#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<math.h>

typedef struct Vector{
   float x;
   float y;
} Vector2_t;

void ScanVector(Vector2_t *vector,int num,FILE *fp){

     for(int i=0;i<num;i++){

        printf("\n\e[1;36mEnter X Of %d.Coordination :\e[0m ",i+1);scanf("%f",&vector[i].x);
        fprintf(fp,"\nEnter X Of %d.Coordination : %f",i+1,vector[i].x);
        printf("\n\e[1;35mEnter Y Of %d.Coordination :\e[0m ",i+1);scanf("%f",&vector[i].y);
        fprintf(fp,"\nEnter Y Of %d.Coordination : %f",i+1,vector[i].y);
    }

}

void SumVector(Vector2_t *vector,int num){

    vector[num].x=0;
    vector[num].y=0;

    for(int i=0;i<num;i++){
        vector[num].x +=vector[i].x;
        vector[num].y +=vector[i].y;
    }


}

void PrintVector(Vector2_t *vector,int num,FILE *fp);



int main(void){
 time_t Time;
    Time=time(NULL);
    struct tm *Tm=localtime(&Time);
    printf("\e[1mWelcome To Program...\n%.2d : %.2d : %.2d  %.2d / %.2d / %.2d",Tm->tm_hour,Tm->tm_min,Tm->tm_sec,Tm->tm_mday,Tm->tm_mon+1,Tm->tm_year+1900);
    FILE *fp;
    int num,i;
    char ch;
    fp=fopen("carteisan.txt","w");
    if (fp==NULL){
        printf("\n\e[1;4;31mFile Couldn't Be Opened...\n\e[0m\a");
        return 1;
    }
    while(1){
       printf("\n\e[1;36mHow Many Vectors Will Be Summed :\e[0m ");scanf("%d",&num);
       Vector2_t vector[num+1];
       ScanVector(vector,num,fp);
       SumVector(vector,num);
       PrintVector(vector,num,fp);
         while(1){

          printf("\n\e[1;36mWould You Like To Contunie (Y/N) ? : ");scanf(" %c",&ch);

          if (ch=='Y' || ch=='y'){
            fprintf(fp,"\n");
            Sleep(2000);break;
          }
          else if (ch=='N' || ch=='n'){
            fclose(fp);

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

void PrintVector(Vector2_t *vector,int num,FILE *fp){
   char sign,sign1;
   if (num>1){
   for(int i=0;i<num;i++){
    sign= (vector+i)->x>=0 ? '+':'-';
    sign1= (vector+i)->y>=0 ? '+':'-';

    if (sign=='-')
     (vector+i)->x=abs((vector+i)->x);
    if (sign1=='-')
     (vector+i)->y=abs((vector+i)->y);

    fprintf(fp,"\n %c %fx %c %fy",sign,(vector+i)->x,sign1,(vector+i)->y);
    printf("\n %c %fx %c %fy",sign,(vector+i)->x,sign1,(vector+i)->y);
   }
   fprintf(fp,"\n+");
   printf("\n+");
   fprintf(fp,"\n-------------------------------------------");
   printf("\n-------------------------------------------");
   sign= (vector+num)->x>=0 ? '+':'-';
   sign1= (vector+num)->y>=0 ? '+':'-';
    if (sign=='-')
     (vector+num)->x=abs((vector+num)->x);
    if (sign1=='-')
     (vector+num)->y=abs((vector+num)->y);
   fprintf(fp,"\n  %c %fx %c %fy",sign,(vector+num)->x,sign1,(vector+num)->y);
   printf("\n  %c %fx %c %fy",sign,(vector+num)->x,sign1,(vector+num)->y);
   }
   else{
    fprintf(fp,"\n %c %fx %c %fy",sign,(vector)->x,sign1,(vector)->y);
    printf("\n %c %fx %c %fy",sign,(vector)->x,sign1,(vector)->y);
   }
}
