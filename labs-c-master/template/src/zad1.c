#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Miał być link z pliku strings.h ale linker mnie zawodzi :/

char* toLower(char* s);
char* toUpper(char* s);

char* replaceFnc(char *str, char sep, char *up_or_down)
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
    if(up_or_down=="low")
        ptr = toUpper(ptr);
    else
        ptr = toLower(ptr);
    return ptr;
}

int main(void)
{
    char str[] = "@Hello!World$$123)";
    char sep = '-';
    printf("%s", replaceFnc(str, sep, "up"));
}

char* toLower(char* s)
{
    char* ptr = malloc(strlen(s));
    for(int i=0; i<strlen(s); i++)
        ptr[i] = tolower(s[i]);
    return ptr;
}

char* toUpper(char* s) {
    char* ptr = malloc(strlen(s));
    for(int i=0; i<strlen(s); i++)
        ptr[i] = toupper(s[i]);
    return ptr;
}