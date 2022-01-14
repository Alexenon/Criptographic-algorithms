#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l', 'm','n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

/* New alphabet with 64 chars */
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
		};


/* Generation of key */
char *CSK_keygen(char key[])
{
    int i, j, k, n;
    
    strcat(key, alphabet);
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

/* Basic encryption */
void CSR_encrypt(char msg[])
{
  char enc[63], keystream[63];
  int key, i, j, k;

  // Generation of key
  printf("key: ");
  scanf("%s", &keystream);  
  CSK_keygen(keystream);
  printf("generated key: ");
    for(i=0; i<strlen(keystream); i++)
        printf("%c", keystream[i]);
  printf("\n");

  // Asking for render 
  printf("index: ");
  scanf("%i", &key);

  for(i=0; i<strlen(msg); i++)
    for(j=0; j<strlen(keystream); j++)
      if(msg[i]==keystream[j]) {

        int temp = (j+key)%62;

        if(temp < strlen(keystream))
          enc[i] = keystream[temp];
        else {
          k = temp - strlen(keystream);
          enc[i] = keystream[k];
        }
      }

  printf("enc: ");
  for(i=0; i<strlen(msg); i++)
    printf("%c", enc[i]);
  printf("\n");
}


/* Basic decryption */
void CSR_dencrypt(char msg[])
{ 
  char enc[63], keystream[63];
  int key, i, j, k;

  // Generation of key
  printf("key: ");
  scanf("%s", &keystream);  
  CSK_keygen(keystream);

  printf("generated key: ");
    for(i=0; i<strlen(keystream); i++)
        printf("%c", keystream[i]);
  printf("\n");

  // Asking for index
  printf("index: ");
  scanf("%i", &key);

  for(i=0; i<strlen(msg); i++)
    for(j=0; j<strlen(keystream); j++)
      if(msg[i] == keystream[j]) {

        int temp = (j-key)%62;

        if(temp < strlen(keystream))
          enc[i] = keystream[temp];
        else {
          k = temp - strlen(keystream);
          enc[i] = keystream[k];
        }
      }

  printf("enc: ");
  for(i=0; i<strlen(msg); i++)
    printf("%c", enc[i]);
  printf("\n");
}


int main(int argc, char *argv[])
{
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
  if(argc==3) {
    if(strcmp(opt,"-encrypt")==0)
      CSR_encrypt(msg);
    else if(strcmp(opt,"-decrypt")==0)
      CSR_dencrypt(msg);
    else {
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