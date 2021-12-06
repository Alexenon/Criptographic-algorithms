#ifndef CSK_C
#define CSK_C
#include "vars.c"

char *CSK_keygen(char key[])
{
    int i, j, k, n;
    
    strcat(key, letters);
    n = strlen(key);
    for(i=0; i<n; i++)
        for(j=i+1; j<n;)
            if(key[i] == key[j]){
                for(k=j; k<n; k++)
                    key[k] = key[k+1];
                n--;
            }
            else
                j++;
                
    return key;
}

void CSK_encrypt(char msg[])
{
    char key[26], enc[25];
    int i, j, k;
    
    printf("key: ");
    scanf("%s", &key);
    
    CSK_keygen(key);
    for(i=0; i<strlen(msg); i++)
        for(j=0; j<strlen(letters); j++)
            if(msg[i] == letters[j]) {
                k = j % strlen(key);   
                enc[i] = key[k];       
                break;
            }
    
    printf("encrypt: ");
    for(int i = 0; i < strlen(msg); i++) 
        printf("%c", enc[i]);
    printf("\n");
    
}

void CSK_encrypt_plus(char msg[])
{
    char key[26], enc[25];
    int i, j, k;
    
    printf("key: ");
    scanf("%s", &key);
    
    CSK_keygen(key);
    for(i=0; i<strlen(msg); i++)
        for(j=0; j<strlen(alphabet2); j++)
            if(msg[i] == alphabet2[j]) {
                k = j % strlen(key);   
                enc[i] = key[k];       
                break;
            }
    
    printf("encrypt: ");
    for(int i = 0; i < strlen(msg); i++) 
        printf("%c", enc[i]);
    printf("\n");
    
}


void CSK_decrypt(char msg[])
{
    char key[26], enc[25];
    int i, j, k;
    
    printf("key: ");
    scanf("%s", &key);
    
    CSK_keygen(key);
    for(i=0; i<strlen(msg); i++)
        for(j=0; j<strlen(letters); j++)
            if(msg[i] == key[j]) {
                k = j % strlen(key);
                enc[i] = letters[k];
                break;
            }
    printf("decrypt: ");
    for(int i = 0; i < strlen(msg); i++) 
        printf("%c", enc[i]);
    printf("\n");
}

#endif