// Testinig_Information_Course_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
int main()
{
    PrintMultipliactionTable();
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
