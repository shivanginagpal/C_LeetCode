//Interview Cake: Write a function that takes a string and reverses the words in place.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//O(n) time and O(1) space

void reverseString(char *str, int left, int right)
{
    while (left < right)
    {
        char temp = str[left];
        str[left++] = str[right];
        str[right--] = temp;
    }
    //str[len] = '\0';
    //return str;
}
int main()
{
    char str[] = "Hello Shivangi Whats up?";
    reverseString(str, 0, strlen(str) - 1);
    printf("Rveresed string is: %s\n", str);
    int start = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == ' ' || (i == strlen(str)))
        {
            reverseString(str, start, i - 1);
            start = i + 1;
        }
    }
    printf("String with reversed words is %s\n", str);
}