#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

int main(void){

    FILE *file;

    double amount,income,outcome;
    char date[10],desc[10],filename[15],ch;

    time_t Time;
    Time=time(NULL);
    struct tm *Tm=localtime(&Time);
    printf("\e[1mWelcome To Program...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);

    while(1){

    income=0;outcome=0;

    printf("\n\e[1;35mWrite Your Filename:\e[0m ");scanf("%s",filename);
    file=fopen(filename,"r");

    if (file==NULL){
        printf("\n\e[1;4;31mfailed to open file!\n\e[0m\a");
        return 1;
    }

    while(fscanf(file,"%s %lf %s",date,&amount,desc)==3){
        if(amount>=0){
            income+=amount;
        }
        else{
            outcome+=amount;
        }
    }

    fclose(file);

    file=fopen(filename,"a");

    if (file==NULL){
        printf("\n\e[1;4;31mThis File Couldn't Be Opened...\n\e[0m");
        exit(1);
    }
    fprintf(file,"\nIncome:%.3lf\nOutcome:%.3lf\nBalance:%.3lf",income,outcome,income+outcome);
    fclose(file);

    while(1){
      printf("\n\e[1;36mWould You Like To Contunie (Y/N) ? : ");ch=getche();

      if (ch=='Y' ||ch=='y'){
        Sleep(2000);
        break;
      }

      else if (ch=='N' || ch=='n'){

        Time=time(NULL);
        Tm=localtime(&Time);
        printf("\n\e[1;32mHave a Good Days...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\e[0m\n",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
        _exit(0);

      }

      else
       printf("\n\e[1;4;31mWrong Character...\nPlease Write Again...\n\e[0m\a");

    }
    }
}
