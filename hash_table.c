#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hash_t{
    char item[256];
    int count;
    struct hash_t *next;

}hash_t;

int ctoi(char *arr){
    int c = 0;
    int asc=0;
    while(1){
     if(*arr=='\0') return c%256;
     asc = *arr;
     if(asc < 0) asc = -1 * asc;
     c += asc;
     arr++;     
    }
}

void dig_search(char *buf,hash_t *node){
  while(node -> next != NULL ){
    if(strcmp(buf, node-> item)==0){
       node -> count++;
       return  ;
    }else if(strcmp(buf, node -> next -> item)==0){
       node -> next -> count++;
       return ;
    }
    node = node -> next;
  }
  hash_t *new = malloc(sizeof(hash_t));
  strcpy(new -> item , buf);
  new -> count = 1;
  node -> next = new; 
}

void make(int ind , char *buf, hash_t **table){
    hash_t *save = table[ind]; 
    if(table[ind] != NULL){
	if(strcmp(buf,table[ind]->item) ==0){
	    table[ind] -> count++;
	}else if(strcmp(buf,table[ind] -> item) != 0){
            dig_search(buf, table[ind]);
            table[ind] = save;
	}
    }else if(table[ind] == NULL ){
      hash_t *new = malloc(sizeof(hash_t));
      strcpy(new -> item , buf);
      new -> count = 1;
      table[ind] = new;
    }
}

void word_search(char *word,hash_t *table){
   hash_t *save = table;
   while(table != NULL){
     if(strcmp(table -> item ,word) == 0){
      printf("[%s] , count = %d \n",word,table -> count);
      table = save;
      return ;
     }
     table = table -> next;
   }
   table = save;
   printf("%s IS NOT FOUND!! \n",word);
}

int main(){
  FILE *fp;
  int f=0,index=0;
  char buf[256];
  hash_t *table[256];

  for(f;f<256;f++){
    table[f] =NULL;
  }

  fp = fopen("java8.txt","r");

  while(1) {
    f = fscanf(fp,"%s",buf);
    if (f == EOF) break;
    index = ctoi(buf);
    make(index,buf,table);    
  }

  fclose(fp);
  char word[256];
  int count=0;
  printf("\n");
  printf("search word plz! if you want to quit, type ctrl+c ! \n");
  while(1){
    scanf("%s",word);
    index = ctoi(word);
    //printf("index = %d \n",index);
    word_search(word,table[index]);  
  }
  return 0;
}
