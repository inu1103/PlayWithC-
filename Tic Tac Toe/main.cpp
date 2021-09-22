// play TIC TAC TOE now 

#include <bits/stdc++.h>
using namespace std;

char TTT[10] = {'o','1','2','3','4','5','6','7','8','9'};

int Winner_Check();
void SQUARE();

int main()
{
    int player = 1,i,choice;

    char mark;
    do
    {
        SQUARE();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && TTT[1] == '1')

            TTT[1] = mark;
        else if (choice == 2 && TTT[2] == '2')

            TTT[2] = mark;
        else if (choice == 3 && TTT[3] == '3')

            TTT[3] = mark;
        else if (choice == 4 && TTT[4] == '4')

            TTT[4] = mark;
        else if (choice == 5 && TTT[5] == '5')

            TTT[5] = mark;
        else if (choice == 6 && TTT[6] == '6')

            TTT[6] = mark;
        else if (choice == 7 && TTT[7] == '7')

            TTT[7] = mark;
        else if (choice == 8 && TTT[8] == '8')

            TTT[8] = mark;
        else if (choice == 9 && TTT[9] == '9')

            TTT[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=Winner_Check();

        player++;
    }while(i==-1);
    SQUARE();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

int Winner_Check()
{
    if (TTT[1] == TTT[2] && TTT[2] == TTT[3])

        return 1;
    else if (TTT[4] == TTT[5] && TTT[5] == TTT[6])

        return 1;
    else if (TTT[7] == TTT[8] && TTT[8] == TTT[9])

        return 1;
    else if (TTT[1] == TTT[4] &&TTT[4] == TTT[7])

        return 1;
    else if (TTT[2] == TTT[5] && TTT[5] == TTT[8])

        return 1;
    else if (TTT[3] == TTT[6] && TTT[6] == TTT[9])

        return 1;
    else if (TTT[1] == TTT[5] && TTT[5] == TTT[9])

        return 1;
    else if (TTT[3] == TTT[5] && TTT[5] == TTT[7])

        return 1;
    else if (TTT[1] != '1' && TTT[2] != '2' && TTT[3] != '3'
             && TTT[4] != '4' && TTT[5] != '5' && TTT[6] != '6'
             && TTT[7] != '7' && TTT[8] != '8' && TTT[9] != '9')

        return 0;
    else
        return -1;
}

void SQUARE()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << TTT[1] << "  |  " << TTT[2] << "  |  " << TTT[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << TTT[4] << "  |  " << TTT[5] << "  |  " << TTT[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << TTT[7] << "  |  " << TTT[8] << "  |  " << TTT[9] << endl;

    cout << "     |     |     " << endl << endl;
}