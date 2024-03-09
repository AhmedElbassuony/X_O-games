#include "BoardGame_Classes.hpp"
#include <iomanip>

Pyramic_board::Pyramic_board()
{
    n_rows = 3;
    n_cols = 1;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0;
        }
        n_cols += 2;
    }
}

bool Pyramic_board::update_board(int x, int y, char mark)
{
    if (!(x < 0 || x > 2 || y > (1 + 2 * x) || y < 0) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    return false;
}

void Pyramic_board::display_board()
{
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
        for (int j = 0; j < (4 - 2 * i) / 2; j++)
            cout << "         ";
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "|(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }

        cout << "\n----------------------------------------------";
    }
    cout << endl;
}

bool Pyramic_board::is_winner()
{
    if (board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[0][0] != 0)
    {
        return true;
    }
    if (board[1][0] == board[1][1] and board[1][1] == board[1][2] and board[1][0] != 0)
    {
        return true;
    }
    if (board[2][0] == board[2][1] and board[2][1] == board[2][2] and board[2][0] != 0)
    {
        return true;
    }
    if (board[2][1] == board[2][2] and board[2][2] == board[2][3] and board[2][1] != 0)
    {
        return true;
    }
    if (board[2][2] == board[2][3] and board[2][3] == board[2][4] and board[2][2] != 0)
    {
        return true;
    }
    if (board[0][0] == board[1][2] and board[1][2] == board[2][4] and board[0][0] != 0)
    {
        return true;
    }
    if (board[0][0] == board[1][0] and board[1][0] == board[2][0] and board[0][0] != 0)
    {
        return true;
    }
    return false;
}

bool Pyramic_board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool Pyramic_board::game_is_over()
{
    return n_moves >= 9;
}