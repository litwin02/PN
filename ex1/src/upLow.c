#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *toLower(char *s)
{
  char *ptr = malloc(strlen(s));
  for (int i = 0; i < strlen(s); i++)
    ptr[i] = tolower(s[i]);
  return ptr;
}

char *toUpper(char *s)
{
  char *ptr = malloc(strlen(s));
  for (int i = 0; i < strlen(s); i++)
    ptr[i] = toupper(s[i]);
  return ptr;
}