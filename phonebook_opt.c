#include <stdlib.h>

#include "phonebook_opt.h"

/* o version */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: find name one by one */
    while(pHead != NULL){
        if(strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead -> pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
//    return NULL;
}
