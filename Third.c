#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>

int digit(int num){
    int counter=0;
    while(num!=0){
      counter++;
      num /=10;
}
   return counter;
}

void Decompose(int *arr,int num);
int main(void){

    char ch;
    int num,*num_series,size,j;

    time_t Time;
    Time=time(NULL);
    struct tm *Tm=localtime(&Time);
    printf("\e[1mWelcome To Program...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
    FILE *fp;

    fp=fopen("integers.txt","a");

    if (fp==NULL){
        printf("\n\e[1;4;31mFile Couldn't Opened...\n\e[0m\a");
        return 1;
    }

    while(1){

        printf("\n\e[1;35mWrite a Number :\e[0m ");scanf("%d",&num);

        if (num==0)
           return 0;

        size=digit(num);
        num_series=(int *) calloc(size,sizeof(int));
        Decompose(num_series,num);

        printf("\n\e[1;37m%d = ",num);
        fprintf(fp,"\n%d = ",num);

        for(int i=size-1;i>0;i--){
            printf("\e[1;3%dm%d*10^%d + ",i%7,num_series[i],i);
            fprintf(fp,"%d*10^%d + ",num_series[i],i);
        }

        printf("\e[1;30m%d*10^0",num_series[0]);
        fprintf(fp,"%d*10^0",num_series[0]);


        while(1){

          printf("\n\e[1;36mWould You Like To Contunie (Y/N) ? : ");scanf(" %c",&ch);

          if (ch=='Y' || ch=='y'){
            Sleep(2000);break;
          }
          else if (ch=='N' || ch=='n'){
            fclose(fp);
            free(num_series);
            Time=time(NULL);
            Tm=localtime(&Time);
            printf("\e[1;32mHave a Good Days...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\e[0m\n",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
            _exit(0);
          }

          else
            printf("\n\e[1;4;31mWrong Character...\nPlease Write Again...\n\e[0m\a");
        }
    }
}

void Decompose(int *arr,int num){
    for(int i=0;num!=0;i++){
        *(arr+i)=num%10;
        num /=10;
    }

}
