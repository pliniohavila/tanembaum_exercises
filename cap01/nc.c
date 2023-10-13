#include <stdio.h>
#include "nc.h"

Complex     sum(Complex*, Complex*);
Complex     sub(Complex*, Complex*);
Complex     multiply(Complex*, Complex*);

int     main(void)
{
    Complex     nc1;
    Complex     nc2;
    Complex     sum_result;
    Complex     sub_result;
    Complex     multiply_result;

    printf("Sum, sub e multiply complex numbers\n");
    printf("Number format: [real][operator][imaginary]\n");
    printf("Put zero to part this no exist\n");
    printf("First number: ");
    scanf("%f %f", &nc1.real, &nc1.imaginary);
    fflush(stdin);
    printf("Second number: ");
    scanf("%f %f", &nc2.real, &nc2.imaginary);
    printf("\n");
    sum_result = sum(&nc1, &nc2);
    sub_result = sub(&nc1, &nc2);
    multiply_result = multiply(&nc1, &nc2);
    printf("SUM: (%.1f)+(%.1f)i\n", sum_result.real, sum_result.imaginary);
    printf("SUB: (%.1f)+(%.1f)i\n", sub_result.real, sub_result.imaginary);
    printf("MULTIPLY: (%.1f)+(%.1f)i\n", multiply_result.real, multiply_result.imaginary);

    return (0);
}

Complex     sum(Complex *nc1, Complex *nc2)
{
    Complex     result;

    result.real = nc1->real + nc2->real;
    result.imaginary = nc1->imaginary + nc2->imaginary;

    return (result);
}

Complex     sub(Complex *nc1, Complex *nc2)
{
    Complex     result;

    result.real = nc1->real - nc2->real;
    result.imaginary = nc1->imaginary - nc2->imaginary;

    return (result);
}

Complex     multiply(Complex *nc1, Complex *nc2)
{
    Complex     result;

    result.real = (nc1->real * nc2->real) - (nc1->imaginary * nc2->imaginary);
    result.imaginary = (nc1->real * nc2->imaginary) + (nc1->imaginary * nc2->real);
    
    return (result);
}
// gcc nc.c -o nc -g; .\nc