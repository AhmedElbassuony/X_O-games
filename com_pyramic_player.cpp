#include "BoardGame_Classes.hpp"

com_pyramic_player::com_pyramic_player(char symbol) : Player(symbol)
{
    this->name = "Computer";
    cout << "My names is " << name << endl;
}

void com_pyramic_player::get_move(int &x, int &y)
{
    x = rand() % (3);
    y = rand() % (x * 2 + 1);
}
