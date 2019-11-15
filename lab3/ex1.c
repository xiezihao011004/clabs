#include <stdio.h>
#include <string.h>
#define x 200
int strrindex(char s[], char t[])
{
    int i, j, k;
    int len = strlen(s);
    for (i = len - 1; i >= 0; i--)
    {
        for (j = i, k = 0; t[k] != 0 && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
int main()
{
    char s[x];
    char t[x];
    printf("请输入字符：");
    scanf("%s %s", s, t);
    strrindex(s, t);
    int pos;
    pos = strrindex(s, t);
    printf("%d\n", pos);
    return 0;
}
