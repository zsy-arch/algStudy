#include <stdio.h>
#include <string.h>

char get_right_letter(char c)
{
    char str[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
            return str[i - 1];
    }
    return ' ';
}

int main(int argc, const char *argv[])
{
    char c;

    while ((c = getchar()) != '\n')
    {
        printf("%c", get_right_letter(c));
    }    
    printf("\n");
}