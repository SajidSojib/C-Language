// #include<stdio.h>
// int main(){
//     int arr[]={3,5,6,7,9,12};  //increasing
//     int sum=12;

//     for (int i = 0; i < 6-1; i++)
//     {
//         for (int j = i+1; j < 6 ; j++)
//         {
//             if (arr[i]+arr[j]==sum)
//             {
//                 printf("%d %d\n",arr[i],arr[j]);
//             } 
//         }    
//     }

//     return 0;
// }


#include<stdio.h>
int main(){
    int arr[]={3,5,6,7,9,12};  //increasing
    int sum=12,a=4;

    for (int i = 0, j=5; i < j; a=4)
    {
        if (arr[i]+arr[j]==sum)
        {
            printf("%d %d\n",arr[i],arr[j]);
            i++;
            j--;
        }

        else if (arr[i]+arr[j]>sum) j--;
        else i++;    
    }

    return 0;
}