#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list{
    char item[256];
    struct list *next;
}list;


int main(){
  FILE *fp;
  int f;
  char buf[256];

  fp = fopen("java8.txt","r");
//dictionary
  list *dic = malloc(sizeof(list));
  list *first = dic;
  
  while(1) {
    f = fscanf(fp,"%s",buf);
    if (f == EOF) break;
    list *save = malloc(sizeof(list));
    strcpy( save -> item , buf );
    dic -> next = save;
    dic = dic -> next;
    
  }

  fclose(fp);
  dic = first;
  printf("word plz! if you want to quit, type ctrl+c!!\n");
  while(1){
    char word[256];
    int count=0;
    scanf("%s",word);
    dic = first;
  // search string of "word"
    while( dic -> next != NULL){
        if(strcmp(dic -> next -> item,word) == 0) count++;
        dic = dic -> next;
    }

    printf("[%s] , count = %d \n",word,count);
  }
  return 0;
}
