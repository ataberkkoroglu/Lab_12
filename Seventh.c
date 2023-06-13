#include<stdio.h>
#include<string.h>
#include<time.h>
#include<Windows.h>

typedef struct
{

    char Brand[30];
    char Price[15];
    char Model[30];

} Car;

int main(void)
{

    char ch;
    int n,i;

    time_t Time;
    Time=time(NULL);
    struct tm *Tm=localtime(&Time);
    printf("\e[1mWelcome To Program...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
    FILE *fp;
    fp=fopen("Car.txt","a");

    if (fp==NULL)
    {

        fprintf(stderr,"\n\e[1;4;31mFile Couldn't Be Opened...\n\e[0m\a");
        fflush(stderr);
        return 1;
    }
    while(1)
    {
        printf("\n\e[1;35mHow Many Car's Information Do You Want To Add To Text File :\e[0m  ");
        fscanf(stdin,"%d",&n);
        Car car[n];
        for(i=0; i<n; i++)
        {
            fflush(stdin);
            printf("\n\e[1;32mWrite a %d.Car's Brand :\e[0m ",i+1);
            fgets(car[i].Brand,sizeof(car[i].Brand),stdin);
            fflush(stdin);
            printf("\n\e[1;34mWrite a %i.Car's Model :\e[0m ",i+1);
            fgets(car[i].Model,sizeof(car[i].Model),stdin);
            fflush(stdin);
            printf("\n\e[1;35mWrite a %d.Car's Price :\e[0m ",i+1);
            fgets(car[i].Price,sizeof(car[i].Price),stdin);
            fflush(stdin);
        }
        fseek(fp,0,SEEK_SET);
        if (ftell(fp)!=0)
          fprintf(fp,"\n\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\n----------------------------------\n",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
        else
            fprintf(fp,"%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\n----------------------------------\n",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);

        for(i=0; i<n; i++)
        {
            fprintf(stdout,"\n---%d.Car---\nBrand: %s\nModel: %s\nPrice: %s",i+1,car[i].Brand,car[i].Model,car[i].Price);
            fflush(stdout);
            fprintf(fp,"\n\n---%d.Car---\nBrand: %s\nModel: %s\nPrice: %s",i+1,car[i].Brand,car[i].Model,car[i].Price);
        }
        while(1)
        {
            printf("\n\e[1;36mWould You Like To Continue (Y/N) ?  :\e[0m ");
            ch=fgetc(stdin);

            if(ch=='Y' || ch=='y')
            {
                Sleep(2000)
                ;
                break;
            }

            else if (ch=='N' || ch=='n')
            {

                Time=time(NULL);
                Tm=localtime(&Time);
                fprintf(stdout,"\e[1;32mHave a Good Days...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d\e[0m",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
                fflush(stdout);
                return 0;

            }

            else
            {
                printf("\n\e[1;4;31mWrong Character...\nPlease Write Again...\n\e[0m\a");

            }
        }

    }
}
