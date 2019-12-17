#include <stdio.h>
#include <stdlib.h> //for atof()
#include <string.h>
#define MAXOP 100 //max size of operand or operator
#define NUMBER '0'
int getop(char[]);
void ungets(char[]);
void push(double);
double pop(void);
int main(int argc, char *argv[])
{
    char s[MAXOP];
    double op2;

    while (--argc > 0)
    {
        ungets(" "); //push end of argument
        ungets(*++argv);
        switch (getop(s))
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error:zeor divisor\n");
            break;
        default:
            printf("error:unknown command %s\n", s);
            argc = 1;
            break;
        }
    }

    printf("\t%.8g\n", pop());
    return 0;
}
#define MAXVAL 100  //阀val的最大深度
int sp = 0;         //下一个空闲阀的位置
double val[MAXVAL]; //值阀
void push(double f) //push函数把f压入值阀中
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}
double pop(void) //pop函数弹出并返回阀顶的值
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
#include <ctype.h>
int getch(void);
void ungetch(int);
int getop(char s[]) //getop函数获取下一个运算符或数值操作数
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c; //不是数
    }
    i = 0;
    if (c == '-')
    {
        c = getch();
        if (isdigit(c) || c == '.')
        {
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
            {
                ungetch(c);
            }
            return '-';
        }
    }
    if (isdigit(c)) //收集整数部分
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    if (c == '.') //收集小数部分
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZ]; //用于ungetch函数的缓冲区
int bufp = 0;     //buf中下一个空闲位置
int getch(void)   //取一个字符（可能是压回的字符）
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) //把字符压回到输入中
{
    if (bufp >= BUFSIZ)
    {
        printf("ungetch : too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
void ungets(char *s)
{
    unsigned int i = strlen(s);

    while (i > 0)
        ungetch(s[--i]);
}
