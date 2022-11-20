#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* replaceFnc(char *str, char sep)
{
    int16_t offset = 0;
    char* ptr = malloc(strlen(str));
    for(int i=0; i<strlen(str); i++)
    {
        if(isalnum(str[i]))
        {
            ptr[i-offset]=str[i];
            continue;
        }
        else
        {
            if(i==0 && isalnum(str[i])==0){
                offset++;
                continue;
            }
            else if(str[i+1]=='\0' && isalnum(str[i])==0){
                ptr[i-offset]='\0';
                break;
            }
            else if(isalnum(str[i+1])==0 && isalnum(str[i])==0){
                offset++;
                continue;
            }
            else
                ptr[i-offset]=sep;
        }
    }
    ptr = realloc(ptr, strlen(ptr));
    return ptr;
}

int main(void)
{
    char str[] = "@Hello!World$$123)";
    char sep = '-';
    printf("%s", replaceFnc(str, sep));
}