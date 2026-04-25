#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("enter string: ");
    scanf("%[^\n]s", str);

    int count = 1, i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            count++;
        }
        i++;
    }
    printf("words: %d", count);

    return 0;
}