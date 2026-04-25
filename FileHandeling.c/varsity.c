#include <stdio.h>
int main()
{
    // file open mode: r = read, w = write, a = append, r+ = read and write, w+ = write and read, a+ = append and read
    // FILE *fptr;
    // fptr = fopen("test.txt", "w");
    // fprintf(fptr, "Hello world!\n");
    // fprintf(fptr, "This is a test file.\n");
    // fprintf(fptr, "Bye world!\n");

    // fclose(fptr);

    FILE *fptr;
    char ch;
    fptr = fopen("test.txt", "r");
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}