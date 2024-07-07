#include <stdio.h>

void merge (int vet[], int inicio, int meio, int fim);
void mergeSort (int vet[], int inicio, int fim);
void exibirVetor (int vet[], int tamanho);

int main () {
    int vetor[] = {5, 2, 4, 1, 3, 6, 7, 0, 12, 23, 52, 35, 65, 34, 27, 87, 57};

    int tamanhoVetor = sizeof(vetor) / sizeof(int);

    printf("\nVetor Original: ");
    exibirVetor(vetor, tamanhoVetor);

    mergeSort(vetor, 0, tamanhoVetor - 1);

    printf("\nVetor Ordenado: ");
    exibirVetor(vetor, tamanhoVetor);

    return 0;
}

void merge (int vet[], int inicio, int meio, int fim) {
    int i, j, k;

    //declarando o tamanho dos subvetores
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;
    
    //declarando os subvetores
    int vetEsquerda[tamanhoEsquerda], vetDireita[tamanhoDireita];

    //copiando elementos para o subvetor esquerdo
    for (i = 0; i < tamanhoEsquerda; i++) {
        vetEsquerda[i] = vet[inicio + i];
    }

    //copiando elementos para o subvetor direito
    for (j = 0; j < tamanhoDireita; j++) {
        vetDireita[j] = vet[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    //comparando os valores dos subvetores e ordenando no vetor original
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (vetEsquerda[i] <= vetDireita[j]) {
            vet[k] = vetEsquerda[i];
            i++;
        } else {
            vet[k] = vetDireita[j];
            j++;
        }
        k++;
    }

    //Copiando os elementos restantes do vetor esquerdo
    while (i < tamanhoEsquerda) {
        vet[k] = vetEsquerda[i];
        i++;
        k++;
    }

    //Copiando os elementos restantes do vetor direito
    while (j < tamanhoDireita) {
        vet[k] = vetDireita[j];
        j++;
        k++;
    }
}

void mergeSort (int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        //Ordenando as duas metades
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);

        merge(vet, inicio, meio, fim);
    }
}

void exibirVetor (int vet[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}    