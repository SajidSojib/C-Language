#include<stdio.h>
#include<string.h>
int main() {
    // Define a structure to hold cricket player data
    typedef struct a
    {
        char name[50];
        int match;
        float avg;
    } cricket;

    cricket arr[3];

    // Input data for each cricket player
    for (int i = 0; i < 3; i++)
    {
        scanf("%[^\n]s",arr[i].name);
        scanf("%d",&arr[i].match);
        scanf("%f",&arr[i].avg);
    }

    // Display data for each cricket player
    for (int i = 0; i < 3; i++)
    {
        printf("\n%s\n",arr[i].name);
        printf("Total match: %d\n", arr[i].match);
        printf("Average runs: %.2f\n",arr[i].avg);
    }

    return 0;
}