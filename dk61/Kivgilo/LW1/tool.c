#include <stdio.h>
#include "tool.h" 

void vtoroy_faktorial(float A,float C,float B)
{ 
float Y, D, Q, X; 
 if (B + sqr(C) == 0 && B <= 0) 
        {
         printf(" Vvedi chislo > 0 \n"); 
         return;
        }
    else
        {
            X=(A*B)/(B+sqr(C)); 
            printf("X=%f",(A*B)/(B+sqr(C))); 
        }
    printf("\n");
    
    Y=suma_factorialov(D,B); //suma 
    
    printf("Y=%f",suma_factorialov(D,B)); 
    printf("\n");

    Q=X+Y;
    printf("Q=%f",X+Y);
 } 

float suma_factorialov(float D,float B)
{
float sum=0;
float fact=1;

    for (D=0;D<=B;D++)
    {
        if (D==0)
            sum++;
        else
        {
            fact=fact*D;
            sum = fact + sum;
        }
    }
   return sum;
    printf("\n");
}

float sqr(float C) 
{
float result=0;
    result=C*C;
return result;
}




