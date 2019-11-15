#include <stdio.h>
int main()
{
    int i = 0;
    printf("Enter any characters not more than 50 characters:");
    int digit[i];
    int j = 0;
    int k = 0;
    while (i <= 50)
    {
        digit[i] = getchar();
        if (digit[i] == '\n' || digit[i] == EOF)
        {
            break;
        }
        else
        {
            if ((digit[i] != 'a') && (digit[i] != 'A') && (digit[i] != '0'))
            {
                ;
            }
            else
            {
                if (digit[i] == 'a' || digit[i] == 'A')
                {
                    j++;
                }
                else if (digit[i] == '0')
                {
                    k++;
                }
            }
        }
        i++;
    }
    printf("The number of a is: %d and the number of 0 is: %d\n", j, k);
    return 0;
}
