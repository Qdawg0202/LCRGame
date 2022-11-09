#include <stdio.h>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

int main()
{
    srand(time(NULL)); //randomly seeds

    //starts game and specifies player number
    int numOfPlayers = 0;
    cout << "Please enter number of players: " << endl;
    cin >> numOfPlayers;
    if(numOfPlayers < 3)
    {
        cout << "Error: Players entered not below minimum 3 players" << endl;
        return 1;
    }

    int centerPot = 0; //accumulates the chips at the center
    int winner; //will hold number of winning player

    Player arrPlayers[numOfPlayers];
    for(int x = 0; x < numOfPlayers; x++)
    {
        cout << "Player " << x << " has " << arrPlayers[x].getChips() << " chips" << endl;
    }

    while(winner != numOfPlayers-1) //while there is more than one player in the game
    {

//        cout << "there are currently " << numOfPlayers - numOut<< " players in the game this round" << endl;
        //checks to see how many players in game and if need to break out of while loop

        for(int x = 0; x < numOfPlayers; x++)
        {
            cout << "Player "<< x << " currently has " << arrPlayers[x].getChips() << " chips." << endl;
            int temp22 = arrPlayers[x].getChips();
            for(int y = 0; y < temp22  && y < 3; y++)
            {
                int temp = arrPlayers[x].takeTurn();

                if (temp == -1)  //if player x has no chips
                {
                    cout << "Player " << x << " has no chips, their turn will be skipped" << endl;
                }

                else if (temp == 0) //l case
                {
                    if (x == 0) //leftmost
                    {
                        arrPlayers[numOfPlayers - 1].setChips();
                    }
                    else
                    {
                        arrPlayers[x - 1].setChips();
                    }
                    cout << "Player " << x << " has rolled an L" << endl;
                }

                else if (temp == 1)//r case
                {
                    if (x == numOfPlayers-1)//right most
                    {
                        arrPlayers[0].setChips();
                    }
                    else
                    {
                        arrPlayers[x + 1].setChips();
                    }
                    cout << "Player " << x << " has rolled an R" << endl;
                }

                else if (temp == 2) //c case
                {
                    centerPot++;
                    cout << "Player " << x << " has rolled a C" << endl;
                }
                else
                {
                    cout << "Player " << x << " has rolled a *" << endl;
                }
            }
            cout << "Player "<< x << " now has " << arrPlayers[x].getChips() << " chips." << endl; //returns chips of player after a turn
            cout << endl;
            int numOut = 0; //counts the amount of players that have lost
            for(int a = 0; a < numOfPlayers; a++)
            {
                if(arrPlayers[a].getChips() <= 0)
                {
                    numOut++;
                }
            }
            winner = numOut;
            if(winner == numOfPlayers-1)
                break; //checks the winner every turn
        }
    }

    //gets winner of game
    for(int a = 0; a < numOfPlayers; a++)
    {
        if(!arrPlayers[a].getChips() == 0)
        {
            winner = a;
        }
    }

    cout << "Player " << winner << " has won the game and the " << centerPot << " chip pot" << endl;

    return 0;
}