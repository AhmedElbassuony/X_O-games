#include <iostream>
#include "BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI pyramic Game. :)\n";

    cout <<"select which game you want:\n";
    cout <<"1-Normal X_O\n";
    cout <<"2-pyramic X_O\n";
    cout <<"3-tic_tac_toe X_O\n";
    cin>>choice;
    if(choice==1)
    {
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            players[1] = new RandomPlayer ('o', 3);

        
        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
    }
    else if(choice==2)
    {
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            players[1] = new com_pyramic_player ('o');

        GameManager pyramic_game (new Pyramic_board(), players);
        pyramic_game.run();
    }
    else if(choice==3)
    {
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            players[1] = new RandomPlayer ('o', 5);
            
        GameManager tic_tac_toe_game (new tic_tac_toe, players);
        tic_tac_toe_game.run();
    }
    else 
    {
        cout <<"invalid choice\n";
    }
    system ("pause");
}
