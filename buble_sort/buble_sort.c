#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubleSort(int arr[],int fnum);
//main 함수 
void main (){
int i,cnt=10;   
srand(time(NULL));    
int numarr[cnt];//10개의 원소를 가지는 배열 선언
for(i=0;i<cnt;i++){
numarr[i]=rand()%101;   //0부터 100사이의 임의의 정수를 만들어 배열에 삽입 
}
printf("======배열(정렬전) 출력======\\n\\n");
for(i=0;i<10;i++){
printf(" %d ",numarr[i]);       //배열의 초기값 출력 
}
bubleSort(numarr,cnt); // 버블 정렬 함수 호출 
printf("\\n\\n======배열(정렬후) 출력======\\n\\n");
for(i=0;i<10;i++){
printf(" %d ",numarr[i]);   //정렬된 결과 출력 
}
}
//test
//버블 정렬 함수  
void bubleSort(int arr[],int fnum){  // 입력으로 정수형 배열 정수(크기) 
int i,j,temp,maxnum;
for(i=0;i<fnum;i++){
for(j=0;j<fnum-1;j++){
if(arr[j]>arr[j+1]){      //버블 정렬 
temp = arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}