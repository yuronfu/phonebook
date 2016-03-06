#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 65537
#define DICT_FILE "words.txt"

int hashFunc(char lastname[])
{
    unsigned int hashVal = 5381;
    while(*lastname) hashVal = (hashVal<<5) + hashVal + *lastname++;

    return hashVal%HASH_TABLE_SIZE;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    int i = 0,ave = 0,old = 0,new,diff;
    char line[MAX_LAST_NAME_SIZE];

    /* check file opening */
    fp = fopen(DICT_FILE, "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }

    while (fgets(line, sizeof(line), fp)) {
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';
        i = 0;
        if(!old) old = new = hashFunc(line);
        else {
            new = hashFunc(line);
            (old > new) ? (diff = old - new) : (diff = new - old);
            if(!ave) ave = diff;
            else ave = (ave+diff)/2;
        }
    }

    /* close file as soon as possible */
    fclose(fp);
    printf("ave. of diff. of hash value = %d\n",ave);

    return 0;
}
