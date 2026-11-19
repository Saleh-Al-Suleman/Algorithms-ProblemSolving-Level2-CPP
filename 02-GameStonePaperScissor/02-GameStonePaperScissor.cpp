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
