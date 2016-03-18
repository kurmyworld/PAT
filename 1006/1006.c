#include <stdio.h>
void putB(int times){
  int _i = 0;
  for(;_i<times;_i++){
    printf("B");
  }
}
void putS(int times){
  int _i = 0;
  for(;_i<times;_i++){
    printf("S");
  }
}
void putN(int times){
  int _i = 0;
  for(;_i<times;_i++){
    printf("%d",_i+1);
  }
}
int getInt(){
  int in = 0;
  scanf("%d",&in);
  return in;
}
int getB(int num){
  return num/100%10;
}
int getS(int num){
  return num/10%10;
}
int getN(int num){
  return num%10;
}
void main(){
  int a,s,b,n;
  a = getInt();
  s = getS(a);
  b = getB(a);
  a = getN(a);
  n = getN(a);
  putB(b);
  putS(s);
  putN(n);
}
