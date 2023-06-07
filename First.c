#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<string.h>

int main(){
    int i;
    char Name[20],Surname[20],birth[11],ch;
    FILE *fp;

    fp=fopen("Myfile.txt","a+");

    if (fp==NULL){
        return 1;
    }

    time_t Time;
    Time=time(NULL);
    struct tm *Tm=localtime(&Time);
    printf("\e[1mWelcome To Program...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);

    if(fscanf(fp,"%s %s %s",Name,Surname,birth)!=3)
      fprintf(fp,"  Name  \t  Surname  \t  Date Of Birth  \n--------\t-----------\t----------------");

    while(1){

        strcpy(Name,"");
        strcpy(Surname,"");
        strcpy(birth,"");

        fseek(fp,0,SEEK_END);
        fflush(stdin);

        printf("\n\e[1;35mWrite Your Name :\e[0m ");gets(Name);
        fflush(stdin);

        printf("\n\e[1;34mWrite Your Last Name :\e[0m ");gets(Surname);
        fflush(stdin);

        printf("\n\e[1;36mWrite Your Date Of Birth :\e[0m ");gets(birth);
        fflush(stdin);

        fprintf(fp,"\n%s  \t  %s  \t  %s  ",Name,Surname,birth);

        while(1){

            printf("\n\e[1;36mWould You Like To Contunie (Y/N) ? :\e[0m ");ch=getchar();

            if(ch=='Y' || ch=='y'){

                fseek(fp,(strlen(Name)+strlen(Surname)+strlen(birth)+5),SEEK_END);
                Sleep(2000);break;
            }

            else if (ch=='N' || ch=='n'){
                fclose(fp);
                fp=fopen("Myfile.txt","r");

                if (fp==NULL){
                    return 1;
                }
                 for(int i=0;!feof(fp);i++) {
                  if (i>7)
                    i=0;
                  printf("\e[1;%dm%c",30+i,fgetc(fp));

                  }

                Time=time(NULL);
                Tm=localtime(&Time);
                printf("\n\n\e[1;32mHave a Good Days...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\e[0m\n",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
                fclose(fp);
                return 0;

            }
            else{
                printf("\n\e[1;4;31mWrong Character...\nPlease Write Again...\n\e[0m\a");
            }
        }
    }
    return 0;
}
