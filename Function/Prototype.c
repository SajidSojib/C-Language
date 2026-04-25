#include <stdio.h>
void england()
{
    printf("you are in england"); //6
    return;  //7
}

void bangladesh()
{
    printf("you are in bangladesh\n"); // 2
    void australia();
        australia();                   // 3
    return;                            // 9
}

int main()
{
    bangladesh(); // 1
    return 0;     // 10
}
void australia()
{
    printf("you are in australia\n"); // 4
     england();                   // 5
    return;                           // 8
}