#include <stdio.h>
#include <malloc.h>
#include "mystring.h"

int main(int argc, const char *argv[])
{
    char *str = (char *)malloc(sizeof(char) * 100);
    char c = 0;
    scanf("%s\n%c", str, &c);
    delchar(str, c);
    printf("%s\n", str);
    return 0;
}