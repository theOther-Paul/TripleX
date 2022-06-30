#include <iostream>
#include <ctime>
#include <windows.h>
#include <thread>
#include <iomanip>

void PrintGameCover()
{
    system("cls");
    std::cout << "\n     0000             0000        7777777777777777/========___________";
    std::cout << "\n   00000000         00000000      7777^^^^^^^7777/ || ||   ___________";
    std::cout << "\n  000    000       000    000     777       7777/=========//";
    std::cout << "\n 000      000     000      000             7777// ((     //";
    std::cout << "\n0000      0000   0000      0000           7777//   \\   //";
    std::cout << "\n0000      0000   0000      0000          7777//========//";
    std::cout << "\n0000      0000   0000      0000         7777";
    std::cout << "\n0000      0000   0000      0000        7777";
    std::cout << "\n 000      000     000      000        7777";
    std::cout << "\n  000    000       000    000       77777";
    std::cout << "\n   00000000         00000000       7777777";
    std::cout << "\n     0000             0000        777777777" << std::endl;
}

void PrintIntro()
{
    std::cout << "\n-> You're a secret agent that needs to break into a server room and steal some important data. " << std::endl;
    std::cout << "-> To break into, you need to hack the next console and guess the correct code. " << std::endl;
    std::cout << "-> Try your luck with this!" << std::endl;
}

void PrintRoomTransition(int Difficulty)
{
    std::cout << std::endl;
    std::cout << "\n +++ Enter the LEVEL " << Difficulty << " server room +++" << std::endl;
}

void PrintEnding()
{
    std::cout << "\n           ,----------------,                 ,---------,";
    std::cout << "\n         ,-----------------------,          ,'         '|";
    std::cout << "\n       ,'                      ,'|        ,'       ,'   |";
    std::cout << "\n      +-----------------------+  |      ,'        ,'    |";
    std::cout << "\n      |  .-----------------.  |  |     +---------+      |";
    std::cout << "\n      |  |                 |  |  |     | -==----'|      |";
    std::cout << "\n      |  |  C/:_           |  |  |     |         |      |";
    std::cout << "\n      |  |  Mission        |  |  |/----|`---=    |      |";
    std::cout << "\n      |  |  complete!      |  |  |   ,/|==== ooo |      ;";
    std::cout << "\n      |  |                 |  |  |  // |(((( [33]|    ,' ";
    std::cout << "\n      |  `-----------------'  |,' .;'| |((((     |  ,'   ";
    std::cout << "\n      +-----------------------+  ;;  | |         |,'     ";
    std::cout << "\n         /_)______________(_/  //'   | +---------+       ";
    std::cout << "\n    ___________________________/___  `,;";
    std::cout << "\n   /  oooooooooooooooo  .o.  oooo /,   \,'-----------";
    std::cout << "\n  / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,'";
    std::cout << "\n '>>/_==__==========__==_ooo__ooo=_/'   /___________,'";
    std::cout << "\n `-----------------------------'";
}

void PrintBadEnding()
{
    std::cout << "\n           ,----------------,                 ,---------,";
    std::cout << "\n         ,-----------------------,          ,'         '|";
    std::cout << "\n       ,'                      ,'|        ,'       ,'   |";
    std::cout << "\n      +-----------------------+  |      ,'        ,'    |";
    std::cout << "\n      |  .-----------------.  |  |     +---------+      |";
    std::cout << "\n      |  |                 |  |  |     | -==----'|      |";
    std::cout << "\n      |  |  C/:_           |  |  |     |         |      |";
    std::cout << "\n      |  |  Mission        |  |  |/----|`---=    |      |";
    std::cout << "\n      |  |  Failed!        |  |  |   ,/|==== ooo |      ;";
    std::cout << "\n      |  |                 |  |  |  // |(((( [33]|    ,' ";
    std::cout << "\n      |  `-----------------'  |,' .;'| |((((     |  ,'   ";
    std::cout << "\n      +-----------------------+  ;;  | |         |,'     ";
    std::cout << "\n         /_)______________(_/  //'   | +---------+       ";
    std::cout << "\n    ___________________________/___  `,;";
    std::cout << "\n   /  oooooooooooooooo  .o.  oooo /,   \,'-----------";
    std::cout << "\n  / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,'";
    std::cout << "\n '>>/_==__==========__==_ooo__ooo=_/'   /___________,'";
    std::cout << "\n `-----------------------------'";
}

bool PlayGame(int Difficulty) //need fixes for number of tries,. Currently it doesn't go lower than 2.
{
    unsigned int FailCount;
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty; //rand() returns a value between 0 and 32767
    int CodeC = rand() % Difficulty + Difficulty;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << " \n-> There are 3 numbers in the code that add up to: " << CodeSum;
    std::cout << "\n-> The product of the numbers is: " << CodeProduct << std::endl;
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessC * GuessB;
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n*** Data extracted! Get to the next floor! ***";
        system("sleep<3");
        system("cls");
        PrintRoomTransition(Difficulty);
        return true;
    }
    else
    {
        do
        {
            if (FailCount > 0)
            {
                FailCount--;
                std::cout << "\n*** Carefull! We need the data intact and you in one piece! Better luck with the next room ***" << std::endl;
                std::cout << "You have " << FailCount << " remaining tries until the mission is aborted! Make them count!";
                return true;
            }
            else
            {
                if (FailCount == 0)
                {
                    std::cout << "*** You lost too many data! The mission is aborted! We're pulling you out! ***";
                    system("sleep<3");
                    system("cls");
                    PrintBadEnding();
                    return -1; //will exit the program and any loop
                }
            }
        } while (FailCount != 0);
    }
}

int main()
{
    srand(time(NULL)); //will add a new seed each time the program is compiled
    PrintGameCover();
    PrintIntro();
    int LevelDifficulty = 1;
    const int MaxLevel = 10;                             //const will make the max level a constant so it can't be changed
    while (LevelDifficulty <= MaxLevel)                  //will loop game until the last level is reached or until the player is killed
    {                                                    // the bool var must be initialized with the playgame function in order to return if the player has won or not
        bool bLevelComplete = PlayGame(LevelDifficulty); //in UE4 all bool variables must be prefixed with "b" then it's name

        std::cin.clear();  //clears any errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty; //will increase the difficulty by 1
        }
    }
    if (LevelDifficulty == MaxLevel)
    {
        PrintEnding();
    }

    return 0;
}