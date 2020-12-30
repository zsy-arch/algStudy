#include <iostream>
#include <cstring>
#include <malloc.h>

void replace(char *str) {
    int i = 0;
    int n = strlen(str);
    std::cout << n << std::endl;
    for (int j = 0; j < n; ++j) {
        if (str[j] == ' ') i++;
    }
    char *p1 = &str[n];
    char *p2 = &str[n + 2 * i];
    while (p1 >= str && p1 < p2) {
        if (*p1 == ' ') {
            *p2-- = '0';
            *p2-- = '2';
            *p2-- = '%';
        } else {
            *p2-- = *p1;
        }
        p1--;
    }
}

int main() {
    char *str = (char *) malloc(sizeof(char) * 100);
    sprintf(str, "Hello     World!");
    replace(str);
    std::cout << str << std::endl;
    return 0;
}
