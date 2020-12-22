#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void today(int *yearp,int *monthp,int *dayp);   //오늘 날짜 구하는 함수  
void input(char *c_birth);  //사용자 생년월일 입력함수 
void change(char *c_birth,int *year,int *month,int *day);  //사용자의 문자형 생년월일을 정수값으로 변환시키는 함수 
void date(int year,int month,int day,int uyear,int umonth,int uday); //살아온 날수 계산 함수  

void main(){
	int year,month,day,uyear,umonth,uday;
	char c_birth[11];
	today(&year,&month,&day);    //오늘 날짜 구하는 함수 호출  
	input(c_birth);//사용자 생년월일 입력함수호출  
	change(c_birth,&uyear,&umonth,&uday);//사용자의 문자형 생년월일을 정수값으로 변환시키는 함수호출  
	date(year,month,day,uyear,umonth,uday);//살아온 날수 계산 함수호출  
}

void today(int *yearp,int *monthp,int *dayp){
	time_t time_ms;
	struct tm *t;     // 구조체 변수 선언
	time_ms=time(NULL);  // 현재 시각 얻기   
	t=localtime(&time_ms);  //시간을 분리하여 구조체에 넣기
	*yearp=t->tm_year%100+2000;
	*monthp=t->tm_mon+1;
	*dayp=t->tm_mday;
}

void input(char *c_birth){
	printf("생년월일을 순서대로 입력하세요: 0000/00/00\n");
	printf("                              : "); 
	
	scanf("%s",c_birth);
	printf("\n============================================\n"); 
	if(strcmp(c_birth,"0")==0){     //0을 입력하면 프로그램 종료  
		printf("프로그램이 종료됩니다");
		exit(1);
	}
}
void change(char *c_birth,int *year,int *month,int *day){
    char sp[2] = "/";
	*year = atoi(strtok(c_birth, sp)); //strtok 활용하여 sp 단위로 끊고 atoi로 문자열을 정수형으로 변환 
    *month = atoi(strtok(NULL, sp));//strtok 활용하여 sp 단위로 끊고 atoi로 문자열을 정수형으로 변환
    *day = atoi(strtok(NULL, sp));//strtok 활용하여 sp 단위로 끊고 atoi로 문자열을 정수형으로 변환
}
void date(int year,int month,int day,int uyear,int umonth,int uday){
	int monthdate[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int date=0,i,a,m;
	i=uyear+1;
	for(i;i<year;i++){       //살아온 년수 더하기  
		if(((i%4==0)&&(i%100!=0))||i%400==0){  //윤년 계산기 
			date+=366;
		}
		else{
			date+=365;
		}
		
	}
	if(((uyear%4==0)&&(uyear%100!=0))||uyear%400==0){//윤년 계산기
		monthdate[1]=29;     //윤년일경우  
	}
	else{
		monthdate[1]=28;    //평년일경우 
	}
	m=umonth+1;
	if(uyear<year){        
		for(m;m<=12;m++){      //n월부터 12월까지 
			date+=monthdate[m-1];        //배열에 저장해논 달마다 날짜수를 date에 더하기 
		}
		date+=monthdate[umonth-1]-uday+1;
	}
	
	if(((year%4==0)&&(year%100!=0))||year%400==0){//윤년 계산기
		monthdate[1]=29;//윤년일경우
	}
	else{
		monthdate[1]=28;//평년일경우 
	}
	for(a=1;a<month;a++){ //1월부터 n월까지 
		date+=monthdate[a-1];
	}
	date+=day;
	
	printf("살아온 날짜는 %d일 입니다.\n",date);
}


