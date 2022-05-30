// tic tac toe ai using minimax algorithm
#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "|   ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "   "
                 << "|   ";
        }
        cout << endl
             << "--------------------------" << endl;
    }
}
bool placeMarker(int slot)
{ // for finding in which the slot is wee see that if we divide 1 or 4 or 7 by 3 we get 0,1,2 which is row number but if we divide last element ie 3, 6,9 it gives 1,2,3 1 more than row
    int row, column;
    if (slot % 3 == 0)
    {
        row = (slot / 3) - 1;
        column = 2;
    }
    else
    {
        row = slot / 3;
        column = (slot % 3) - 1;
    }
    // cout << row << ',' << column;
    if (board[row][column] != 'X' && board[row][column] != 'Y')
    {
        board[row][column] = currentMarker;
        return true;
    }
    else
    {
        return false;
    }
}
int winner()
{ // same row or column or diagonal
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return currentPlayer;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return currentPlayer;
    }
    return 0;
}
void swap_player_and_marker(char marker1, char marker2)
{
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
        currentPlayer = 1;

    if (currentMarker == marker1)
        currentMarker = marker2;
    else
        currentMarker = marker1;
}
void game()
{
    cout << "Player 1 select your marker" << endl;
    char marker1;
    cin >> marker1;
    cout << "Player 2 select your marker" << endl;
    char marker2;
    cin >> marker2;
    int slot;
    int win = 0;
    currentPlayer = 1;
    currentMarker = marker1;
    drawBoard();
    for (int i = 0; i < 9; i++)
    {

        cout << "Player " << currentPlayer << " please enter the position you want to mark" << endl;
        cin >> slot;
        // if slot is out of range we go back to for loop again with a decreased value of i
        if (slot < 1 || slot > 9)
        {
            cout << "Please enter a valid slot.";
            i--;
            continue;
        }
        // if slot is already filled we go back to for loop again with a decreased value of i
        if (!placeMarker(slot))
        {
            cout << "This slot is already filled please select another slot.";
            i--;
            continue;
        }
        drawBoard();
        win = winner();
        if (win != 0)
        {
            cout << "Player " << currentPlayer << '(' << currentMarker << ')' << " is the winner.";
            break;
        }
        swap_player_and_marker(marker1, marker2);
    }
    if (win == 0)
        cout << "Nobody won, Match was a draw.";
}
int main()
{
    game();
}
