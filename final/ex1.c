#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
int getch(void);
void ungetch(int);
char getfloat(double *pn);
int main()
{
    int n;
    double i = 0.000000;
    double array[10000];
    char getfloat(double *);
    printf("enter float:");
    for (n = 0; n < 10000 ; n++)
    {
        if(getfloat(&array[n]) == '\n')
        {
            i = i + array[n];
            break;
        }
       
        i = i +array[n];
    }
    double sum;
    sum = i * i;
    printf("The sum of the squares = %f\n", sum);
    return 0;
}
char getfloat(double *pn)
{
    int c, sign, flag = 1;
    while (isspace(c = getch()))
    {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.')
    {
        c = getchar();
        if (!isdigit(c))
        {
            ungetch(c);
        }
        for (; isdigit(c); c = getchar())
        {
            flag *= 10;
            *pn = 10 * *pn + (c - '0');
        }
    }
    *pn = *pn / flag * sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
