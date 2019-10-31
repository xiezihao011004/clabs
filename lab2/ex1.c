//打印出unsigned int数据类型在此机器中最大整数以及这个最大整数的位数
#include <stdio.h>
int main(void)
{
    unsigned int a, b;//设置两个变量a，b
    a = 1;
    b = 0;
    while ( a > 0)//当a>0时，a一直加1直到a不大于0，当a成为最大整数时再加1，a就会变成0不再符合条件
    {
        a++;
    }
    printf("unsigned int max = %u\n",a -1);//此时如果打印a，那么打印出来的是比最大整数大1的数，所以要a-1
    unsigned int n;//设置一个新变量n等于a-1，n就是那个最大的整数
    n = a - 1;
    do//当n大于0时一直重复b++使b+1，n是最大整数是十进制形式的，n每除以一次10，b就+1，就是记录一个位数，当n被除到个位数时，再除以10，因为是int整数型，所以n就会=0，不再重复这个循环
    {
        n = n /10;
        b++;
    } while (n > 0);
    printf("The unsigned int bit is %d\n",b);//这个时候打印出b，b就是这个最大整数的位数
    return 0;
}     