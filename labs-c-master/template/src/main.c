#include <stdio.h>
#include <stdint.h>
#include <math.h>

int32_t a, b, c;

void sqr_fun(int32_t a, int32_t b, int32_t c)
{
    double x0, x1, x2, xl;
    if(a==0){
      xl = -c/b;
      printf("%lf", xl);
      return;
    }
    int32_t delta = b*b-(4*a*c);
    if(delta==0){
      x0=-b/2*a;
      printf("%lf", x0);
    }
    else if(delta<0)
      printf("Brak miejsc zerowych w dziedzinie rzeczywistej");
    else
    {
      x1=(-b-sqrt(delta))/(2*a);
      x2=(-b+sqrt(delta))/(2*a);
      printf("Pierwsze miejsce zerowe: %lf Drugie miejsce zerowe: %lf", x1, x2);
    }
}

int main(void)
{
  a = 0;
  b = 4;
  c = 8;
  
  printf("Input a: ");
  scanf("%d", &a);
  printf("\nInput b: ");
  scanf("%d", &b);
  printf("\nInput c: ");
  scanf("%d", &c);
  
  sqr_fun(a, b, c);
  return 0;
}