/*
Esse códigonão foi feito por mim, mas por Cristiano Carvalho Lacerda <cristiano.lacerda@usp.br>

Como se trata de um algoritmo extremamente complexo e cujo material de aprendizado é muito escasso, eu irei apenas explicar as etapas desse código por comentários ao melhor da minha habilidade.

Esse código não apresenta função de remoção, cuja implementação na árvore B* é de enorme dificuldade. Eu não consegui achar um único código que possuísse essa função pela internet, Github, Gitlab, etc.
------------------------------------------------------------------------
A ideia básica desse código é que cada nó contém N - 1 chaves e N ponteiros para sub-árvores(filhos).

Todas as chaves no nó apontado por Ptr(0) têm valores menores que Key(0). Todas as chaves no nó Ptr(1) e em suas subpáginas têm valores maiores que Key(0) e menores que Key(1). Todas as chaves em Ptr(N) e em suas subpáginas têm valores maiores que Key(N - 1).

A chave e os dados de cada entrada(entry) são combinados para formar o "payload".
O payload e o ponteiro anterior são combinados para formar uma "célula" (Cell).
Cada nó possui um pequeno cabeçalho que contém o Ptr(N) e outras informações, como o número atual de itens armazenados.
Um nó é basicamente um cabeçalho, um array de células com tamanho |ordem - 1|, e possivelmente algum espaço não utilizado no final, de forma que cada nó tenha o mesmo tamanho de uma página de disco.
*/

#include "arvoreBEstrela.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* Estruturas Locais */
typedef struct _bt_header {
    u8 isLeaf;
    u8 height;
    u16 activeCount;
    u32 lastChildren; /* (isso é Ptr(N)) */
} __attribute__((packed)) bt_header;

typedef struct _bt_cell {
    u32 leftChildOffset;
    bt_payload payload;
} __attribute__((packed)) bt_cell;

typedef struct  _bt_node {
    bt_header info;
    bt_cell cells[];
} __attribute__((packed)) bt_node;

typedef struct _bt_page {
    bt_node *node;
    u32 diskOffset;
} __attribute__((packed)) bt_page;
/* BTHANDLE é um ponteiro para uma bt_tree */
typedef struct _bt_tree {
    FILE *btFile;
    char indexName[32];
    int order;
    unsigned int pageSize;
    bt_page *root;
} bt_tree;

/* Funções Locais*/
bt_node *bt_newNode(unsigned int PageSize);
bt_page *bt_newPage(bt_tree *bt);
bt_page *bt_readPage(bt_tree *bt, u32 nodeOffset);
int bt_saveNode(bt_tree *bt, bt_page *p);
void bt_splidChild(bt_tree *bt, bt_page *px, bt_page *py,u16 i);
void bt_splidChild3way(bt_tree *bt, bt_page *px, bt_page *py, bt_page *pz, u16 i);
void bt_insertNonFull(bt_tree *bt, bt_page *node, bt_payload entry);
void bt_rotateRight(bt_tree *bt, bt_page *pp, bt_page *pparent, bt_page *pq, u16 k);
void bt_rotateLeft(bt_tree *bt, bt_page *pp, bt_page *pparent, bt_page *pq, u16 k);

BTHANDLE bt_create(const char *name, unsigned int pageSize) {
    bt_tree *bt = malloc(sizeof(*bt));
    strcpy(bt->indexName, name);
    strcat(bt->indexName, ".idx");
    bt->pageSize = pageSize;
    bt->order = ((pageSize - sizeof(bt_header)) / sizeof(bt_cell)) + 1;
    /* Cria o arquivo */
    bt->btFile = fopen(bt->indexName, "w");
    fclose(bt->btFile);
    /* Salva a raiz */
    bt->root = bt_newPage(bt);
    return bt;
}

bt_node *bt_newNode(unsigned int pageSize) {
    bt_node *n = malloc(pageSize);
    /* Inicializa o nó */
    n->info.activeCount = 0;
    n->info.isLeaf = 1;
    return n;
}

bt_page *bt_newPage(bt_tree *bt) {
    bt_page *p = malloc(sizeof(*p));
    p->node = bt_newNode(bt->pageSize);
    bt->btFile= fopen(bt->indexName, "r+");
    setbuf(bt->btFile, NULL);
    fseek(bt->btFile, 0, SEEK_END);
    p->diskOffset = (u32) ftell(bt->btFile);
    bt_saveNode(bt, p);
    return p;
}

bt_page *bt_readPage(bt_tree *bt, u32 nodeOffset) {
    /* Aloca memória para o nó */
    bt_page *p = malloc(sizeof(*p));
    p->node = bt_newNode(bt->pageSize);
    /* Lê conteúdo apontado pelo nodeOffset dentro do arquivo */
    bt->btFile = fopen(bt->indexName, "r+");
    setbuf(bt->btFile, NULL);
    fseek(bt->btFile, nodeOffset, SEEK_SET);
    fread(p->node, bt->pageSize, 1, bt->btFile);
    fclose(bt->btFile);
    p->diskOffset = nodeOffset;
    return p;
}

int bt_saveNode(bt_tree *bt, bt_page *p) {
    bt->btFile = fopen(bt->indexName, "r+");
    setbuf(bt->btFile, NULL);
    fseek(bt->btFile, p->diskOffset, SEEK_SET);
    fwrite(p->node, bt->pageSize,1, bt->btFile);
    fclose(bt->btFile);
    return 0;
}

bt_payload* bt_get2(bt_tree *bt, bt_node *x, int key) {
    int i = x->info.activeCount;
    bt_page *child;
    while (i >= 0 && key < x->cells[i].payload.key) {
        i--;
    }
    if (key == x->cells[i].payload.key) {
        bt_payload *bt = malloc(sizeof(*bt));
        *bt = x->cells[i].payload;
        return bt;
    }
    if (x->info.isLeaf) {
        return NULL;
    }
    else {
        if (i == x->info.activeCount - 1) {
        /* A chave de entrada é maior que todas as chaves do nó */
        child = bt_readPage(bt, x->info.lastChildren);
        }
        else {
        child = bt_readPage(bt, x->cells[++i].leftChildOffset);
        }
    }
    return bt_get2(bt, child->node, key);
}

bt_payload* bt_get(BTHANDLE h, int key) {
    bt_tree *bt = (bt_tree*) h;
    bt_node *x = bt->root->node;
    return bt_get2(bt, x, key);
}

void bt_splidChild(bt_tree *bt, bt_page *childp, bt_page *parentp, u16 i) {
    bt_node *parent = parentp->node, *child = childp->node;
    int t =  (bt->order - 1) / 2; /* t é o mínimo de chaves */
    int splitPoint = (bt->order - 1 ) - t;
    bt_page *pz = bt_newPage(bt); /* Irmão a direita de y*/
    bt_node *z = pz->node; /* Apelido de pz->node*/
    /* Definindo valores de z */
    z->info = child->info;
    z->info.activeCount = splitPoint - 1;
    /* Copia as chaves de ordem maior para z */
    for (int j = 0; j < z->info.activeCount; ++j) {
        z->cells[j] = child->cells[j + t + 1];
    }
    /* Define valores de y */
    child->info.activeCount = t;
    child->info.lastChildren = child->cells[t].leftChildOffset;
    /* Abre espaço para nova chave em x */
    for (int j = parent->info.activeCount; j > i; --j) {
        parent->cells[j + i] = parent->cells[j];
    }
    /* Copia chave promovida para x */
    parent->cells[i].payload = child->cells[t].payload;
    parent->info.activeCount++;
    /* Transforma z no irmão a direita de y */
    parent->info.lastChildren = pz->diskOffset;
    /* Salva mudanças no disco */
    bt_saveNode(bt, parentp);
    bt_saveNode(bt, childp);
    bt_saveNode(bt, pz);
}

void bt_splidChild3way(bt_tree *bt, bt_page *parentp, bt_page *leftp, bt_page *rightp, u16 i) {
    bt_node *parent = parentp->node, *left = leftp->node, *right = rightp->node;
    bt_page *midp = bt_newPage(bt);
    bt_node *mid = midp->node;
    
    int t = (2 * bt->order - 1) / 3;
    int split = (bt->order - 1 ) - t;
    /* Move a maior chave na esquerda para a posicão i do pai*/
    bt_payload parentPayload = parent->cells[i].payload; /* Salva */
    parent->cells[i].payload = left->cells[t].payload;
    /* Copia as chaves de maior ordem da esquerda para a direita */
    for (int j = 0; j < split - 1; ++j) {
        mid->cells[j] = left->cells[j + t + 1];
    }
    /* Coloca a chave i do pai na posicão de split do meio */
    mid->cells[split - 1].payload = parentPayload;
    mid->cells[split - 1].leftChildOffset = left->info.lastChildren;
    /* Conserta os cabeçalhos dos nós */
    mid->info = left->info;
    mid->info.activeCount = t;
    left->info.activeCount = t;
    left->info.lastChildren = left->cells[t].leftChildOffset;
    right->info.activeCount = (split - 1) + (split - 1)  + 1;
    /* Abre espaço para nova chave no pai */
    for (int j = parent->info.activeCount; j > i; --j) {
        parent->cells[j + i] = parent->cells[j];
    }
    /* Promove menor chave da direita ao parente */
    parent->cells[i + 1].payload = right->cells[t - 1].payload;
    parent->cells[i + 1].leftChildOffset = midp->diskOffset;
    mid->info.lastChildren = right->cells[t - 1].leftChildOffset;
    /* Copia chaves de menor ordem da direita ao meio */
    for (int j = 0; j < split; ++j) {
        mid->cells[split + j] = right->cells[j];
    }
    /* Move as células da direita ao início do vetor */
    for (int j = 0; j < right->info.activeCount; ++j) {
        right->cells[j] = right->cells[j + t];
    }
    /* Salva as mudanças no disco */
    bt_saveNode(bt, parentp);
    bt_saveNode(bt, leftp);
    bt_saveNode(bt, midp);
    bt_saveNode(bt, rightp);
}
/* Os métodos de rotação são muito expansivos já que requerem um acesso ao disco e movem apenas uma chave, uma melhor opção de implementação é redistribuir as chaves igualmente entre os nós */
void bt_rotateRight(bt_tree *bt, bt_page *pp, bt_page *pparent, bt_page *pq, u16 k) {
    /* Apelido útil para referência aos nós */
    bt_node *p = pp->node, *parent = pparent->node, *q = pq->node;
    /* Move todas as gravações em q uma posição para a direita */
    for (int i = q->info.activeCount; i > 0; --i) {
        q->cells[i + 1] = q->cells[i];
    }
    /* Move a entrada k do pai a primeira posição de q */
    q->cells[0].payload = p->cells[k].payload;
    /* Promove a maior chave de p a posição k do pai */
    parent->cells[k].payload = p->cells[p->info.activeCount].payload;
    /* Ajusta ponteiros */
    q->cells[0].leftChildOffset = p->info.lastChildren;
    p->info.lastChildren = p->cells[--p->info.activeCount].leftChildOffset;
    /* Ajusta o tamanho de q */
    q->info.activeCount++;
    /* Salva mudanças no disco */
    bt_saveNode(bt, pp);
    bt_saveNode(bt, pparent);
    bt_saveNode(bt, pq);
}

void bt_rotateLeft(bt_tree *bt, bt_page *pp, bt_page *pparent, bt_page *pq, u16 k) {
    /* Apelido útil para referência aos nós */
    bt_node *p = pp->node, *parent = pparent->node, *q = pq->node;
    /* Copia a entrada k do pai à ultima posição de p */
    p->cells[p->info.activeCount].payload = parent->cells[k].payload;
    /* Copia a menor chave de q a posição k do pai */
    parent->cells[k].payload = q->cells[0].payload;
    /* Conserta ponteiros */
    p->cells[++p->info.activeCount].leftChildOffset = p->info.lastChildren;
    p->info.lastChildren = q->cells[0].leftChildOffset;
    /* Move todas as gravações em q uma posição para a esquerda */
    for (int i = 0; i < q->info.activeCount; ++i) {
        q->cells[i] = q->cells[i + 1];
    }
    /* Ajusta o tamanho de q */
    q->info.activeCount--;
    /* Salva mudanças no disco */
    bt_saveNode(bt, pp);
    bt_saveNode(bt, pparent);
    bt_saveNode(bt, pq);
}

int bt_put(BTHANDLE h, bt_payload entry) {
    bt_tree *bt = (bt_tree*) h;
    bt_page *root = bt->root;
    /* Se a raiz estiver vazia */
    if ( root->node->info.activeCount == (((bt_tree *)bt)->order - 1) ) {
        /* Cria e define nova raiz */
        bt_page *newRoot = bt_newPage(bt);
        newRoot->node->cells[0].leftChildOffset = root->diskOffset;
        newRoot->node->info.isLeaf = 0;
        newRoot->node->info.activeCount = 0;
        /* Conserta o ponteiro da árvore */
        bt->root = newRoot;
        root->node->info.height++;
        root->node->info.isLeaf = 1;
        /* Splita antiga raiz adiciona nova entrada */
        bt_splidChild(bt,root, newRoot, 0);
        bt_insertNonFull(bt, newRoot, entry);
    }
    else {
        bt_insertNonFull(bt, root, entry);
    }
    return 0;
}

void bt_insertNonFull(bt_tree *bt, bt_page *px, bt_payload entry) {
    bt_node *x = px->node;
    int i = x->info.activeCount - 1;
    /* Se x é uma folha insira a entrada na posição correta */
    if (x->info.isLeaf) {
        while (i >= 0 && entry.key < x->cells[i].payload.key) {
            x->cells[i + 1].payload = x->cells[i].payload;
            i--;
        }
        x->cells[++i].payload = entry;
        x->info.activeCount++;
        bt_saveNode(bt, px);
        return;
    }
    else {
        /* Se não é folha, ache o descendente correto para inserir a entrada */
        int flag = 0; /* -1 se o nó esta no início(esquerda), +1 se o nó está no final(direita) */
        u32 childOffset;
        bt_page *child;
        while (i >= 0 && entry.key < x->cells[i].payload.key) {
            i--;
        }
        if (i == x->info.activeCount - 1) {
            /* Chave de entrada é maior que todas as chaves do nó */
            childOffset = x->info.lastChildren;
            child = bt_readPage(bt, childOffset);
            flag = 1;
            
        } else {
            childOffset = x->cells[++i].leftChildOffset;
            child = bt_readPage(bt, childOffset);
            if (i == 0) flag = -1; /* Chave de entrada é menor que todas as chaves do nó */
        }
        if (child->node->info.activeCount == bt->order - 1) {
            /* Tenta encher(overflow) e se necessário dar split */
            bt_page *sibling = NULL; /* Previne avisos de compilação */
            if (flag == -1) {
                sibling = bt_readPage(bt, x->info.lastChildren);
                if (sibling->node->info.activeCount < bt->order - 1) {
                    bt_rotateRight(bt, child, px, sibling, i);
                    bt_insertNonFull(bt, child, entry);
                    return;
                }
                else bt_splidChild3way(bt, px, child, sibling, i);
            }
            else if (flag > -1) {
                sibling = bt_readPage(bt, x->cells[i].leftChildOffset);
                if (sibling->node->info.activeCount < bt->order - 1 ) {
                    bt_rotateLeft(bt, sibling, px, child, i);
                    bt_insertNonFull(bt, child, entry);
                    return;
                }
                else bt_splidChild3way(bt, px, sibling, child, i);
            }
            bt_insertNonFull(bt, px, entry);
        }
        /* Apenas insere no filho */
        else {
            bt_insertNonFull(bt, child, entry);
        }
    }
}