#include <iostream>
using namespace std;

int checkwin(char square[]);
void board(char square[]);

int main()
{

    string reply = "y";
    while (reply == "y") // lets the players play as long is "y" is true.
    {
        char square [9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int player = 1;
        int win = 0;
        int choice;
        char mark;

        string playerOne;
        string playerTwo;
        string currentPlayer;

        string y;
        string n;

        cout << "Welcome to Tic Tac Toe!\n";
        cout << "Player 1: Type your name" << endl;
        getline(cin, playerOne);                    // Using getline instead of cin that is including the whitespace
        cout << "PLayer 2: Type your name" << endl;
        getline(cin, playerTwo);                    // Using getline instead of cin that is including the whitespace


        while (win == 0)
        {
            cout << "\n" << playerOne << " (X) - " << playerTwo << " (O)" << endl << endl;
            board(square);
            currentPlayer = (player % 2 == 1 ) ? playerOne : playerTwo; // This funtion is creating the oppurtunity too play multiplayer
            mark = (player % 2 == 1) ? 'X' : 'O'; // This function change turns based on "X & O"

            cout << "\n" << currentPlayer << " enter a number: ";
            cin >> choice;
            //this is explaining the fact that the range of the board is actually from 0-8.
            //by koding this the visual appearance will go from the range 1-9.
            if      (choice == 1 && square [0] == '1') { square [0] = mark; }
            else if (choice == 2 && square [1] == '2') { square [1] = mark; }
            else if (choice == 3 && square [2] == '3') { square [2] = mark; }
            else if (choice == 4 && square [3] == '4') { square [3] = mark; }
            else if (choice == 5 && square [4] == '5') { square [4] = mark; }
            else if (choice == 6 && square [5] == '6') { square [5] = mark; }
            else if (choice == 7 && square [6] == '7') { square [6] = mark; }
            else if (choice == 8 && square [7] == '8') { square [7] = mark; }
            else if (choice == 9 && square [8] == '9') { square [8] = mark; }
            else    //the player will recieve an invalid move if the spot is already taken or is not on the board.
            {
                cout << "Invalid move.";
                player--;
                cin.ignore();
                cin.get();
            }
            cout << endl;
            win = checkwin(square);     // checking if the game is still continuing
            player++;
        }

        board(square);

        if (win == 1)
        {
            cout << currentPlayer << " wins!\n";
        }
        else
        {
            cout << "Draw!";    //the game will come too a draw if it can't find any winner after every spot on the board is taken.
        }
        cin.ignore();
        cin.get();

        cout << "Do you want too play again? (y/n)" << endl << endl; //asks the player for input on if they would like too play once more
        getline(cin, reply); //using getline in hopes of ignoring whitespace in the answer, but it fails to do so.

    }
    return 0;

}

int checkwin (char square[])//checking if any of the players have 3 in a row. This is done by koding all the available possibilities.
{                            //the game will continue to the next players turn if a win is not discovered.
    if      (square [0] == square [1] && square [1] == square [2]) return 1;        //Teacher said that you could do shortcuts with this setup in a for loop by typing:
    else if (square [0] == square [3] && square [3] == square [6]) return 1;        //for (int i = 0; i < 7; i=3)
    else if (square [0] == square [4] && square [4] == square [8]) return 1;        //sqaure [i] == sqaure [i+1] && sqaure[i+1] == sqaure [i+2]
    else if (square [3] == square [4] && square [4] == square [5]) return 1;
    else if (square [6] == square [7] && square [7] == square [8]) return 1;
    else if (square [1] == square [4] && square [4] == square [7]) return 1;
    else if (square [2] == square [5] && square [5] == square [8]) return 1;
    else if (square [2] == square [4] && square [4] == square [6]) return 1;
    else if (  square [0] != '1' && square [1] != '2' && square [2] != '3'
               && square [3] != '4' && square [4] != '5' && square [5] != '6'
               && square [6] != '7' && square [7] != '8' && square [8] != '9')
        return 2;
    else
        return 0;
}

void board(char square []) //this is creating the visual board
{
    system("cls");
    cout << "     |     |     " << endl;
    cout << "  " << square[6] << "  |  " << square [7] << "  |  " << square [8] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[3] << "  |  " << square [4] << "  |  " << square [5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[0] << "  |  " << square [1] << "  |  " << square [2] << endl;
    cout << "     |     |     " << endl << endl;

    return;
}
