#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"
#include "smaz.h"

entry *findName(char lastname[], entry *pHead)
{
    entry *e;
    char dcompressed[32],compressedlastName[32];

    memset(compressedlastName,'\0',sizeof(compressedlastName));
    smaz_compress(lastname,strlen(lastname),compressedlastName,sizeof(compressedlastName));

    while (pHead != NULL) {
        if (strcasecmp(pHead->lastName,compressedlastName) == 0) {
            memset(dcompressed,'\0',sizeof(dcompressed));
            smaz_decompress(pHead->lastName,strlen(pHead->lastName),dcompressed,sizeof(dcompressed));
            e = (entry *) malloc(sizeof(entry));
            memset(e-> lastName,'\0',sizeof(e->lastName));
            strcpy(e->lastName,dcompressed);
            return e;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    char compressedlastName[32];

    memset(compressedlastName,'\0',sizeof(compressedlastName));
    smaz_compress(lastName,strlen(lastName),compressedlastName,sizeof(compressedlastName));

    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, compressedlastName);
    e->pNext = NULL;

    return e;
}
