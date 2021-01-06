//3. Longest Substring Without Repeating Characters

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int longestSub(char *str)
{
    int n = strlen(str), ans = 0;
    //128 to include all characters in the ASCII set
    int set[128] = {0};
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (set[str[j] - 'a'] == 0)
        {
            set[str[j++] - 'a'] += 1;
            //since j is already incremented in the last step
            //or else you can do j-i+1
            //if you want to increase the j before end of this scope
            ans = MAX(ans, (j - i));
        }
        else
        {
            set[str[i++] - 'a'] -= 1;
        }
    }

    return ans;
}
int main()
{
    char *str = "abcaabac";
    printf("Longest Substring Length is %d\n", longestSub(str));
    return 0;
}