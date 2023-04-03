/* A simple calculator program to perform basic mathematical operations using bitwise operators */

#include <stdio.h>

/* Function to perform addition operation using bitwise operator */
int add(int a, int b)
{
    int carry;
    while (b != 0)
    {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

/* Function to perform subtraction operation using bitwise operator */
int subtract(int a, int b)
{
    while (b != 0)
    {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    return a;
}

/* Function to perform multiplication operation using bitwise operator */
int multiply(int a, int b)
{
    int result = 0;
    while (b != 0)
    {
        if (b & 1)
        {
            result = add(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

/* Function to perform division operation using bitwise operator */
int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: division by zero\n");
        return -1;
    }
    int quotient = 0;
    int remainder = 0;
    int i = 31;
    while (i >= 0)
    {
        remainder <<= 1;
        remainder |= (a >> i) & 1;
        if (remainder >= b)
        {
            remainder = subtract(remainder, b);
            quotient |= 1 << i;
        }
        i = subtract(i, 1);
    }
    return quotient;
}

int main()
{
    int a, b;
    /* Input two numbers from the user */
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    /* Display the results of the mathematical operations */
    printf("Sum: %d\n", add(a, b));
    printf("Difference: %d\n", subtract(a, b));
    printf("Product: %d\n", multiply(a, b));
    printf("Quotient: %d\n", divide(a, b));
    printf("Division Remainder: %d\n", subtract(a, multiply(b, divide(a, b)))); // Compute the remainder of division

    return 0;
}