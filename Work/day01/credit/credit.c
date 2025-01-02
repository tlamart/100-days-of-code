#include <cs50.h>
#include <stdio.h>

int check_card_number(long card_number);
int even_digit(int n);
int get_first_digit(long n);
int get_second_digit(long n);
int get_length(long n);
void print_result(int length, int validity, int first, int second);

int main(void)
{
    long card_number = get_long("Number : ");
    int card_number_length = get_length(card_number);
    int checksum_validity = check_card_number(card_number);
    int first_digit = get_first_digit(card_number);
    int second_digit = get_second_digit(card_number);
    print_result(card_number_length, checksum_validity, first_digit, second_digit);
}

int get_length(long n)
{
    int i = 0;
    while (n)
    {
        i++;
        n /= 10;
    }
    return i;
}

int check_card_number(long card_number)
{
    int sum_of_even_digit = 0;
    int sum_of_odd_digit = 0;
    int total;
    int valid = card_number <= 0;

    while (card_number)
    {
        sum_of_odd_digit += card_number % 10;
        card_number /= 10;
        sum_of_even_digit += even_digit(2 * (card_number % 10));
        card_number /= 10;
    }
    total = sum_of_even_digit + sum_of_odd_digit;
    if (valid || total % 10 != 0)
        return 1;
    else
        return 0;
}

int even_digit(int n)
{
    if (n < 10)
        return n;
    else
        return (n % 10 + even_digit(n / 10));
}

int get_first_digit(long n)
{
    while (n > 10)
        n /= 10;
    return n % 10;
}

int get_second_digit(long n)
{
    while (n > 100)
        n /= 10;
    return n % 10;
}

void print_result(int length, int validity, int first, int second)
{
    if (validity == 1 || length < 13)
        printf("INVALID\n");
    else if ((length == 13 || length == 16) && first == 4)
        printf("VISA\n");
    else if (length == 16 && first == 5 && second > 0 && second <= 5)
        printf("MASTERCARD\n");
    else if (length == 15 && first == 3 && (second == 4 || second == 7))
        printf("AMEX\n");
    else
        printf("INVALID\n");
}
