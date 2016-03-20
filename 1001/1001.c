#include <stdio.h>

int callatz(int n){
  int count = 0;
  while(n!=1){
    if(n%2==1){
      n = (3*n+1)/2;
    }else{
      n = n/2;
    }
    count++;
  }
  return count;
}
int main(int argc, char const *argv[]) {
   int count = 0;
   int num;
   scanf("%d",&num);
   count = callatz(num);
   printf("%d",count);
   return 0;
 }
