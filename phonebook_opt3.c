#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt3.h"
#define HASH_TABLE_SIZE 1031

entry *findName(char lastname[], entry *ht)
{
    entry *pHead = (ht+hashFunc(lastname))->pNext;

    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *ht)
{
    entry *e;
    e = (entry *) malloc(sizeof(entry));
    strcpy(e->lastName, lastName);

    int hashindex = hashFunc(lastName);
    e->pNext = (ht+hashindex)->pNext;
    (ht+hashindex)->pNext = e;

    return ht;
}

void init_hashtable(entry **pHead,entry **e)
{
    int i = 0;

    *e = (entry *) malloc(HASH_TABLE_SIZE*sizeof(entry));
    while(i < HASH_TABLE_SIZE) {
        (*e+i)->pNext = NULL;
        i++;
    }
    *pHead = *e;
}

int hashFunc(char lastname[])
{
    unsigned int hashVal = 5381;
    while(*lastname) hashVal = (hashVal<<5) + hashVal + *lastname++;

    return hashVal%HASH_TABLE_SIZE;
}
