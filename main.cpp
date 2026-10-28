#include <iostream>
using namespace std;
#include <random>

int main()
{
    //empty space 2-d grid
    char grid[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    // intialize row and col
    int row, col = 0;

    // random generator so that a random O can be put in an empty space after the user X input
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> int_dist(0, 2);


    // making a do-while loop to start game until there is a winner
    do
    {
        //creating borders bewtween around the empty space grid to make the border using
        //nested for-loop
        for (row = 0; row < 3; row++)
        {
            if (row < 3)
                std::cout << row << "| ";

            for (col = 0; col < 3; col++)
            {

                cout << " " << grid[row][col] << " ";

                if (col < 2)
                    cout << "|";
            }

            cout << '\n';
            if (row < 2)
                cout << "   " << "---+---+---\n";
        }

        cout << "   " << "-----------\n";
        cout << "    0 | 1 | 2\n";
        //get user input for row and column
        cout << "please input 2 numbers 0-2. the first input will be the row and the second will be the column." << endl;
        cout << "This is how you will input your wanted position." << endl;

        cin >> row >> col;

        //input bool for this small do while check to make sure user input is valid
        // and to keep random generator from posting O until input is valid
        bool input = false;

        do
        {
            if (row < 0 || row > 2 || col < 0 || col > 2)
            {
                cout << "invalid input" << endl;
                cin >> row >> col;
            }
            else
            {
                input = true;
                break;
            }
        } while (input);

        if (row >= 0 && row < 3 && col >= 0 && col < 3)
        {
            if (grid[row][col] == ' ')
            {
                grid[row][col] = 'X';
            }
            else if (grid[row][col] == 'X')
            {
                cout << "spot is taken";
            }
        }

        if (grid[int_dist(gen)][int_dist(gen)] != 'X' && cin)
        {
            grid[int_dist(gen)][int_dist(gen)] = 'O';
        }

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
                cout << "you won";
                winner = true;
            }
        }

        if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X' ||
            grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')
        {
            cout << "you won";
            winner = true;
        }

        if (winner == true)
        {
            break;
        }
    } while (true);

    return 0;
}