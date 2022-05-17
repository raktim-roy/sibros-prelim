#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>


bool poweroftwo(unsigned num)
{
    return num && !(num & (num - 1));
}

static unsigned quotient (unsigned num, unsigned div)
{
    if (num == 0 && div == 0) return -1;
    unsigned quotient = 0;
    while (num >= div)
    {
        num = num - div ;
        quotient++ ;
    }
    return quotient ;
    
    
}

static unsigned modulo (unsigned num, unsigned div) {
    
    if (poweroftwo(div))
    {
        return (num & (div -1));
    }
    else
    {
        if (num - div >= div)
        num = modulo (num, div + div);
        while (num >= div)
            num -= div;
         return num;
    }
    
}



typedef struct {
    unsigned quotient;
    unsigned remainder;
} divider_s;
// Implement (with all possible error checks)
void divide(divider_s* answer, unsigned number, unsigned divide_by)
{
    if(divide_by == 0) 
    {
        printf("Divide by zero is not supported\n");
        return;
    }
        
    answer->quotient = quotient(number, divide_by);

    answer->remainder = modulo(number, divide_by);
    

    return;
}

int main()
{

    divider_s test = {.quotient = 0,.remainder = 0};
    divide(&test, 1029, 24);
    printf("%u\n", test.quotient);
    printf("%u\n", test.remainder);
}