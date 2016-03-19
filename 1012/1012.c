#include <stdio.h>
#include <stdlib.h>
/*
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

总感觉A4有点问题。
*/
typedef struct _intLink{
  int num;
  struct _intLink* next;
}intLink;

typedef struct _A{
  int A1 ;
  int A2 ;
  int A3 ;
  float A4 ;
  int A5 ;
}A;

intLink* getArray(){
  intLink* header = NULL;
  header = (intLink*)malloc(sizeof(intLink));
  intLink* nextNode = header;
  intLink* newNode = NULL;
  do{
    newNode = (intLink*)malloc(sizeof(intLink));
    scanf("%d",&newNode->num);
    nextNode->next = newNode;
    newNode->next = NULL;
    nextNode = newNode;
  }while(getchar()!='\n');
  return header;
}

void classification(A* a,intLink* inputArray){
  int _i = -1;
  int count = 1;
  intLink* nextNode = inputArray;
  while(nextNode->next){
    nextNode = nextNode->next;
    if(nextNode->num%5==0 && nextNode->num%2==0){
      a->A1 = a->A1+nextNode->num;
    }
    if(nextNode->num%5 == 1){
      _i = _i * -1;
      a->A2 = a->A2 + nextNode->num*_i;
    }
    if(nextNode->num%5==2){
      a->A3++;
    }
    if(nextNode->num%5==3){
      count++;
      a->A4 = a->A4+nextNode->num;
    }
    if(nextNode->num%5==4 && nextNode->num>a->A5){
      a->A5 = nextNode->num;
    }
  }
  printf("--count:%d---\n",count);
  a->A4 = a->A4/count;
}

void printA(A* a){
  if(a->A1 == 0){printf("N ");}else{printf("%d ",a->A1);}
  if(a->A2 == 0){printf("N ");}else{printf("%d ",a->A2);}
  if(a->A3 == 0){printf("N ");}else{printf("%d ",a->A3);}
  if(a->A4 == 0){printf("N ");}else{printf("%.1f ",a->A4);}
  if(a->A5 == 0){ printf("N");}else{printf("%d",a->A5);}
}
void main(){
  intLink* header;
  A* a = (A*)malloc(sizeof(A));
  header = getArray();
  classification(a,header);
  printA(a);
}
