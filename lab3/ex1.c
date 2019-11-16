#include <stdio.h>
#define X 200
int main()
{
    char s[X];
    char t[X];
    int n = 0, m = 0;
    printf("请输入字符：");
    while (s[n] != EOF)
    {
        s[n] = getchar();
        if (s[n] == ' ')
        {
            break;
        }
        n++;
    }
    getchar();
    while (t[m] != EOF)
    {
        t[m] = getchar();
        if (t[m] == '\n')
        {
            break;
        }
        m++;
    }
    int i, j, k;
    int p = n - 1;
    for (i = n - 1; i > 0; i--)
    {
        for (j = i, k = p; t[k] != 0 && s[j] == t[k]; j--, k--)
            ;
        if (k < 0)
        {
            printf("%d\n", j + 1);
            return i;
        }
        printf("-1\n");
        return -1;
    }
}
