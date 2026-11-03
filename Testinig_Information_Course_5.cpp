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

int main()
{
    // this the call with Problem one #Multipliaction
    //PrintMultipliactionTable();

    // this the call with Problem two #PrintPrimeNumberFrom1ToN
    //PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number: "));

    // this the call with Problem Three #PrintPerfectNumberOrNot
    PrintIsPerfectNumber(ReadPositiveNumber("Please enter a positive number: "));
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
