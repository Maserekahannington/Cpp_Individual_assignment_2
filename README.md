# C++ Assignment 2

This repository contains solutions for the credit-card validation and multiple-choice question grading assignments.

## Credit Card Validation

Write a C++ program that determines whether a credit card number is valid.

## Requirements

The program must:

1. Read a credit card number from the user.
2. Accept card numbers containing between 13 and 16 digits.
3. Recognize card prefixes:
   - `4` for Visa
   - `5` for MasterCard
   - `37` for American Express
   - `6` for Discover
4. Use the Luhn checksum to validate the number.
5. Display `Valid` when all checks pass; otherwise, display `Invalid`.

## Luhn Check

Starting from the second digit from the right, double every other digit. If doubling produces a two-digit number, add its two digits. Add this result to the sum of the digits in the remaining positions. The card number is valid when the total is divisible by 10.

## Source File

The solution is implemented in `credit_card.cpp`.

## Compile and Run

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic credit_card.cpp -o credit_card.exe
.\credit_card.exe
```

## Example

Input:

```text
4242424242424242
```

Output:

```text
Valid
```

## Grading Multiple-Choice Questions

Write a program that grades the answers of eight students to ten multiple-choice questions. Each student's answers are stored in a row of a two-dimensional array, and the correct answers are stored in a one-dimensional key.

The program compares each answer with the corresponding answer in the key, counts the correct answers, and displays each student's score.

The supplied answer key is:

```text
D B D C C D A E A D
```

The solution is implemented in `grading_multiple_choice_questions.cpp`.

### Compile and Run

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic grading_multiple_choice_questions.cpp -o grading_multiple_choice_questions.exe
.\grading_multiple_choice_questions.exe
```

### Expected Scores

```text
Student 0 correct answers: 7
Student 1 correct answers: 6
Student 2 correct answers: 5
Student 3 correct answers: 4
Student 4 correct answers: 8
Student 5 correct answers: 7
Student 6 correct answers: 7
Student 7 correct answers: 7
```
