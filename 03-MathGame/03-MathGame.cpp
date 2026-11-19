// 03-MathGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

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
