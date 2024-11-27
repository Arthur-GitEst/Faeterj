#ifndef __FileStructs__btree__
#define __FileStructs__btree__

#include <stdio.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

/* Tipos exportados */
/* O tamanho dessa struct afeta a ordem da árvore */
typedef struct _bt_payload {
    u32 key;
    u32 value;
} __attribute__((packed)) bt_payload;

/* O tipo BTHANDLE representa uma referência a árvore B sem expor seus detalhes de implementação. É retornado das operações bt_create e bt_open e são passadas para chamadas da api. */
typedef void* BTHANDLE;


/* API's Globais */

BTHANDLE bt_create(const char *name, unsigned int pageSize);
BTHANDLE bt_open(const char *name);
int bt_put(BTHANDLE, bt_payload entry);
bt_payload* bt_get(BTHANDLE h, int key);
bt_payload bt_nextRecord(BTHANDLE);



#endif