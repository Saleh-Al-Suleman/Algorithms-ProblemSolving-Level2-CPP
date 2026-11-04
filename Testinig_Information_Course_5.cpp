// Testinig_Information_Course_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

// #problem1: 
// Multiplication Table 1 to 10

void PrintHeadTable()
{
    cout << "\n\t\t\t Multiplication Table 1 to 10\n";
    for (short i = 1; i <= 10; i++)
    {
        cout << "\t" << i;
    }
    cout << "\n";
    cout << "-----------------------------------------------------------------------------------\n";
}
void PrintOneRow(int number)
{
    if (number != 10)
    cout << number << "     | ";
    else
        cout << number << "    | ";
    for (int i = 1; i <= 10; i++)
    {
        cout << i * number << "\t";
    }
    cout << "\n";
}
void PrintMultipliactionTable()
{
    PrintHeadTable();
    for (int i = 1; i <= 10; i++)
    {
        PrintOneRow(i);
    }
    cout << "-----------------------------------------------------------------------------------\n";
}

// #Problem2: 
// Print All Prime Numbers From 1 to N

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Message)
{
    int num = 0;
    do
    {
        cout << Message;
        cin >> num;
    } while (num <= 0);
    return num;
}

enPrimeNotPrime CheckPrime(int Number)
{
    int m = round(Number / 2);
    for (int Counter = 2; Counter <= m; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbersFrom1ToN(int EndNumber_N)
{
    cout << "\nPrime Numbers From " << 1 << " To " << EndNumber_N << " are:\n";
    bool isFirstInLine = true;

    short counter = 0;
    for (int i = 1; i <= EndNumber_N; i++)
    {
        if (CheckPrime(i) == enPrimeNotPrime::Prime)
        {
            if (isFirstInLine)
            {
                cout << "[";
                isFirstInLine = false;
            }
            else
            {
                cout << ", ";
            }
            cout << right << setw(5) << i;
            counter++;
            if (counter == 5)
            {
                cout << "]\n";
                counter = 0;
                isFirstInLine = true;
            }
        }
    }
    if (counter > 0)
        cout << "]\n";
}

// #Problem3: 
// Print is the Number Perfect or Not

bool isPerfect(int Number)
{
    int sum = 0;
    for (int i = 1; i <= Number / 2; i++)
    {
        if (Number % i == 0)
        {
            sum += i;
        }
    }

    return Number == sum;
}

void PrintIsPerfectNumber(int Number)
{
    cout << "\t";
    if (isPerfect(Number))
    {
        cout << Number << " Is Prefect Number" << endl;
    }
    else
    {
        cout << Number << " Is Not Prefect Number" << endl;
    }
}

// #Problem 4:
// Print Perfect Numbers From 1 to N

enum enCheckPerfectNotPerfectNumber { Perfect = 1, NotPerfect = 2 };

enCheckPerfectNotPerfectNumber CheckPerfectNotPrefectNumber(int Number)
{
    int sum = 0;
    for (int i = 1; i <= Number / 2; i++)
    {
        if (Number % i == 0)
            sum += i;
    }
    if (sum == Number)
        return enCheckPerfectNotPerfectNumber::Perfect;
    else
        return enCheckPerfectNotPerfectNumber::NotPerfect;
}

void PrintPerfectNumbersFromOneToN(int Number_End)
{
    cout << "\nInputed Number: [" << Number_End << "] -> the Perfect Number(s) From 1 to [" << Number_End << "].\n";

    for (int i = 1; i <= Number_End; i++)
    {
        if (CheckPerfectNotPrefectNumber(i) == enCheckPerfectNotPerfectNumber::Perfect)
            cout << "\t" << i << endl;
    }

    cout << "---------------------------------------------\n";
}

//#Problem 5: Print Digits in a Reversed Order
void PrintDigits(int number)
{
    cout << "\nThe Number Inputed: [" << number << "] this is reversed order:\t[";
    int Remender = 0;
    while (number > 0)
    {
        Remender = number % 10;
        number /= 10;
        cout << Remender;
    }
    cout << "]\n---------------------------------------------------------\n";
}

//#Problem 6: Sum Of Digits
int CalcDigitsOfSumNumbers(int number)
{
    int Remender = 0, sum = 0;
    while (number > 0)
    {
        Remender = number % 10;
        number = number / 10;
        sum += Remender;
    }
    return sum;
}

//#Problem 7: ReverseNumber
int ReverseNumber(int number)
{
    int remender = 0, newNum = 0;

    while (number > 0)
    {
        remender = number % 10;
        number /= 10;
        newNum = newNum * 10 + remender;
    }
    return newNum;
}

int main()
{
    //// this the call with Problem one #Multipliaction
    //PrintMultipliactionTable();

    //// this the call with Problem two #PrintPrimeNumberFrom1ToN
    //PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number: "));

    //// this the call with Problem Three #PrintPerfectNumberOrNot
    //PrintIsPerfectNumber(ReadPositiveNumber("Please enter a positive number: "));

    //// this the call with problem four #PrintPerfectnumbersFromOneToN
    //PrintPerfectNumbersFromOneToN(ReadPositiveNumber("Please enter a positive number: "));

    ////this the call with Problem 5 #PrintDigits_in_aReversed Order
    //PrintDigits(ReadPositiveNumber("Please enter a number: "));

    ////this the call with problem 6 #SumOfDigits
    //int number = ReadPositiveNumber("Please enter a number: ");
    //cout << "\n\tSum of digits: " << CalcDigitsOfSumNumbers(number);
    //cout << "\n-------------------------------------------------------------------" << endl;

    // this the call with Problem 7 #ReverseNumber
    int numtoReverse = ReadPositiveNumber("Please enter a number: ");
    cout << "This is the reverse number [" << numtoReverse << "] is equal: [" << ReverseNumber(numtoReverse) << "].\n";
    cout << "-------------------------------------------------------------\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
