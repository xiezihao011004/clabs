#include <stdio.h>
int ISDigit(char a)
{
    if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F') || (a = 'x') || (a = 'X'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int bitcount(unsigned x);
int main()
{
    printf("请输入一个16进制的非负整数：");
    int x = bitcount(1);
    char hex[x];
    int n = 0;
    int i = 0;
    while ((hex[i] = getchar()) != EOF && hex[i] != '\n')
    {
        i++;
    }
    if (i > 11)
    {
        printf("输入的数字太大需要换一个小的数字\n");
        unsigned int j, k;
        j = 0;
        k = ~j;
        printf("系统最大能接受的整数是%u\n", k);
    }
    else if (!(hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')))
    {
        printf("输入了不合法的字符(1)\n");
    }
    else
    {
        int flag = 1;
        for (i = 2; hex[i] != '\n'; i++)
        {
            if (ISDigit(hex[i]))
            {
                if ((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F'))//避免0x后再出现x
                {
                    if (i > 1)
                    {
                        if (hex[i] >= '1' && hex[i] <= '9')
                        {
                            n = n * 16 + hex[i] - '0';
                        }
                        else if (hex[i] >= 'a' && hex[i] <= 'f')
                        {
                            n = n * 16 + (hex[i] - 'a' + 10);
                        }
                        else //(hex[i] >= 'A' && hex[i] <= 'F')
                        {
                            n = n * 16 + (hex[i] - 'A' + 10);
                        }
                    }
                }
                else
                {
                    printf("输入了不合法的字符(2)\n");
                    return 0;
                }
            }
            else
            {
                flag = 0;
                printf("输入了不合法的字符(3)\n");
                break;
            }
        }
        if (flag == 1)
        {
            printf("输入数字的十进制表达是:%u\n", n);
        }
    }
    return 0;
}
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x <<= 1)
        b++;
    return b;
}
