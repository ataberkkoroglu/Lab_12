#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){

int num,i,random;
srand(time(NULL));
FILE *fp,*file;

fp=fopen("Numbers.txt","w");
file=fopen("Numbers.bin","wb");

if (file==NULL || fp==NULL){
    printf("\n\e[1;4;31mFiles Couldn't Be Opened...\a\n\e[0m");
    return 1;
}
printf("\nHow Many Numbers Do You Want To Generate Randomly ? : ");scanf("%d",&num);

for(i=0;i<num;i++){
    random=rand()%100;
    fprintf(fp,"%d\n",random);
    fprintf(file,"%x\n",random);
}

fclose(fp);
return 0;
}
