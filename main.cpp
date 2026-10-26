#include <iostream>
using namespace std;

int main()
{
    char grid[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    // Put X in the first row, second column

    int row, col = 0;

    do
    {
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

        cout << "please input 2 numbers 0-2. the first input will be the row and the second will be the column." << endl;
        cout << "This is how you will input your wanted position." << endl;

        cin >> row >> col;

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
        
        for (int i = 0; i < 3; i++)
        {
            if (grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X')
            {
                cout<< "you won"<<endl;
            }
        }

    } while (true);

    return 0;
}