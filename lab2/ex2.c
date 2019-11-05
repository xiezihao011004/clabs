#include <stdio.h>
int bitcount(unsigned x);
int main(void)
{
    char digit[6];
    int i = 0;
    int n = 0;
    while (i < 7)
    {
            digit[i] = getchar();
            if(digit[i] == '\n')
            {
                break;
            }
            n = n * 10 + (digit[i] - '0');
            i++ ; 
    }
    printf("输入数字%d\n", n);
    printf("二进制中1的个数%d\n", bitcount(n));    
    return 0;
}
int bitcount(unsigned x)
{
    int b;
    for(b = 0;x != 0; x >>=1)
    {
        if(x & 01)
        {
            b++;
        }
    }
    return b;
}