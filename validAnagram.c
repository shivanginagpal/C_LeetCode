//Leet Code: 242. Valid Anagram

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define NUM_CHAR 256

bool isAnagram(char *st1, char *st2)
{
    int len1 = strlen(st1), len2 = strlen(st2);
    if (len1 != len2)
    {
        return false;
    }
    int map[NUM_CHAR] = {0};

    for (int i = 0; i < len1; i++)
    {
        map[st1[i]]++;
        map[st2[i]]--;
    }
    for (int i = 0; i < NUM_CHAR; i++)
    {
        if (map[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char *str1 = "Leetcode";
    char *str2 = "codeLeet";
    if (isAnagram(str1, str2))
    {
        printf("Given strings %s and %s are anagrams\n", str1, str2);
    }
    else
    {
        printf("Strings %s and %s are NOT anagrams\n", str1, str2);
    }
    return 0;
}