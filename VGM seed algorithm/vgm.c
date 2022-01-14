#ifndef VGM_C
#define VGM_C
#include <stdio.h>
#include "vars.c"

extern int seed;

void VGM_encrypt_seed(char msg[])
{
    char enc[25], key[25];
    int i, j, k, m, m1, m2;

    printf("key: ");
    scanf("%s", key);
    seed = time(NULL);
    k=0;
    for(i=0; i<strlen(msg); i++) {
        for(j=0; j<strlen(letters); j++) {
            if(msg[i] == letters[j])
                m1 = j;
            if(key[k] == letters[j])
                m2 = j;
        }
        m = (m1+m2+seed) % strlen(letters);
        enc[i] = letters[m];

        if(k == strlen(key)-1)
            k = 0;
        else
            k+=1;
    }

    printf("encrypt: ");
        for(i=0; i<strlen(msg); i++)
            printf("%c", enc[i]);
    printf("\n");
    printf("seed: %d\n", seed);
}


void VGM_decrypt_seed(char msg[])
{
    char enc[25], key[25];
    int i, j, k, m, m1, m2;

    printf("key: ");
    scanf("%s", key);

    k=0;
    for(i=0; i<strlen(msg); i++) {
        for(j=0; j<strlen(letters); j++) {
            if(msg[i] == letters[j])
                m1 = j;
            if(key[k] == letters[j])
                m2 = j;
        }
        
        /* Here is the magic */
        m = (strlen(letters) + m1 - m2 - seed) % strlen(letters) + 4;
        if(m>=26) 
            m=0;
        enc[i] = letters[m];

        if(k == strlen(key)-1)
            k = 0;
        else
            k+=1;
    }

    printf("decrypt: ");
        for(i=0; i<strlen(msg); i++)
            printf("%c", enc[i]);
    printf("\n");
}

#endif