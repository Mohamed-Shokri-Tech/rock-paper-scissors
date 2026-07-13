#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

enum enGameTypes { Stone = 1, Paper = 2, Scissor = 3 };

enum enRoundResult { PlayerWin = 1, ComputerWin = 2, Draw = 3 };

int RandomNumber(int From, int To)
{
	int randNum;
	randNum = rand() % (To - From + 1) + From;

	return randNum;
}

enGameTypes PlayerChoice()
{
	int PlayerChoice;

	do
	{
		cout << "Your Choice : [1]Stone, [2]Paper, [3]Scissor ? \n";
		cin >> PlayerChoice;
	} while (PlayerChoice < 1 || PlayerChoice>3);


	if (PlayerChoice == 1)
		return enGameTypes::Stone;
	else if (PlayerChoice == 2)
		return enGameTypes::Paper;
	else
		return enGameTypes::Scissor;

}

enGameTypes ComputerChoice()
{
	int ComputerChoice;
	ComputerChoice = RandomNumber(1, 3);

	if (ComputerChoice == 1)
		return enGameTypes::Stone;
	else if (ComputerChoice == 2)
		return enGameTypes::Paper;
	else
		return enGameTypes::Scissor;

}

enRoundResult RoundResult(enGameTypes PlayerChoice,enGameTypes ComputerChoice)
{
	if (PlayerChoice == ComputerChoice)
		return enRoundResult::Draw;

	else if (PlayerChoice == enGameTypes::Stone && ComputerChoice == enGameTypes::Paper)
		return enRoundResult::ComputerWin;

	else if (PlayerChoice == enGameTypes::Stone && ComputerChoice == enGameTypes::Scissor)
		return enRoundResult::PlayerWin;

	else if (PlayerChoice == enGameTypes::Paper && ComputerChoice == enGameTypes::Stone)
		return enRoundResult::PlayerWin;

	else if (PlayerChoice == enGameTypes::Paper && ComputerChoice == enGameTypes::Scissor)
		return enRoundResult::ComputerWin;

	else if (PlayerChoice == enGameTypes::Scissor && ComputerChoice == enGameTypes::Stone)
		return enRoundResult::ComputerWin;

	else if (PlayerChoice == enGameTypes::Scissor && ComputerChoice == enGameTypes::Paper)
		return enRoundResult::PlayerWin;
	else
		return enRoundResult::Draw;

}

string GameName(enGameTypes GameName)
{
	if (GameName == enGameTypes::Stone)
		return "Stone";
	else if (GameName == enGameTypes::Paper)
		return "Paper";
	else if (GameName == enGameTypes::Scissor)
		return "Scissor";

	return "Scissor";
}

string WineerName(enRoundResult Ruselt)
{
	if (Ruselt == enRoundResult::ComputerWin)
		return "[Computer Winner]";
	else if (Ruselt == enRoundResult::PlayerWin)
		return "[Player Winner]";
	else if (Ruselt == enRoundResult::Draw)
		return "[Non Winner]";

	return "[Non Winner]";
}

void PrintRoundResult(enGameTypes PlayerChoice, enGameTypes ComputerChoice, enRoundResult RoundResult,int RoundNumber)
{
	cout << "\n\n-----------------------------Round [" << RoundNumber << "]-----------------------------\n";
	cout << "Player Choice : " << GameName(PlayerChoice)  << endl;
	cout << "Computer Choice : " << GameName(ComputerChoice) << endl;
	cout << "Round Winner : " << WineerName(RoundResult) << endl;

	if(RoundResult== enRoundResult::PlayerWin)
	system("color 2F");
	else if(RoundResult == enRoundResult::ComputerWin)
	system("color 4F");
	else if (RoundResult == enRoundResult::Draw)
	system("color 6F");
	
	cout << "-------------------------------------------------------------------------------\n";
}

void UpdateScore(enRoundResult Result, int& ComputerWin, int& PlayerWin, int& Draw)
{


	if (Result == enRoundResult::ComputerWin)
		ComputerWin++;
	else if (Result == enRoundResult::PlayerWin)
		PlayerWin++;
	else if (Result == enRoundResult::Draw)
		Draw++;


}

void GameOver(int RoundNumbers, int Computerwin, int Playerwin, int Draw)
{

	cout << "\n\n--------------------------------------------\n";
	cout << "            ------Game Over ------          \n";
	cout << "--------------------------------------------\n\n";
	cout << "          ------ [Game Ruselt] ------         \n";
	cout << "Game Round : " << RoundNumbers << endl;
	cout << "Player Won Times : " << Playerwin << endl;
	cout << "Computer Won Times : " << Computerwin << endl;
	cout << "Draw Times : " << Draw << endl;


	if (Computerwin > Playerwin)
	{
		cout << "Final Winner : Computer \n";
		cout << system("color 4F");
	}
	else if (Playerwin > Computerwin)
	{
		cout << "Final Winner : Player \n";
		cout << system("color 2F");
	}
	else
	{
		cout << "Final Winner : non \n";
		cout << system("color 6F");
	}

}

void RoundPlay(int RoundNumbers)
{
	int Draw = 0;
	int PlayerWin = 0;
	int ComputerWin = 0;

	for (int i = 1; i <= RoundNumbers; i++)
	{
		enGameTypes Player = PlayerChoice();

		enGameTypes Computer = ComputerChoice();

		enRoundResult Result = RoundResult(Player, Computer);

		PrintRoundResult(Player, Computer, Result,i);

		UpdateScore(Result, ComputerWin, PlayerWin, Draw);

	}

	GameOver(RoundNumbers, ComputerWin, PlayerWin, Draw);
}



int main()
{
	srand((unsigned)time(NULL));

	char AgainPlay = 'y';

	while (AgainPlay == 'y')
	{
		int RoundNumbers = ReadPositiveNumber("How Many Rounds You want Play ?");

		RoundPlay(RoundNumbers);

		cout << "You Want Play Again [y] or [n]?";
		cin >> AgainPlay;

		system("cls");
	}
	

	return 0;
}