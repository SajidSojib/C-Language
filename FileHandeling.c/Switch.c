#include<stdio.h>
int main(){
    int n;
    printf("enter number 1-7: ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        printf("\nSaturday\n\n");
        break;
    case 2:
        printf("\nSunday\n\n");
        break;
    case 3:
        printf("\nMonday\n\n");
        break;
    case 4:
        printf("\nTwe4sday\n\n");
        break;
    case 5:
        printf("\nWednasday\n\n");
        break;
    case 6:
        printf("\nThursday\n\n");
        break;   
    case 7:
        printf("\nFriday\n\n");
        break; 
    default:
        printf("Invalid number");
        break;
    }

    return 0;
}