#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int seed;

char* randomization(){
    char text[30];
    //return sprintf(text, "%d", seed); 
    return "12345678";
}

char* strtobin(char* s){
    if(s == NULL) return 0; 
    char *binary = malloc(sizeof(s)*8);
    strcpy(binary,"");
    char *ptr = s;
    int i;

    for(; *ptr != 0; ++ptr)
    {
        /* perform bitwise AND for every bit of the character */
        for(i = 7; i >= 0; --i){
            (*ptr & 1 << i) ? strcat(binary,"1") : strcat(binary,"0");
        }
    }
    scanf("binary %s", binary);
    return binary;
}

char* binopers(){
    static char bin[9];
    int x, n;
    for(x = 0; x < 8; x++){
        bin[x] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }
    //bin[x] = '';
    return (bin);
}

char* bintochar(char* enc, char* encbin){
    return encbin;
}


void FLD_encrypt(char msg[])
{
    seed = time(NULL);
    char *msgbin, *keybin, *encbin, enc[25];
    int i, j, k;
    msgbin = strtobin(msg);
    keybin = strtobin(randomization());
    encbin = binopers(msgbin,keybin);
    bintochar(enc,encbin);
    printf("enc: ");
    for(i=0; i<strlen(msg); i++)
        printf("%c", enc[i]);
    printf("\n");
}




int main() {

    FLD_encrypt("mesaj");

    
    return 0;
}