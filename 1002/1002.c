#include <stdio.h>
#include <stdlib.h>

typedef struct _LongInt{
  int num;
  struct _LongInt* next;
}LongInt;

LongInt* getLongInt(){
  LongInt* header = (LongInt*)malloc(sizeof(LongInt));
  header->next = NULL;
  LongInt* nextNode = header;
  LongInt* tmp = NULL;
  char d;
  d = getchar();
  while(d!='\n'){
    tmp = (LongInt*)malloc(sizeof(LongInt));
    tmp->num = d-48;
    //scanf("%1d",&tmp->num);
    nextNode->next = tmp;
    nextNode = tmp;
    nextNode->next = NULL;
    d = getchar();
  }
  return header;
}

int sumLongInt(LongInt* header){
  int sum = 0;
  LongInt* nextNode = header;
  while(nextNode->next){
    nextNode = nextNode->next;
    sum = sum + nextNode->num;
  }
  return sum;
}

void printSum(int num){
  int size;
  int i;
  int tmp;
  int *array;
  size = 0;
  tmp = num;
  while(tmp!=0){
    tmp = tmp/10;
    size++;
  }

  array = malloc(sizeof(int)*size);
  for(i = 0; i < size; i++){
    array[i] = num%10;
    num = num/10;
//    printf("--array[%d]:%d--\n",i,array[i]);
  }

  for(i = size-1; i >= 0; i--){
    switch (array[i]) {
      case 0:printf("ling");break;
      case 1:printf("yi");break;
      case 2:printf("er");break;
      case 3:printf("san");break;
      case 4:printf("si");break;
      case 5:printf("wu");break;
      case 6:printf("liu");break;
      case 7:printf("qi");break;
      case 8:printf("ba");break;
      case 9:printf("jiu");break;
      default: printf("error");break;
    }
    if(i>0){
      printf(" ");
    }
  }
}

void freeAll(LongInt* header){
  LongInt* nextNode = header;
  LongInt* tmp ;
  while(nextNode->next){
    tmp = nextNode;
    nextNode = nextNode->next;
    free(tmp);
  }
  free(nextNode);
}

void main(){
   LongInt* header = NULL;
   int sum = 0;
   header = getLongInt();
   sum = sumLongInt(header);
   printSum(sum);
}
