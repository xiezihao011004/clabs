#include <stdio.h>
void reverse(char *s, int n);
int k = 0;
int j;
int main()
{
    char s[1000];
    int i;
    int n = 0;
    while ((s[n] = getchar()) != '\n')
    {
        n++;
    }
    j = n / 2;
    reverse(s,n);
    for(i = 0; i <= n;i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    return 1;
}
void reverse(char *s, int n)
{
    if(n == 0 || n == 1|| n == j)
    {
       return;
    }
    else
    {
        char p = s[k];
        s[k] = s[n];
        s[n] = p;
        k++;
        n--;
        reverse(s, n);
    }
}
