#include <stdio.h>
void reverse(char *s)
{
    if (*s != '\0')
        reverse(s + 1);
    printf("%c", (char)*s);
}
int main()
{
    char s[10000];
    int n = 0;
    while ((s[n] = getchar()) != '\n')
    {
        n++;
    }
    reverse(s);
}
