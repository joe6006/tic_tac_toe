#include <iostream>
#include <random>
#include <limits>

using namespace std;
#include <random>

int main()
{
    //empty space 2-d grid
    char grid[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row = 0;
    int col = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> int_dist(0, 2);

    while (true)
    {
        for (row = 0; row < 3; row++)
        {
            cout << row << "| ";

            for (col = 0; col < 3; col++)
            {
                cout << " " << grid[row][col] << " ";

                if (col < 2)
                    cout << "|";
            }

            cout << '\n';
            if (row < 2)
                cout << "   ---+---+---\n";
        }

        cout << "   -----------\n";
        cout << "    0 | 1 | 2\n";
        cout << "please input 2 numbers 0-2. the first input will be the row and the second will be the column." << endl;
        cout << "This is how you will input your wanted position." << endl;

        do
        {
            if (!(cin >> row >> col))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                row = -1;
                col = -1;
            }
        } while (row < 0 || row > 2 || col < 0 || col > 2);

        if (grid[row][col] != ' ')
        {
            cout << "spot is taken" << endl;
            continue;
        }

        grid[row][col] = 'X';

        int computerRow = int_dist(gen);
        int computerCol = int_dist(gen);

        while (grid[computerRow][computerCol] != ' ')
        {
            computerRow = int_dist(gen);
            computerCol = int_dist(gen);
        }

        grid[computerRow][computerCol] = 'O';

        bool winner = false;

        for (int i = 0; i < 3; i++)
        {
            if (grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X')
            {
                cout << "you won" << endl;
                winner = true;
            }
            else if (grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X')
            {
                cout << "you won" << endl;
                winner = true;
            }

            if (grid[i][0] == 'O' && grid[i][1] == 'O' && grid[i][2] == 'O')
            {
                cout << "Computer Wins" << endl;
                winner = true;
            }
            else if (grid[0][i] == 'O' && grid[1][i] == 'O' && grid[2][i] == 'O')
            {
                cout << "Computer Wins" << endl;
                winner = true;
            }
        }

        if ((grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') ||
            (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X'))
        {
            cout << "you won" << endl;
            winner = true;
        }else if((grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') ||
            (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')){
                cout<<"Computer Wins";
                winner = true;
            };

        if (winner)
        {
            cout << "\nWinning board:\n";
            for (int row = 0; row < 3; row++)
            {
                cout << row << "| ";
                for (int col = 0; col < 3; col++)
                {
                    cout << " " << grid[row][col] << " ";
                    if (col < 2)
                        cout << "|";
                }
                cout << '\n';
                if (row < 2)
                    cout << "   ---+---+---\n";
            }
            cout << "   -----------\n";
            cout << "    0 | 1 | 2\n";
            break;
        }
    }

    return 0;
}