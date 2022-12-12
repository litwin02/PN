#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "upLow.h"

char *replaceFuncWithENG(char *str, char sep, char *up_or_down)
{
    int16_t offset = 0;
    int8_t numLen = 0;
    char *ptr = malloc(500);
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i]))
        {
            if (isdigit(str[i]))
            {
                switch (str[i])
                {
                case 0:;
                    char *num;
                    num = "Zero";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 1:;
                    num = "One";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 2:;
                    num = "Two";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 3:;
                    num = "Three";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 4:;
                    num = "Four";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 5:;
                    num = "Five";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 6:;
                    num = "Six";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 7:;
                    num = "Seven";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 8:;
                    num = "Eight";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                case 9:;
                    num = "Nine";
                    ptr[i - offset + numLen] = *num;
                    numLen += strlen(num);
                    break;
                default:
                    break;
                }
            }
            else
                ptr[i - offset + numLen] = str[i];
            continue;
        }
        else
        {
            if (i == 0 && isalnum(str[i]) == 0)
            {
                offset++;
                continue;
            }
            else if (str[i + 1] == '\0' && isalnum(str[i]) == 0)
            {
                ptr[i - offset + numLen] = '\0';
                break;
            }
            else if (isalnum(str[i + 1]) == 0 && isalnum(str[i]) == 0)
            {
                offset++;
                continue;
            }
            else
                ptr[i - offset + numLen] = sep;
        }
    }
    ptr = realloc(ptr, strlen(ptr));
    if (up_or_down == "low")
        ptr = toUpper(ptr);
    else
        ptr = toLower(ptr);
    return ptr;
}

char *replaceFunc(char *str, char sep, char *up_or_down)
{
    int8_t offset = 0;
    char *ptr = malloc(strlen(str));
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i]))
        {
            ptr[i - offset] = str[i];
            continue;
        }
        else
        {
            if (i == 0 && isalnum(str[i]) == 0)
            {
                offset++;
                continue;
            }
            else if (str[i + 1] == '\0' && isalnum(str[i]) == 0)
            {
                ptr[i - offset] = '\0';
                break;
            }
            else if (isalnum(str[i + 1]) == 0 && isalnum(str[i]) == 0)
            {
                offset++;
                continue;
            }
            else
                ptr[i - offset] = sep;
        }
    }
    ptr = realloc(ptr, strlen(ptr));
    if (up_or_down == "low")
        ptr = toUpper(ptr);
    else
        ptr = toLower(ptr);
    return ptr;
}

int main(void)
{
    char str[] = "@Hello!World$$123)";
    char sep = '-';
    printf("%s", replaceFunc(str, sep, "up"));
}
