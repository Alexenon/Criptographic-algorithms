#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int tms = 0;

void VGN_encrypt_seed(char msg[])
{
    char enc[25], key[25];
    int i, j, k, m, m1, m2;
    int seed;

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
    tms = seed;
}

void VGN_decrypt_seed()
{
    char msg[25];
    char enc[25], key[25];
    int i, j, k, m, m1, m2;

    printf("message: ");
    scanf("%s", msg);

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
        m = (strlen(letters) + m1 - m2 - tms) % strlen(letters);
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

int main() {    

    // key = student
    VGN_encrypt_seed("nupotveniazi");
    VGN_decrypt_seed();
    
    return 0;
}