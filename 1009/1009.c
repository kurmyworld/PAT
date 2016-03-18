#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
typedef struct _CharNode
{
  struct _CharNode *before;
  char data[MAX];
  struct _CharNode *next;
}CharNode;

CharNode* getLine(CharNode* end){
  CharNode* header = NULL;
  CharNode* nextNode = NULL;
  CharNode* tmp = NULL;
  header = (CharNode*)malloc(sizeof(CharNode));
  header->next = NULL;
  header->before = NULL;
  nextNode = header;
  do{
    tmp = (CharNode*)malloc(sizeof(CharNode));
    tmp->before = nextNode;
    nextNode->next = tmp;
    nextNode = tmp;
    scanf("%s",tmp->data);
    tmp->next = NULL;
  }while(getchar() != '\n');
  tmp->next = end;
  end->before = tmp;
  return header;
}

void println(CharNode* end){
  CharNode* nextNode = end;
  while(nextNode->before){
    printf("%s",nextNode->before->data);
    if(nextNode->before->before){
      printf(" ");
    }
    nextNode = nextNode->before;
  }
}
void freeall(CharNode* header){
  CharNode* n = header;
  CharNode* t = n;
  while(n->next){
    n=n->next;
    free(t);
    printf("\nfree a node\n");
    t = n;
  }
}

void main(){
  CharNode* end = (CharNode*)malloc(sizeof(CharNode));
  CharNode* header = getLine(end);
  println(end);
  freeall(header);
}
