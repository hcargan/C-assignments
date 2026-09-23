A credit card has a unique number used for identification and validation. IBM engineer Hans Peter Luhn created an international algorithm to generate and validate these numbers.

Credit card numbers typically range from 13 to 16 digits. A valid card must begin with specific prefixes: '4' for Visa, '5' for MasterCard, '37' for American Express, or '6' for Discover. The Luhn check (Mod 10 algorithm) works as follows:

1. Double every second digit from right to left. If doubling yields a two-digit number, sum its digits to get a single digit.
2. Add all single-digit results from Step 1.
3. Add all digits in odd positions from right to left.
4. Add the totals from Steps 2 and 3.
5. If the total sum is divisible by 10, the card is valid; otherwise, it is invalid.

The C++ program implements this logic using the following functions:

int getSize(long long d): Counts and returns the total number of digits in an integer using division by 10, accounting for 0 as a single digit.

int getDigit(int number): Returns single-digit numbers as-is. For doubled numbers greater than 9, it splits and sums the tens and ones digits (e.g., 14 becomes 1 + 4 = 5).

int sumOfOddPlace(long long number): Sums all digits in odd positions starting from the rightmost digit, jumping two places at a time.

int sumOfDoubleEvenPlace(long long number): Processes digits in even positions (starting from position 2 from the right), doubles them, passes them to getDigit(), and returns their cumulative sum.

long long getPrefix(long long number, int k): Extracts and returns the first k digits of a number by dividing out the remaining trailing digits.

bool prefixMatched(long long number, int d): Determines the length of prefix d using getSize(), extracts that prefix from the card number using getPrefix(), and checks if they match.

bool isValid(long long number): Combines all rules. It checks if the length is between 13 and 16 digits, verifies card prefixes, and computes the Luhn sum. Returns true if all checks pass and the sum is divisible by 10.

In the main function, the user inputs a card number, which is passed to isValid(). The program then outputs whether the entered card number is valid or invalid.