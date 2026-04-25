#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[200],f,r;
    printf("string: ");
    scanf("%[^\n]s",str);

    printf("find: ");
    scanf(" %c",&f);
    printf("replace: ");
    scanf(" %c", &r);

    int vowel1 = 0, conso1 = 0,i=0;
    char ch;
    while (str[i] != '\0')
    {
        ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            {
                vowel1++;
            }
            else
                conso1++;
        }
        i++;
    }

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == f)
            str[i] = r;
        i++;
    }
    printf("Updated output: %s\n",str);

    int vowel2=0,conso2=0;
    i=0;
    while(str[i] != '\0'){
        ch = tolower(str[i]);
        if(ch>='a' && ch<='z'){
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            {
                vowel2++;
            }
            else conso2++;
        }
        i++;
    }

    printf("Previous count- Vowels: %d, consonants: %d\n",vowel1,conso1);
    printf("Current count- Vowels: %d, consonants: %d\n", vowel2, conso2);

    return 0;
}