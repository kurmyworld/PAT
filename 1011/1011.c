#include <stdio.h>
#include <stdlib.h>
typedef struct _ABC{
  int A;
  int B;
  int C;
}ABC;
//被调用的函数必须出现在前面
void printResult(int _bool, int _case){
  if(_bool){
    printf("Case #%d: true",_case);
  }else{
    printf("Case #%d: false",_case);
  }
}
//获取一个输入，有点java味道
int getInt(){
  int i;
  scanf("%d",&i);
  return i;
}
//得到一数组，动态分配内存
ABC* getArray(int size){
  ABC* abc = NULL;
  abc = (ABC*)malloc(sizeof(ABC)*size);
  return abc;
}
//计算这个数组的数据
void calc(ABC* abcArray,int size){
  int i;
  for(i = 0;i<size;i++){
    //结构体里边的基本数据类型用点操作符来访问
    scanf("%d %d %d",&abcArray[i].A,&abcArray[i].B,&abcArray[i].C);
  }
  for(i = 0; i < size; i++){
    //如果A+B>C
    if(abcArray[i].A + abcArray[i].B > abcArray[i].C){
      //打印true的结果，并将此case传入
      printResult(1,i+1);
    }else{
      //否则打印false的case输出
      printResult(0,i+i);
    }
    //如果下面还有数据，则输出一个换行
    if(i+1<size){
      printf("\n");
    }
  }
}

void main(){
  int size;
  ABC* abcArray = NULL;
  size = getInt();
  abcArray = getArray(size);
  calc(abcArray,size);
}
