#include <stdio.h>
int main()
{
    int num = 15;
    int count = 0;

    while (num)
    {
        num &= (num - 1);
        count++;
    }
    printf("Number of 1 bits in given num are %d\n", count);
    return 0;
}