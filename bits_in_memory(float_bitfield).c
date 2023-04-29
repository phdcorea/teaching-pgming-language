/*
    - Display bits of memory in float type.
    - Data structure: bit field in C
    - Compiler: gcc or g++
    - Ref: See IEEE754 that shows the format of float and double-type in memory.
*/

#include <stdio.h>
#include <string.h>

struct Bits // structure for bit field in C
{
    unsigned long mantissa : 23; // Mantissa: 23 bits
    unsigned long exponent  : 8; // Exponent: 8 bits
    unsigned long sign : 1;      // Sign bit: 1 bit
};

union uBits { // Using union data structure.
    int number;
    float f;
};

int main(void)
{
    float f_data;
    struct Bits bits;
    union uBits ubits; //union data structure
    
    f_data = 0.1f;
    
    memcpy(&bits, &f_data, 8); //copy from f to s in same size 32bits
    
    printf("--- bit field ---\n");
    printf("sign = %u\n",  bits.sign);
    printf("exp  = %u\n",  bits.exponent);
    printf("mant = %lu\n",  bits.mantissa);   

    /* Using shift operator */
    printf("--- shift >> and & operator ---\n");

    printf("sign = %u\n",  bits.sign & 0x1);
    printf("exponent: ");
    for(int i = 7; i >= 0; i--)
        printf("%d",  (bits.exponent >> i) & 0x1);
    printf("\n");

    printf("mantissa: ");
    for(int i = 22; i >=0; i--)
        printf("%d",  (bits.mantissa >> i) & 0x1);
    printf("\n");
    
    printf("--- Using union ---\n");
    ubits.f = 0.1f;
    
    for(int i = 31; i >= 0; i--)
        printf("%d",  (ubits.number >> i) & 0x1);
    printf("\n");


    return 0;
}