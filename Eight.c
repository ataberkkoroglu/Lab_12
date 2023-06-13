#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

int main(void)
{

    FILE *fp;
    time_t Time;
    Time=time(NULL);
    struct tm *Tm=localtime(&Time);
    printf("\e[1mWelcome To Program...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\n",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);

    srand(Time);

    int n,i,num,sum;
    double std;
    char ch;

    while(1)
    {
        sum=0;
        fp=fopen("STD.txt","w+");
        if(fp==NULL)
        {
            fprintf(stderr,"\e[1;4;31This File Couldn't Be Opened!..\e[0m\n\a");
            return 1;
        }
        printf("\n\e[1;35mHow Many Numbers Do You Want To Generate Randomly ? :\e[0m ");
        fscanf(stdin,"%d",&n);

        for (i=0; i<n; i++)
        {
            fprintf(fp,"%d\n",rand()%100);
        }
        fclose(fp);
        fp=fopen("STD.txt","a+");
        if(fp==NULL)
        {
            fprintf(stderr,"\e[1;4;31This File Couldn't Be Opened!..\e[0m\n\a");
            return 1;
        }
        for(i=1; fscanf(fp,"%d",&num)==1; i++)

            std=sqrt(pow(num-((float) (sum+=num)/i),2)/i);


        fprintf(fp,"STD : %.2f",std);
        fprintf(stdout,"\n\e[1;32mSTD : \e[1;37m%.2f",std);

        fclose(fp);
        while(1)
        {
            fflush(stdin);
            printf("\n\e[1;36mWould You Like To Contunie (Y/N) ? :\e[0m ");
            ch=getchar();

            if(ch=='Y' || ch=='y')
            {
                Sleep(2000);
                break;
            }

            else if (ch=='N' || ch=='n')
            {
                Time=time(NULL);
                Tm=localtime(&Time);
                printf("\e[1;32mHave a Good Days..\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\n\e[0m",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
                return 0;
            }

            else
            {
                printf("\n\e[1;4;31mWrong Character...\nPlease Write Again...\n\e[0m\a");
            }
        }

    }

}
