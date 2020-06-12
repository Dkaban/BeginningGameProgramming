// THE PROBLEM
// ***************************
// This is a simple game project created by following along with the Unreal C++ Game Development Udemy Course
// https://www.udemy.com/course/unrealcourse/learn
// The game requires you to guess 3 numbers, given the sum and product of the 3 numbers.
// Difficulty scales up as more variation in the randomization of the numbers is introduced.
// Date: June 12th, 2020
// ***************************

#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	std::cout << "\n\nYou are a secret agent breaking into a " << Difficulty;
	std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << std::endl;//Want a blank line
	std::cout << "There are 3 numbers in the code";
	std::cout << "\nThe codes add up to " << CodeSum;
	std::cout << "\nThe product of the code is " << CodeProduct << std::endl;

	//Get the input from the user for their code guesses
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;
	std::cout << "You entered: " << GuessA << GuessB << GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//Check if guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\nYou Win!";
		return true;
	}
	else
	{
		std::cout << "\nYou Lose!";
		return false;
	}
}

int main()
{
	srand(time(NULL)); // create new random sequence based on time of day

	int LevelDifficulty = 1;
	int MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); //Clear any errors
		std::cin.ignore(); //Discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}

	std::cout << "\n *** Great work agent! You got all the files! Now get out of there! *** \n";
	return 0;
}
