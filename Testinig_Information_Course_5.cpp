// Testinig_Information_Course_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
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

string ReadString(string Message)
{
    string EnteredText;
    
    while(true)
    {
        cout << Message;
        if (!getline(cin, EnteredText)) {
            return "";
        }
        if (!EnteredText.empty())
            return EnteredText;
    }
}

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

int ReadDigit()
{
    int digit = 0;
    do {
        cout << "Please enter digit for example [1]: ";
        cin >> digit;

        if (digit > 9)
            digit = -1;

    } while (digit <= -1);
    return digit;
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
    cout << "\nThe Number Inputed: [" << number << "] this is reversed order:\t[ ";
    int Remender = 0;
    while (number > 0)
    {
        Remender = number % 10;
        number /= 10;
        cout << Remender << " ";
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

//#problem 8: DigitFrequency
int CountTheDigit(int number, short digitToCheck)
{
    int count = 0, remender = 0;
    while (number > 0)
    {
        remender = number % 10;
        number /= 10;
        if (remender == digitToCheck)
            count++;
    }
    return count;
}

//#Problem 9: DigitFrequencyPrintAll
void PrintAllDigitsFrequency(int Number)
{
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = CountTheDigit(Number, i);
        if (DigitFrequency > 0)
        cout << "\tDigit [" << i << "] Frequency is " << DigitFrequency << " Time(s)\n";
    }
}

//#Problem 10: Print Digits in Order
void PrintDigitsinOrder(int Number)
{
    PrintDigits(ReverseNumber(Number));
}

//#Problem 11: PalendromeNumber
bool CheckIsPalindrome(int number)
{
    return number == ReverseNumber(number);
}

void PrintIsPalindromeThenNumber(int number)
{
    int reversedNumber = ReverseNumber(number);
    if (CheckIsPalindrome(number))
    {
        cout << "Yes, the number [" << number << "] is palindrome thats equal: (" << reversedNumber << ").\n";
    }
    else
    {
        cout << "No, the number [" << number << "] is NOT palindrome thats equal: (" << reversedNumber << ").\n";
    }
}

//#Problem 12: InvertedNumberPattern
void PrintInvertedNumber(int number)
{
    cout << "\n";
    for (int i = number; i > 0; i--)
    {
        cout << "\t";
        for (int j = i; j > 0; j--)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

//#Problem 13: NumberPattern
void PrintNumberPattern(int number)
{
    
    for (int i = 1; i <= number; i++)
    {
        cout << "\t";
        for (int j = 1; j <= i; j++)
        {
            cout << i <<" ";
        }
        cout << "\n";
    }
}

//#Problem 14: Inverted letter pattern
void PrintInvertedLetterPattern(int number)
{
    cout << "\n";
    for (int i = 65 + number - 1; i >= 65; i--)
    {
        cout << "\t";
        for (int j = i; j >= 65; j--)
        {
            cout << (char)i << " ";
        }
        cout << "\n";
    }
}

//#Problem 15: Letter Pattern
void PrintLetterPattern(int number)
{
    int NCharAscii = number + 65 - 1;
    for (int i = 65; i <= NCharAscii; i++)
    {
        cout << "\t";
        for (int j = 65; j <= i; j++)
        {
            cout << (char)i << " ";
        }
        cout << "\n";
    }
}

//#Problem 16: PrintAllWordsFromAAA_To_ZZZ:
void PrintAllWordFromAAAToZZZ()
{
    const int WordsPerLine = 13;

    for (int i = 65; i <= 90; i++)
    {
        cout << "\t====================================\n";
        cout << "\t\tWORDS STARTING WITH '" << (char)i << "'\n";
        cout << "\t====================================\n\n";

        int wordCount = 0;

        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                cout << (char)i << (char)j << (char)k << setw(6);

                wordCount++;

                if (wordCount % WordsPerLine == 0)
                cout << "\n";
            }
            cout << "\n";
        }

    }
}

//#Problem 17: Guess A 3-Letters Password
bool CheckPassword(string Password)
{
    int counter = 0;
    string word = "";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word += (char)i;
                word += (char)j;
                word += (char)k;
                
                counter++;
                cout << "Trial [" << counter << "]: " << word << "\n";

                if (word == Password)
                {
                    cout << "\nPassword is " << word << "\n";
                    cout << "Found after " << counter << " Trial(s)\n";

                    return true;
                }
                word = "";
            }
        }
    }
    return false;
}

//#Problem 18: Encrypt, Decrypt Text
string EncryptText(string Text, short KeyEncrypt)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + KeyEncrypt);
    }
    return Text;
}

//# Decrypt Text
string DecryptText(string TextEncrypted, short KeyDecrypt)
{
    for (int i = 0; i < TextEncrypted.length(); i++)
    {
        TextEncrypted[i] = char((int)TextEncrypted[i] - KeyDecrypt);
    }
    return TextEncrypted;
}

//#Problem 19: Random3NumbersFrom1To10
int RandomNumber(int From, int To)
{
    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

//#Problem 20: Random_Small_Capital_Letter
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialLetter = 3, Digit = 4 };

char GetRandomCharacter(enCharType charType)
{
    switch (charType)
    {
    case enCharType::SmallLetter:
        return (char)RandomNumber(97, 122);

    case enCharType::CapitalLetter:
        return (char)RandomNumber(65, 90);

    case enCharType::SpecialLetter:
        return (char)RandomNumber(33, 47);

    case enCharType::Digit:
        return (char)RandomNumber(48, 57);

    default:
            return 'N';
    }
}

//#Problem 21: GenerateKeys
string GeneratePacetKey(short countDigit)
{
    string PacetKey;

    for (int i = 1; i <= countDigit; i++)
    {
        PacetKey += GetRandomCharacter(enCharType::CapitalLetter);
    }
    return PacetKey;
}

string GenerateOneKey(short countPacetKey = 4)
{
    string key = "";
    for (int i = 1; i <= countPacetKey; i++)
    {
        key += GeneratePacetKey(4);
        if (i < countPacetKey)
            key += '-';
    }
    return key;
}
void GenerateKeys(short NumberOfKeys)
{
    cout << "\n";
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "]: " << GenerateOneKey() << "\n";
    }
}

//#Problem 22: Repeated Elements Count In Array
void FillElementsOfArray(int Array[100], short length)
{
    for (short i = 0; i < length; i++)
    {
        cout << "Please Enter Element [" << i + 1 << "]: ";
        cin >> Array[i];
    }
}

void PrintArrayElements(int Array[100],short length)
{
    cout << "\nArray Elements: ";
    for (short i = 0; i < length; i++)
    {
        cout << Array[i]<<" ";
    }
    cout << "\n\n";
}

short CountRepeatedElementInArray(int Array[100], short length, int number)
{
    short int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (Array[i] == number)
            counter++;
    }
    return counter;
}

short ReadLengthArrayOf100()
{
    short length = 0;
    do 
    {
        length = ReadPositiveNumber("Please Enter How Numbers You Want to Enter: ");
        if (length > 100)
        {
            cout << "\n\tERROR\nEnter Number Under (100)\n";
        }
    } while (length > 100);
 
    return length;
}


int main()
{
    srand((unsigned)time(NULL));

    //// this the call with Problem one #Multipliaction
    /*PrintMultipliactionTable();*/

    //// this the call with Problem two #PrintPrimeNumberFrom1ToN
    /*PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number: "));*/

    //// this the call with Problem Three #PrintPerfectNumberOrNot
    /*PrintIsPerfectNumber(ReadPositiveNumber("Please enter a positive number: "));*/

    //// this the call with problem four #PrintPerfectnumbersFromOneToN
    /*PrintPerfectNumbersFromOneToN(ReadPositiveNumber("Please enter a positive number: "))*/

    ////this the call with Problem 5 #PrintDigits_in_aReversed Order
    //PrintDigits(ReadPositiveNumber("Please enter a number: "));

    ////this the call with problem 6 #SumOfDigits
    /*int number = ReadPositiveNumber("Please enter a number: ");
    cout << "\n\tSum of digits: " << CalcDigitsOfSumNumbers(number);
    cout << "\n-------------------------------------------------------------------" << endl;*/

    //// this the call with Problem 7 #ReverseNumber
   /* int numtoReverse = ReadPositiveNumber("Please enter a number: ");
    cout << "This is the reverse number [" << numtoReverse << "] is equal: [" << ReverseNumber(numtoReverse) << "].\n";
    cout << "-------------------------------------------------------------\n";*/

    ////this the call with problem 8 #DigitFrecuency
   /* int NumberToCount = ReadPositiveNumber("Please enter number for example [11223344]: ");
    int digitToCheck = ReadDigit();
    cout << "\nThe Number [" << NumberToCount << "] has the digit [" << digitToCheck << "] Frequency is (";
    cout << CountTheDigit(NumberToCount, digitToCheck) << ") Times(s)..." << endl;
    cout << "-------------------------------------------------------------\n";*/

    ////this the call with problem 9 #DigitFrecuencyPrintAll
    /*cout << "----------------------------------------------\n";
    PrintAllDigitsFrequency(ReadPositiveNumber("Please enter a number: "));
    cout << "----------------------------------------------\n";*/

    // this the call with problem 10 #PrintDigits_in_Order
    /*cout << "----------------------------------------------\n";
    PrintDigitsinOrder(ReadPositiveNumber("Please enter a number: "));
    cout << "----------------------------------------------\n";*/
    
    // this the call with problem 11 #PalendromeNumber
    /*cout << "\n----------------------------------------------\n";
    PrintIsPalindromeThenNumber(ReadPositiveNumber("Please enter a number: "));
    cout << "----------------------------------------------\n";*/

    // this the call with problem 12 #InvertedNumberPattern
    /*cout << "\n----------------------------------------------\n";
    PrintInvertedNumber(ReadPositiveNumber("Please enter a number: "));
    cout << "\n----------------------------------------------\n";*/

    // this the call with problem 13 #NumberPattern
    /*cout << "\n----------------------------------------------\n\n";
    PrintNumberPattern(ReadPositiveNumber("Please enter a number: "));
    cout << "\n----------------------------------------------\n";*/

    // this the call with problem 14 #InvertedLetterpPattern
    /*cout << "\n----------------------------------------------\n\n";
    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a number: "));
    cout << "\n----------------------------------------------\n";*/

    // this the call with problem 15 #PrintLetterPattern
    /*cout << "\n----------------------------------------------\n\n";
    PrintLetterPattern(ReadPositiveNumber("Please enter a number: "));
    cout << "\n----------------------------------------------\n";*/
    
    // this the call with problem 16 #PrintAllWordFromAAAToZZZ
    
    //PrintAllWordFromAAAToZZZ();
    //

    ////this the call with problem 17 #Guess A 3-Letters Password
    /*cout << "\n----------------------------------------------\n";
    CheckPassword(ReadString("Enter your Password: "));
    cout << "\n----------------------------------------------\n";*/


    // this the call with problem 18 #Encrypt, Decrypt Text
    /*cout << "\n----------------------------------------------\n";
    string password = "Admin",PassEncrypted = EncryptText(password, 3), PassDecrypted = DecryptText(PassEncrypted,3);
    cout << "Before Encrypting: " << password << endl;
    cout << "After Encrypting: " << PassEncrypted;
    cout << "\nAfter Decrypting: " << PassDecrypted;
    cout << "\n----------------------------------------------\n";*/

    // this the call with problem 19: Randome Number From 1 To 10
    /*cout << "====================================\n";
    cout << "\t[" << RandomNumber(1, 10);
    cout << "\t" << RandomNumber(1, 10);
    cout << "\t" << RandomNumber(1, 10);
    cout << "]\n====================================\n";*/

    //this the call with problem 20: Random_Small_Capital_Letter
    /*cout << "====================================\n";
    cout << "Random Capital Letter: " << GetRandomCharacter(enCharType::CapitalLetter) << "\n";
    cout << "Random Small Letter: " << GetRandomCharacter(enCharType::SmallLetter) << "\n";
    cout << "Random Special Letter: " << GetRandomCharacter(enCharType::SpecialLetter) << "\n";
    cout << "Random Digit Letter: " << GetRandomCharacter(enCharType::Digit) << "\n";
    cout << "====================================\n";*/

    //this the call with problem 21: GenerateKeys
    cout << "\n================== [KEYS] =========================\n\n";
    int NumOfKeys = ReadPositiveNumber("Please enter number of keys: ");
    GenerateKeys(NumOfKeys);
    cout << "\n====================================================\n";

    //Only Testing
    // 
    ////this the call with problem 22: Repeated Elements Count In Array
    //cout << "\n================== PROBLEM 22 =========================\n\n";
    //int numOfInput = ReadLengthArrayOf100();
    //int Array[100];

    //FillElementsOfArray(Array, numOfInput);
    //PrintArrayElements(Array, numOfInput);

    //int numberOfCount = ReadPositiveNumber("Please Enter The Number You Want to Count: ");

    //cout << "\nThe number (" << numberOfCount << ") was repated: " << CountRepeatedElementInArray(Array, numOfInput, numberOfCount) << " time(s).\n";

    //cout << "\n========================================================\n";
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
