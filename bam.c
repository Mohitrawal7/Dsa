#include<stdio.h>
int main() {
int i,j,p,temp;
int no[]={1,2,3,5,4,5,7,9,10,8};
printf("ascending order\n");
for (i=0;i<10;i++){
    for(j=i+1;j<10;j++){
        if(no[i]>no[j]){
            temp=no[i];
            no[i]=no[j];
            no[j]=temp;
        }
    }
    }
for (i=0;i<10;i++){
    for(j=i+1;j<10;j++){
        if(no[i]==no[j]){
            printf("%d is repeated\n",no[i]);
p=i+2;
}
}
}
no[p-1]=p;
printf("%d is missing \n",no[p-1]);
for (i=0;i<10;i++){
        printf("%d\t",no[i]);
}
return 0;
}