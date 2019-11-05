//打印出unsigned int数据类型在此机器中最大整数以及这个最大整数的位数
#include <stdio.h>
int bitcount(unsigned x);
int main(void)
{
    unsigned int a = 1;
    while ( a > 0)//当a>0时，a一直加1直到a不大于0，当a成为最大整数时再加1，a就会变成0不再符合条件
    {
        a++;
    }
    printf("unsigned int max = %u\n", a -1);//此时如果打印a，那么打印出来的是比最大整数大1的数，所以要a-1
    printf("The unsigned int bit is %d\n",bitcount(1));
    return 0;
}   
int bitcount (unsigned x)
   {
       int b ;
       for (b = 0; x != 0; x <<= 1)
       b++;
       return b;
    }
