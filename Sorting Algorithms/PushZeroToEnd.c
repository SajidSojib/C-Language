// insertion sort
// #include<stdio.h>
// int main(){
//     int n=9;
//     int arr[9]={5,0,2,0,7,4,1,3,0};
//     for (int i = 1; i < n; i++)
//     {
//       int j=i;
//       while (arr[j-1]==0 && j>0)
//       {
//         int temp=arr[j];
//         arr[j]=arr[j-1];
//         arr[j-1]=temp;
//         j--;
//       }   
//     }
    
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ",arr[i]);
//     }
    
//     return 0;
// }


//bubble sort
// #include<stdio.h>
// int main(){
//     int n=9;
//     int arr[9]={5,0,2,0,7,4,1,3,0};
//     for (int i = 0; i < n-1; i++)
//     {
//       for (int j = 0; j < n-1-i; j++)
//       {
//         if (arr[j]==0)
//         {
//             int temp=arr[j];
//             arr[j]=arr[j+1];
//             arr[j+1]=temp;
//         } 
//       }   
//     }
    
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ",arr[i]);
//     }
    
//     return 0;
// }


#include<stdio.h>
int main(){
    int n=9;
    int arr[9]={5,0,2,0,7,4,1,3,0};
    int ans[9];
    int idx=0;
    for (int i = 0; i < n-1; i++)
    {
      if (arr[i]!=0)
      {
        ans[idx]=arr[i];
        idx++;
      }
    }

    while (idx<9)
    {
        ans[idx]=0;
        idx++;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ans[i]);
    }
    
    return 0;
}