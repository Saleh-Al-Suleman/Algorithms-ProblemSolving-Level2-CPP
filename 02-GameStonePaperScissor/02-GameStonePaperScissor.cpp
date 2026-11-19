// 02-GameStonePaperScissor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

// ==========================================
// Task 1: Game Enums & Data Structures
// ==========================================

enum enOption {
    Stone = 1,
    Paper = 2,
    Scissor = 3
};

enum enWinner {
    Player = 1,
    Bot = 2,
    Draw = 3
};

struct stRoundInfo
{
    int RoundNumber;
    enOption OptionPlayer;
    enOption OptionBot;
    enWinner Winner;
    string NameWinner;
};

struct stGameResult
{
    int GameRounds;
    int PlayerWinTimes;
    int BotWinTimes;
    int DrawTimes;

    enWinner GameWinner;
    string WinnerName;
};

// ==========================================
// Task 2: Input Validation & Random Choice Functions
// ==========================================
int RandomNumber(int From, int To)
{
    return (int) rand() % (To - From + 1) + From;
}

int ReadHowManyRounds()
{
    int NumberOfRounds = 0;
    do
    {
        cout << "Please enter how many number of rounds (from 1 to 10): ";
        cin >> NumberOfRounds;
    } while (NumberOfRounds < 1 || NumberOfRounds>10);
    return NumberOfRounds;
}

enOption ReadPlayerChoice()
{
    short Choice = 0;
    do
    {
        cout << "Please enter the choice [1]->Stone [2]->Paper [3]-> Scissor\nEnter here: ";
        cin >> Choice;
    } while (Choice < 1 || Choice>3);
    return (enOption)Choice;
}

enOption GetComputerChoice()
{
    return (enOption)RandomNumber(1, 3);
}

// ==========================================
// Task 3: Core Game Rules & Winner Logic
// ==========================================

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.OptionPlayer == RoundInfo.OptionBot)
        return enWinner::Draw;
    switch (RoundInfo.OptionPlayer)
    {
    case enOption::Paper:
        return (RoundInfo.OptionBot == enOption::Stone) ? enWinner::Player : enWinner::Bot;
    case enOption::Stone:
        return (RoundInfo.OptionBot == enOption::Scissor) ? enWinner::Player : enWinner::Bot;
    case enOption::Scissor:
        return (RoundInfo.OptionBot == enOption::Paper) ? enWinner::Player : enWinner::Bot;
    
    default: return enWinner::Draw;
    }
}

enWinner WhoWonTheGame(short PlayerWinTimes, short BotWinTimes)
{
    if (PlayerWinTimes > BotWinTimes)
        return enWinner::Player;
    else if (BotWinTimes > PlayerWinTimes)
        return enWinner::Bot;
    else
        return enWinner::Draw;
}

// ==========================================
// Task 4: Text Formatting & Screen Color Helpers
// ==========================================
string ChoiceName(enOption Option)
{
    string NamesOption[3] = { "Stone","Paper","Scissor" };
    return NamesOption[Option - 1];
}

string WinnerName(enWinner Winner)
{
    string NameWinner[3] = { "Player","Bot","Draw" };
    return NameWinner[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player:
        system("color 2F");
        break;
    case enWinner::Bot:
        system("color 4F");
        cout << "\a";
        break;
    case enWinner::Draw:
        system("color 6F");
        break;
    default:
        system("color 6F");
        break;
    }
}

int main()
{
    
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
