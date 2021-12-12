#ifndef VGN_C
#define VGN_C
#include "vars.c"

extern char letters[];
extern char alphabet[];


void VGN_encrypt(char msg[])
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
        m = (m1+m2) % strlen(letters);
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
}

/* Using upgraded alphabet */
void VGN_encrypt_plus(char msg[])
{
    char enc[25], key[25];
    int i, j, k, m, m1, m2;

    printf("key: ");
    scanf("%s", key);

    k=0;
    for(i=0; i<strlen(msg); i++) {
        for(j=0; j<strlen(alphabet); j++) {
            if(msg[i] == alphabet[j])
                m1 = j;
            if(key[k] == alphabet[j])
                m2 = j;
        }
        m = (m1+m2) % strlen(alphabet);
        enc[i] = alphabet[m];

        if(k == strlen(key)-1)
            k = 0;
        else
            k+=1;
    }

    printf("encrypt: ");
        for(i=0; i<strlen(msg); i++)
            printf("%c", enc[i]);
    printf("\n");
}

void VGN_decrypt(char msg[])
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
        if(m1 - m2 >= 0)
            m = (m1 - m2) % strlen(letters);
        else
            m = (strlen(letters) + m1 - m2) % strlen(letters);
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