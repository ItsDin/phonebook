#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "phonebook_opt.h"

/* hash version */
entry *hash_table[HASH_SIZE];

static inline int hashTablePhone(char lastname[])
{
    int number;
    number = 0;
    while(*lastname)
        number += *lastname++;
    return (number%HASH_SIZE);
}

entry *findName(char lastname[], entry *pHead)
{
    /* TODO: find name with hash */
    int h_value = hashTablePhone(lastname);
    pHead = hash_table[h_value];

    while(pHead != NULL){
        if(strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int bucket = hashTablePhone(lastName);

    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    if(hash_table[bucket]){
        hash_table[bucket]->pNext = e;
        e -> pNext = NULL;
        strcpy(e -> lastName, lastName);
        hash_table[bucket] = e;
    }else{
        e->pNext = NULL;
        strcpy(e->lastName, lastName);
        hash_table[bucket] = e;
    }
    free(e->pNext);
    return e;
}
