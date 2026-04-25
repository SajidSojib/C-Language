#include<stdio.h>
#include<limits.h>

int maxSubarraySum(int a[],int n){
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum>max_sum){
                max_sum=sum;
            }
        }
    }
    return max_sum;
}

int main(){
    int arr[9]={-2,3,4,-1,5,-12,6,1,3};
    int n=9;
    printf("%d",maxSubarraySum(arr,n));
    return 0;
}