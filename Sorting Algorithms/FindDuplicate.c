// #include<stdio.h>
// int main(){
//     int arr[]={1,2,3,4,4,5};
//     for (int i = 0; i < 6-1; i++)
//     {
//         for (int j = i+1; j < 6 ; j++)
//         {
//             if (arr[i]==arr[j])
//             {
//                 printf("duplicate number is: %d",arr[i]);
//             } 
//         }    
//     }

//     return 0;
// }



// #include<stdio.h>
// int main(){
//     int arr[6]={1,2,3,5,4,5};
//     int brr[6]={0,0,0,0,0,0};
//     for (int i = 0; i <= 5; i++)
//     {
//         if (brr[arr[i]]==0)
//         {
//             brr[arr[i]]=1;
//         }
//         else printf("duplicate is: %d",arr[i]);
              
//     }

//     return 0;
// }


#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,4,5};
    int sum=0;
    for (int i = 0; i <= 5; i++)
    {
        sum+=arr[i];      
    }
    int duplicate=sum-(5*(5+1)/2);
    printf("\nduplicate: %d\n\n",duplicate);

    return 0;
}
