#include <stdio.h>
int n;
void qksort(int arr[],int low,int high){
    int i,j,temp,pivot;
    i=low-1;
    pivot=arr[high];
    if(low<high){
        for(j=low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=temp;
        pivot=i+1;
        //passes start
        printf("\n");
        for(int k=0;k<n;k++)
        printf("%d ",arr[k]);
        //passes end
        qksort(arr,low,pivot-1); 
        qksort(arr,pivot+1,high);
    }
}
void main(){
    int arr[]={5,6,2,3,1,8,4};
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Passes are : \n");
    qksort(arr,0,n-1);
    printf("\n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
}