#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file1,*file2;
    file1 = fopen("text1.txt", "r");
    file2 = fopen("text2.txt","w");
    char ch;
    if (file1 == NULL)
    {
        printf("File does not exist");
    }
    else
    {
        printf("File is opened\n\n");

        ch=fgetc(file1);
        while (ch!=EOF)
        {
            fprintf(file2,"%c",ch);
            ch=fgetc(file1);
        }

        fclose(file1);
        fclose(file2);
        printf("\n\nfile closed");
    }

    return 0;
}