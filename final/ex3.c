#include <stdio.h>  //求最小值
#include <stdlib.h> //for atof()
#include <ctype.h>
int main(int argc, char *argv[])
{
    int i = 1, j = 0;
    double a[100];
    if (argc == 1)
    {
        printf("The program needs at least one  integer parameter\n");
        return 0;
    }
    while (i < 100)
    {
        if (argv[j + 1] == 0)
        {
            break;
        }
        a[j] = atof(argv[i]);
        i++;
        j++;
    }
    int min = a[0];
    for (i = 1; i < j; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    printf("Min parameter is %d\n", min);
    return 0;
}
