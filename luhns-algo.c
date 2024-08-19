#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Calculates the check digit of a credit card number
 * according to Luhn's algorithm.
 *
 * @param n The credit card number.
 * @return The calculated sum used for validation.
 */
int luhns_algo(long n);

/**
 * Checks whether the credit card number begins with one of the specified prefixes.
 *
 * @param number The credit card number.
 * @param prefixes A list of permitted prefixes (e.g. “34”, “37”).
 * @param size The number of prefixes in the list.
 * @return true if the credit card number begins with one of the prefixes, otherwise false.
 */
bool starts_with(long number, const char *prefixes[], int size);

/**
 * Counts the number of digits in a credit card number.
 *
 * @param num The credit card number.
 * @return The number of digits.
 */
int count_numbers(long num);

/**
 * Validates the credit card number and determines the card type.
 * Supported card types: AMEX, VISA, MASTERCARD.
 *
 * @param number The credit card number.
 * @return The card type (e.g. “AMEX”, “VISA”, “MASTERCARD”) or “INVALID” if the number is invalid.
 */
const char* validate_card(long number);

/**
 * The entry point of the program. Prompts the user to enter a credit card number,
 * validates the number and displays the card type.
 */
int main()
{
    // Prompt with explanation
    printf("Dieses Programm validiert Kreditkartennummern.\n");
    printf("Unterstützte Karten: AMEX, VISA und MASTERCARD.\n");
    printf("Bitte geben Sie eine Kreditkartennummer zur Validierung ein.\n");

    long number;

    // Prompt until the user enters a valid (positive) credit card number
    do
    {
        printf("Number: ");
        scanf("%ld", &number);
    }
    while (number < 1);

    // Validates the credit card number and outputs the result
    const char* card_type = validate_card(number);
    printf("%s\n", card_type);

    return 0;
}

int luhns_algo(long n)
{
    int digit;
    int pre_sum;
    int sum = 0;
    int position = 0;

    // Iteration over the digits of the credit card number
    while (n > 0)
    {
        // Extracts the last digit
        digit = n % 10;
        n = n / 10;

        // Every second digit is doubled (counted from the right)
        if (position % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            pre_sum = digit * 2;

            // If the double is greater than 9, the sum of the digits is formed
            if (pre_sum > 9)
            {
                sum += pre_sum % 10;
                sum += pre_sum / 10;
            }
            else
            {
                sum += pre_sum;
            }
        }
        position++;
    }
    return sum;
}

bool starts_with(long number, const char *prefixes[], int size)
{
    char number_str[20];

    // Converts the credit card number into a character string
    sprintf(number_str, "%li", number);

    // Checks whether the credit card number matches one of the prefixes
    for (int i = 0; i < size; i++)
    {
        if (strncmp(number_str, prefixes[i], strlen(prefixes[i])) == 0)
        {
            return true;
        }
    }

    return false;
}

int count_numbers(long num)
{
    int counter = 0;

    // Counts the digits by repeatedly dividing the number by 10
    while (num != 0)
    {
        num = num / 10;
        counter++;
    }

    return counter;
}

const char* validate_card(long number)
{
    // Supported credit card prefixes
    const char *amex_prefixes[] = {"34", "37"};
    const char *mastercard_prefixes[] = {"51", "52", "53", "54", "55"};
    const char *visa_prefixes[] = {"4"};

    // Calculation of the check digit and number of digits
    int sum_algo = luhns_algo(number);
    int digits = count_numbers(number);

    // Check digit validation
    if (sum_algo % 10 != 0)
    {
        return "INVALID CHECKSUM";
    }

    // Checking the prefixes and the card number length
    if (starts_with(number, amex_prefixes, 2) && digits == 15)
    {
        return "AMEX";
    }
    else if (starts_with(number, mastercard_prefixes, 5) && digits == 16)
    {
        return "MASTERCARD";
    }
    else if (starts_with(number, visa_prefixes, 1) && (digits == 13 || digits == 16))
    {
        return "VISA";
    }
    else
    {
        return "INVALID PREFIX OR LENGTH";
    }
}