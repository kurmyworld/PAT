#include <stdio.h>
#include <stdlib.h>
int *mkArray(int size){
  int *arr = malloc(sizeof(int)*size);
  return arr;
}
void initArray(int *array,int size){
  int i;
  for(i = 0; i < size; i++){
    array[i] = i+1;
  }
}
void move(int *array,int arraySize,int moveTimes){
  int tmp,i,k;
  k = 0;
  while(k++ < moveTimes){
    tmp = array[arraySize-1];
    for(i = arraySize; i > 0; i--){
      array[i]=array[i-1];
    }
    array[0] = tmp;
  }
}
void printArray(int *array,int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d",array[i]);
  }
}
int getInt(){
  int in;
  scanf("%d",&in);
  return in;
}
void main(){
  int size,times;
  int *array;
  size = getInt();
  times = getInt();
  array = mkArray(size);
  initArray(array,size);
  printArray(array,size);
  printf("\n");
  move(array,size,times);
  printArray(array,size);
}
