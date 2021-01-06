//Interview Cake: Write a function that takes a string and reverses the letters in place
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//O(n) time and O(1) space

char *reverseString(char *str, int len)
{
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        char temp = str[left];
        str[left++] = str[right];
        str[right--] = temp;
    }
    str[len] = '\0';
    return str;
}
int main()
{
    char str[] = "Hello Shivangi Whats up?";
    printf("Rveresed string is: %s\n", reverseString(str, strlen(str)));
}