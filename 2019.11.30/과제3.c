#include <stdio.h>
#include <conio.h>
void login();    //로그인 기능을 가지고 있는 함수 
void score(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank);  // 답을 채점하여 점수화 시켜주는 함수
void ranking(char(*x)[10],char(*y)[15],char(*z)[10],int *s);  //오름차순으로 정렬하는 함수   
void tie(int *s,int *rank);  //동점자 처리함수  
void print(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank); //출력함수 + 학과별 평균 함수 

void main(){
	char x[20][10],y[20][15],z[20][10];
	int s[20],rank[20];
	login();    //로그인 함수 호 출  
	score(x,y,z,s,rank); //답채점함수 호 출  
	ranking(x,y,z,s); //오름차순으로 정리하는 함수 호출 
	tie(s,rank);  //동점자 처리하는 함수 호출  
	print(x,y,z,s,rank); //출력함수+학과별 평균 구하는 함수 호출  
}
///////////////////////////////////////////////////////////////////////////////////
void login(){
	FILE *fp;
	char ID[10],PS[10],UID[10],UPS[10];
	int i,F=0; 
	while(1){
		fp=fopen("user.txt","r");
		printf("============ 로그인 ==========\n");
		printf("       ID   :    ");
		gets(UID);
		printf("  Password  :    ");
		for(i=0;i<10;i++){
			UPS[i]=getch();         //getch를 사용하여 비밀번호를 입력할때마다 *출력  
			if(UPS[i]==13){
				UPS[i]='\0';
				printf("\n");
				break;
			} 
			
			printf("*");
		}
		printf("=============================\n");
		while(!feof(fp)==1){
			fscanf(fp,"%s\t%s",ID,PS);
			if(strcmp(UID,ID)==0 && strcmp(UPS,PS)==0){  //입력한 정보랑 소스 정보랑 일치하면 break 
				break;
			}

		}
	if(strcmp(UID,ID)==0 && strcmp(UPS,PS)==0){
		printf("로그인 되었습니다.\n");
		printf("=============================\n");
		printf("result.txt로 출력되었습니다.\n");
		break;
	}
	else{
		F++;
		printf("*****************************\n");
		printf("잘못된ID나Password입니다\n");
		printf("*****************************\n");
		if(F==3){                                        //F로 카운팅하여 F가 3이되면 프로그램종료 
			printf("로그인에 세번 실패하여 프로그램을 종료합니다");
			exit(0);
		}
	}
	
}
}

///////////////////////////////////////////////////////////////////////// 
void score(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank){
	FILE *ap,*sp;
	sp=fopen("source.txt","r");
	ap=fopen("answer.txt","r");
	int i,u,a[10],score,answer[10]; 
	while(!feof(ap)==1){
		for(i=0;i<10;i++){
			fscanf(ap,"%d",&answer[i]);     //답 읽어오기  
			}
		}
	while(!feof(sp)==1){
		for(i=0;i<17;i++){
			rank[i]=i+1;
			score=0;
			fscanf(sp,"%s %s %s",x[i],y[i],z[i]);
			for(u=0;u<10;u++){
				fscanf(sp,"%d",&a[u]);
				if(answer[u]==a[u]){                //정답이면 스코어 +10 
					score=score+10;
				}
		
			}
		s[i]=score;
		}	
	}
	
}
////////////////////////////////////////////////////////////////////////////
void ranking(char(*x)[10],char(*y)[15],char(*z)[10],int *s){
	int u,i;
	char temp[10];
	int temp1;
	for(u=0;u<20;u++){
		for(i=0;i<17;i++){
			if(s[i]<s[i+1]){                             //strcpy 를 사용하여 스코어높은 순서대로 정렬  
				strcpy(temp,x[i]);
				strcpy(x[i],x[i+1]);
				strcpy(x[i+1],temp);
				strcpy(temp,y[i]);
				strcpy(y[i],y[i+1]);
				strcpy(y[i+1],temp);
				strcpy(temp,z[i]);
				strcpy(z[i],z[i+1]);
				strcpy(z[i+1],temp);
				temp1=s[i];
				s[i]=s[i+1];
				s[i+1]=temp1;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
void tie(int *s,int *rank){
	int u,i;
	for(u=0;u<20;u++){
		for(i=0;i<17;i++){
			if(s[i]==s[i+1]){            //스코어가 같으면 동점자 등수 처리 
				rank[i]=rank[i+1];
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
void print(char(*x)[10],char(*y)[15],char(*z)[10],int *s,int *rank){
	int a1=0,a2=0,a3=0,a4=0,i;
	FILE *rp;
	float cs=0,as=0,bs=0,es=0;
	rp=fopen("result.txt","w");
	fprintf(rp,"=====================================================\n");
	printf("==============================================================\n");
	fprintf(rp," 이름\t\t 학과 \t\t     학번     \t 점수 \t 등수   \n");
	printf(" 이름\t\t 학과 \t\t     학번     \t 점수 \t 등수   \n");
	fprintf(rp,"=====================================================\n");
	printf("==============================================================\n");
	for(i=0;i<17;i++){
		fprintf(rp,"%-12s \t %-12s \t %s \t %d \t %d\n",x[i],y[i],z[i],s[i],rank[i]);
		printf("%-12s \t %-12s \t %s \t %d \t %d\n",x[i],y[i],z[i],s[i],rank[i]);
		if(strcmp(y[i],"Computer")==0){              //strcmp로 학과별 인원수랑 평균 
			a1++;
			cs=cs+s[i];
		}
		else if(strcmp(y[i],"Art")==0){
			a2++;
			as=as+s[i];
		}
		else if(strcmp(y[i],"Electricity")==0){
			a3++;
			es=es+s[i];
		}
		else{
			a4++;
			bs=bs+s[i];
		}
		
	}
	fprintf(rp,"=====================================================\n");
	fprintf(rp," \t\t학과\t\t 인원 \t\t 평균 \n");
	fprintf(rp,"=====================================================\n");
	fprintf(rp,"\t\tComputer\t  %d\t\t %.2f\n",a1,cs/a1);
	fprintf(rp,"\t\tElectricity \t  %d\t\t %.2f\n",a3,es/a3);
	fprintf(rp,"\t\tArt \t\t  %d\t\t %.2f\n",a2,as/a2);
	fprintf(rp,"\t\tBusiness \t\t  %d\t\t %.2f\n",a4,bs/a4);\
	printf("==============================================================\n");
	printf(" \t\t학과\t\t 인원 \t\t 평균 \n");
	printf("==============================================================\n");
	printf("\t\tComputer\t  %d\t\t %.2f\n",a1,cs/a1);
	printf("\t\tElectricity \t  %d\t\t %.2f\n",a3,es/a3);
	printf("\t\tArt \t\t  %d\t\t %.2f\n",a2,as/a2);
	printf("\t\tBusiness \t  %d\t\t %.2f\n",a4,bs/a4);


}

