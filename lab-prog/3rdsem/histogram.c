#include<stdio.h>
void main(){
    int a[100],i,j,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The histogram is: ");
    for(i=0;i<10;i++){
        printf("%d ",i);
        for(j=0;j<n;j++){
            if(a[j]==i)
                printf("*");
        }
    }
}