#include <iostream>
using namespace std;
void WellComeNote(int Sum, int Difficulty, int Product, int Tries)
{
    if (Tries >= 3)
    {
        cout << "Welcome To the Game Secret Agent\n";
    }

    cout << "you're a super secret agent breaking into level " << Difficulty << " System\n";
    cout << "your're super hacker 2000 tell you the following information.....\n";
    cout << "\n+ There are three numbers in the code";
    cout << "\n+ The code multiply to give " << Product;
    cout << "\n+ The code add-up to " << Sum << endl;
}

bool PlayGame(int Difficulty, int Tries)
{

    int CodeA = rand() % Difficulty + Difficulty;

    int CodeB = rand() % Difficulty + Difficulty;

    int CodeC = rand() % Difficulty + Difficulty;

    int Sum = CodeA + CodeB + CodeC;

    int Product = CodeA * CodeB * CodeC;

    WellComeNote(Sum, Difficulty, Product, Tries);

    int GuessA;

    int GuessB;

    int GuessC;

    cin >> GuessA;

    cin >> GuessB;

    cin >> GuessC;

    int SumGuess;

    SumGuess = GuessA + GuessB + GuessC;

    int ProductGuess = GuessA * GuessB * GuessC;

    if (SumGuess == Sum && ProductGuess == Product)

    {

        cout << "\nGood Job Agent Keep Taking Out Files Before Alarm\n";

        return true;
    }

    else

    {

        if (SumGuess != Sum && ProductGuess != Product && Tries > 0)

        {

            cout << "\n***You entered the wrong code! Careful agent! Try again! You have following " << Tries << " Tries ***\n";
        }

        return false;
    }
}
int main()

{

    srand(time(NULL));

    int LevelDifficulty = 1;

    int MaxLevelDifficulty = 5;

    int Tries = 3;

    while (MaxLevelDifficulty >= LevelDifficulty && Tries >= 0)

    {

        bool bLevelDifficulty = PlayGame(LevelDifficulty, Tries);

        if (bLevelDifficulty)

        {

            LevelDifficulty++;
        }

        else

        {

            Tries--;
        }
    }

    if (Tries >= 0)

    {
        cout << "\nWow You'r The master HAcker";
    }

    else

    {

        cout << "\n you failed the GAME AND DIED HERE";
    }

    return 0;
}