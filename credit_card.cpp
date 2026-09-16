#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This program validates a credit card number using the Luhn algorithm.
// It checks the card length, accepted issuer prefixes, and whether the digits
// satisfy the checksum rule required for valid credit cards.

// Function declarations for the validation process.
vector<int> readCardNumber();
int getPrefix(const vector<int>& number, int k);
int getSize(const vector<int>& number);
int getDigit(int number);
int sumOfDoubleEvenPlace(const vector<int>& number);
int sumOfOddPlace(const vector<int>& number);
bool prefixMatched(const vector<int>& number);
bool isValid(const vector<int>& number);

// Reads the card number as a string, verifies that every character is a digit,
// and converts it into a vector of integers for processing.
vector<int> readCardNumber()
{
    string number;
    cout << "Enter credit card number: ";
    cin >> number;

    vector<int> cardDigits;
    for (char digit : number)
    {
        // Reject any non-numeric characters immediately.
        if (digit < '0' || digit > '9')
        {
            return {};
        }
        cardDigits.push_back(digit - '0');
    }

    return cardDigits;
}

// Returns the first k digits of the card number as a number.
// Example: prefix of 4 digits from [4, 5, 1, 2] becomes 4512.
int getPrefix(const vector<int>& number, int k)
{
    int prefix = 0;
    int digitsToRead = min(k, static_cast<int>(number.size()));

    for (int i = 0; i < digitsToRead; ++i)
    {
        prefix = prefix * 10 + number[i];
    }

    return prefix;
}

// Returns the total number of digits in the card.
int getSize(const vector<int>& number)
{
    return static_cast<int>(number.size());
}

// Handles double-digit results produced when a digit is doubled.
// For example, 9 * 2 = 18, so the function returns 1 + 8 = 9.
int getDigit(int number)
{
    return number < 10 ? number : number / 10 + number % 10;
}

// Implements the Luhn algorithm step for digits in even positions from the right.
// The digits are processed from the second-last digit backwards and doubled.
int sumOfDoubleEvenPlace(const vector<int>& number)
{
    int sum = 0;
    bool doubleDigit = true;  // Starting from the rightmost even-position digit.

    for (int i = getSize(number) - 2; i >= 0; --i)
    {
        if (doubleDigit)
        {
            sum += getDigit(number[i] * 2);
        }
        doubleDigit = !doubleDigit;
    }

    return sum;
}

// Sums the digits in odd positions from the right (the un-doubled positions).
int sumOfOddPlace(const vector<int>& number)
{
    int sum = 0;

    for (int i = getSize(number) - 1; i >= 0; i -= 2)
    {
        sum += number[i];
    }

    return sum;
}

// Checks whether the card number starts with a valid issuer prefix.
// Common major card prefixes: Visa = 4, MasterCard = 5, Amex = 37, Discover = 6.
bool prefixMatched(const vector<int>& number)
{
    return getPrefix(number, 1) == 4 ||
           getPrefix(number, 1) == 5 ||
           getPrefix(number, 2) == 37 ||
           getPrefix(number, 1) == 6;
}

// Confirms the card satisfies all standard validation rules.
// The card must have a length between 13 and 16 digits, match a valid prefix,
// and pass the Luhn checksum.
bool isValid(const vector<int>& number)
{
    int size = getSize(number);
    return size >= 13 && size <= 16 &&
           prefixMatched(number) &&
           (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
}

int main()
{
    // Read the card number and validate it.
    vector<int> number = readCardNumber();

    // Print whether the card is valid or invalid.
    cout << (isValid(number) ? "Valid" : "Invalid") << '\n';
    return 0;
}
