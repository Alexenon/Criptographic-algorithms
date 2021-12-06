#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "csk.c" 

// ENCRYPT PLUS SHOULD BE ADDED, AND SCREENSHOTS

int main(int argc, char *argv[]){

    char *prg=argv[0];
    char *opt=argv[1];
    char *msg=argv[2];

    if(argc==1) {
        fprintf(stderr, "%s: no option and massage\n", prg);
        exit(3);
    }
    if(argc==2) {
        if(opt[0] != '-')
            fprintf(stderr, "option is missing\n");
        else
            fprintf(stderr, "message is missing\n");
        exit(2);
    }
    if(argc==3){
        if(strcmp(opt,"-Encr")==0)
            CSK_encrypt(msg);
        else if(strcmp(opt,"-Decr")==0)
            CSK_decrypt(msg);
        else if(strcmp(opt,"-Encrp")==0)
            CSK_encrypt_plus(msg);
        else{
            fprintf(stderr, "%s: illegal option: %s\n", prg, opt);
            exit(1);
        }
    }
    if(argc>3){
        fprintf(stderr, "%s: too many args\n", prg);
        exit(4);
    }
    exit(0);
}