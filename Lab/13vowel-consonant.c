#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[100];
    printf("string: ");
    scanf("%[^\n]s", str);
    
    int i = 0,vowel=0,conso=0;
    while (str[i] != '\0')
    {
        char ch=tolower(str[i]);
        if(ch>='a' && ch<='z'){
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowel++;
            }
            else conso++;
        }

        i++;
    }
    printf("vowel: %d\n",vowel);
    printf("consonant: %d", conso);

    return 0;
}