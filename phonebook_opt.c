#include <stdlib.h>

#include "phonebook_opt.h"

/* hash version */
entry *hash_table[HASH_SIZE];
entry *hash_array[HASH_SIZE];

static inline unit32_t hashFind(char lastname[])
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
    int h_value = hashFind(lastname);
    pHead = hash_table[h_value];

    while(pHead != NULL){
        if(strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead -> pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int bucket = hashFind(lastName);
    entry *new_one = (entry *)malloc(sizeof(entry));
    
    if(hash_table[bucket]){
        hash_array[bucket] -> pNext = new_one;
        new_one -> pNext = NULL;
        strcpy(new_one -> lastName, lastName);
        hash_array[bucket] = new_one;
    }else{
        new_one -> pNext = NULL;
        strcpy(new_one -> lastName, lastName);
        hash_array[bucket] = new_one;
        hash_table[bucket] = new_one;
    }
    return new_one;

//    e->pNext = (entry *) malloc(sizeof(entry));
//    e = e->pNext;
//    strcpy(e->lastName, lastName);
//    e->pNext = NULL;

//    return e;
//    return NULL;
}
