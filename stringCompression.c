//443. String Compression
/*
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void compressString(char *str, int length)
{
    if (length <= 1)
    {
        return;
    }
    char lead = str[0];
    int count = 1, idx = 0;

    char buffer[3];

    for (int i = 1; i <= length; i++)
    {
        if (str[i] == lead)
        {
            count++;
            continue;
        }
        str[idx++] = lead;
        if (count >= 2)
        {
            sprintf(buffer, "%d", count);
            for (int j = 0; j < strlen(buffer); j++)
            {
                str[idx++] = buffer[j];
            }
        }
        lead = str[i];
        count = 1;
    }
    str[idx] = '\0';
    return;
}

int main(int argc, char *argv[])
{
    char str[100] = {'\0'};
    int length;
    if (argc == 1)
    {
        printf("Please enter a string to be compressed\n");
        return 0;
    }
    //char *st = (char *)malloc(sizeof(argv[1]));
    strcpy(str, argv[1]);
    length = strlen(str);

    printf("Input string is: %s, strlen is= %lu, size is= %lu\n", str, strlen(str), sizeof(str));

    compressString(str, length);

    printf("Compressed String is: %s\n", str);
    return 0;
}