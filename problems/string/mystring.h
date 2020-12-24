#include <malloc.h>

int strlen(char *str)
{
    int n = 0;
    while (str[n++] != '\0')
    {
    }
    return n;
}

void delchar(char *str, char c)
{
    char *tmp = (char *)malloc(sizeof(char) * 1000);
    char *head = tmp;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != c)
            *tmp++ = str[i];
    }
    int i = 0;
    for (; i < strlen(head); i++)
    {
        str[i] = head[i];
    }
    str[i] = '\0';
}