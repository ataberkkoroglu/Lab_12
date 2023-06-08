#include<stdio.h>


int main(void){

int sum=0,count=0,num;
FILE *fp;
fp=fopen("Numbers.txt","r");
if (fp==NULL){
    printf("\n\e[1;4;31mThis File Couldn't Be Opened...\n\e[0m\a");
    return 1;
}
while(fscanf(fp,"%d",&num)==1){

    sum +=num;
    count++;

}
printf("\n\e[1;36mSum:\e[1;37m%d\n\e[1;35mCount Of Numbers : \e[1;37m%d\n\e[1;34mMean : \e[1;37m%f",sum,count,(float)sum/count);


return 0;
}
