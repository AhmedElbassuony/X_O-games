#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"

using namespace std;

tic_tac_toe::tic_tac_toe() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool tic_tac_toe::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void tic_tac_toe::display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n|| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board [i][j] << " ||";
        }
        cout << "\n-------------------------------------------------------------";
    }
    cout << endl;
}
bool tic_tac_toe::is_winner(){
    char row_win[5], col_win[5], diag_win[8];
    for (int i:{0,1,2,3,4}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2] & board[i][3] & board[i][4] ,
                col_win[i] = board[0][i] & board[1][i] & board[2][i] & board[3][i]  & board[4][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2] ;
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];
    diag_win[2] = board[1][0] & board[2][1] & board[3][2];
    diag_win[3] = board[2][0] & board[3][1] & board[4][2];
    diag_win[4] = board[0][3] & board[1][2] & board[2][1];
    diag_win[5] = board[0][4] & board[1][3] & board[2][2];
    diag_win[6] = board[1][4] & board[2][3] & board[3][2];
    diag_win[7] = board[2][4] & board[3][3] & board[4][2];

    for (int i:{0,1,2,3,4}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
        {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1])||
        (diag_win[1] && diag_win[1] == board[1][1])||
        (diag_win[2] && diag_win[2] == board[1][1])||
        (diag_win[3] && diag_win[3] == board[1][1])||
        (diag_win[4] && diag_win[4] == board[1][1])||
        (diag_win[5] && diag_win[5] == board[1][1])||
        (diag_win[6] && diag_win[6] == board[1][1])||
        (diag_win[7] && diag_win[7] == board[1][1]))
    {return true;}
    return false;
}
bool tic_tac_toe::is_draw(){
    return (n_moves == 25 && !is_winner());
}
bool tic_tac_toe:: game_is_over(){
    return n_moves >= 25;
}