#include<stdio.h>
#include<string.h>
int main(){
    FILE *file;
    file = fopen("text1.txt","r");
    char ch;
    if(file==NULL)
    {
        printf("File does not exist");
    }
    else{
        printf("File is opened\n\n");

        int charecter=0,word=1,line=0;
        ch=fgetc(file);
        while (ch!=EOF)
        {
            if(ch==' ' || ch=='\n') word++;
            if(ch=='.') line++;
            charecter++;
            printf("%c",ch);
            ch=fgetc(file);

        }
        printf("\n\ncharacter: %d\n",charecter);
        printf("word: %d\n",word);
        printf("line: %d\n", line);

        printf("\nfile closed");
        fclose(file);
    }

    return 0;
}