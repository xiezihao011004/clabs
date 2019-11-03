#include <stdio.h>
int bitcount(unsigned x);
int main(void)
{
   int a, b, c, d, e;
   a = getchar(); 
   b = getchar();
   if(b != '\n')
     {
       c = getchar();
        if(c != '\n')
          {
            d = getchar();
            if(d != '\n')
            {
              e = getchar();
              if(e !='\n')
              {
                getchar();//读取回车
              }
            }
          }
     }      
   int n;
   if (b == '\n')
     {   
       n = a -'0';
       printf("输入数字二进制表达中二进制位是1的个数为%d\n",bitcount(n));
       }
   else if(c == '\n')
     {
       n = (a - '0')* 10 + b - '0';
       printf("输入数字二进制表达中二进制位是1的个数为%d\n",bitcount(n));
     }
  else if(d == '\n')
     {
       n = (a - '0') * 100 + (b -'0')* 10 + c - '0';
       printf("输入数字二进制表达中二进制位是1的个数为%d\n",bitcount(n));
     }
  else if(e == '\n')
    {
      n = (a - '0') * 1000 +(b - '0') * 100 + (c - '0') * 10 + d - '0';
      printf("输入数字二进制表达中二进制位是1的个数为%d\n",bitcount(n));
    }
  else
     {
       n = (a - '0') * 10000 + (b - '0') * 1000 +(c - '0') * 100 + (d - '0') * 10 + e  - '0';
       printf("输入数字二进制表达中二进制位是1的个数为%d\n",bitcount(n));
     }
     printf("你当时输入的数字是%d\n",n);
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