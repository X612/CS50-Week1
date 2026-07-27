#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long temp = number;
    long num = number;
    int digits = 1;
    while (temp / 10 > 0)
    {
        temp /= 10;
        digits++;
    }
    int x = 10;
    for (int i = 1; i <= digits - 2; i++)
    {
        num = num - (num % 10);
        num /= 10;
    }
    int first = num - (num % 10);
    first /= 10;
    int even = 0;
    int odd = 0;

    for (int i = 1; i <= digits; i++)
    {
        int k = number % 10;
        number /= 10;
        if (i % 2 == 0)
        {
            int product = k * 2;
            even += (product / 10) + (product % 10);
        }
        else
        {
            odd = odd + k;
        }

    }
    int sum = even + odd;
    if (sum % 10 == 0 && digits == 15 && (num == 34 || num == 37))
    {
        printf("AMEX\n");
    }
    else if (sum % 10 == 0 && digits == 16 &&
             (num == 51 || num == 52 || num == 53 || num == 54 || num == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (sum % 10 == 0 && (digits == 13 || digits == 16) && first == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
