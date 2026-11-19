// 03-MathGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

// ==========================================
// Task 1: Game Enums & Data Structures
// ==========================================

enum enQuestionsLevel {
	EasyLevel = 1,
	MedLevel = 2,
	HardLevel = 3,
	Mix = 4
};

enum enOperationType {
	Add = 1,
	Sub = 2,
	Mult = 3,
	Div = 4,
	MixOp = 5
};

struct stQuestion {
	int number1;
	int number2;
	int CorrectAnswer;
	int PlayerAnswer;
	bool AnswerResult;
	enOperationType OperationType;
	enQuestionsLevel QuestionLevel;
};

struct stQuizz {
	stQuestion QuestionList[100];

	int numberOfQuestions = 0;
	int numberOfRightAnswers = 0;
	int numberOFWrongAnswers = 0;
	enQuestionsLevel QuestionLevel;
	enOperationType opType;

	bool isPass = false;
};

// ==========================================
// Task 2: Input Validation & Random Choice Functions
// ==========================================

int RandomNumber(int From, int To)
{
	return (int)rand() % (To - From + 1) + From;
}

short ReadHowManyQuestions()
{
	int NumberOfQuestions = 0;
	do
	{
		cout << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "| " << left << setw(55) << "Please enter how many questions you want [1 to 10]" << "|\n";
		cout << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "Enter here [1 -> 10]: ";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

	return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionLevel = 0;
	do
	{
		cout << "\n" << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "| " << left << setw(55) << "Select Questions Difficulty Level:" << "|\n";
		cout << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "| " << left << setw(55) << "[1] Easy    [2] Med    [3] Hard    [4] Mix" << "|\n";
		cout << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "Enter Level [1 -> 4]: ";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return (enQuestionsLevel)QuestionLevel;
}

enOperationType ReadOpType()
{
	short OpType = 0;
	do
	{
		cout << "\n" << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "| " << left << setw(55) << "Select Arithmetic Operation Type:" << "|\n";
		cout << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "| " << left << setw(55) << "[1] Add (+)   [2] Sub (-)   [3] Mul (*)   [4] Div (/)" << "|\n";
		cout << setw(16) << "" << "| " << left << setw(55) << "[5] Mix Operations" << "|\n";
		cout << setw(16) << "" << "+--------------------------------------------------------+\n";
		cout << setw(16) << "" << "Enter Operation [1 -> 5]: ";
		cin >> OpType;

	} while (OpType < 1 || OpType > 5);

	return (enOperationType)OpType;
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
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
