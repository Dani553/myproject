#include <stdio.h> 
#include "calculate.h"
#include <string.h>
#include "main.c"

int main (void)
{
float Numeral; char Operation[4]; float Result; printf("Число: ");
scanf("%f",&Numeral);
printf("Операция (+,-,*,/,pow,sqrt,sin,cos,tan): "); scanf("%s",&Operation);
Result = Calculate(Numeral, Operation); printf("%6.2f\n",Result);
return 0;
}
