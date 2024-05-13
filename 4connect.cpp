#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void name_players(string &player1, string &player2){
    cout << "Enter your name (player 1) : " << endl;
    getline(cin, player1);
    cout << "Enter your name (player 2) : " << endl;
    getline(cin, player2);
}
void select(string &player1,bool &flag){
    string selector;
    cout<<player1<<"if you to play with X press 1 or press 2 to play with O"<<endl;
    cin>>selector;
    int range=0;
    for (int i = selector.size()-1; i>=0; --i) {
        range += (selector[i] - '0') * pow(10,selector.size() - i - 1);
    }
    if(range==1)
        flag=true;
    else if (range==2)
        flag=false;
    else
        select(player1,flag);
}
void lines(){
    cout<<" +---+---+---+---+---+---+---+"<<endl;
}
void design(char connect4[7][7]){
    cout<<" 1 + 2 +  3 +  4 + 5 + 6 + 7"<<endl;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << " | "<<connect4[i][j];
        }
        cout<<" |"<<endl;
        lines();
    }
    cout<<endl;
}
bool overload(char connect4[7][7],int x){
    if(connect4[0][x-1]=='X'||connect4[0][x-1]=='O')
        return true;
    else
        return false;
}
bool check_input(char connect4[7][7],string position,bool flag) {
    //check for correct input
    int x = 0;
    for (int i = position.size() - 1; i >= 0; --i)
        x += (position[i] - '0') * pow(10, position.size() - i - 1);
    //check for range
    if (x > 0 && x < 8) {
        //check for overload
        if (overload(connect4,x)){
            cout << "Overload in "<<x<<" position (from 1 to 7):" << endl;
            cin >> position;
            check_input(connect4, position, flag);
        }
        //replace
        if (flag) {
            for (int i = 6; i >= 0; --i) {
                if (connect4[i][x - 1] != 'X' && connect4[i][x - 1] != 'O') {
                        connect4[i][x - 1] = 'X';
                    return true;
                }
            }
        }
        else {
            for (int i = 6; i >= 0; --i) {
                if (connect4[i][x - 1] != 'X' && connect4[i][x - 1] != 'O') {
                        connect4[i][x - 1] = 'O';
                    return true;
                }
            }
        }
    } else {
        cout << "Enter position (from 1 to 7):" << endl;
        cin >> position;
        check_input(connect4, position, flag);
    }
    return false;
}
bool check_win(char connect4[7][7], char symbol){
        // Check rows
    for (int i = 0; i < 7; ++i) {
        for (int j = 3; j < 7; ++j) {
            if (connect4[i][j] == symbol && connect4[i][j-1] == symbol && connect4[i][j-2] == symbol &&
                connect4[i][j-3] == symbol)
                return true;
        }
    }
        // Check columns
        for (int i = 3; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (connect4[i][j] == symbol && connect4[i-1][j] == symbol && connect4[i-2][j] == symbol &&
                connect4[i-3][j] == symbol)
                return true;
        }
    }
    //check for diagonals
    for (int i = 3; i < 7; ++i) {
        for (int j = 3; j < 7; ++j) {
            if(connect4[i][j]==symbol&&connect4[i-1][j-1]==symbol&&connect4[i-2][j-2]==symbol&&connect4[i-3][j-3]==symbol)
                return true;
        }
    }
    for (int i = 3; i < 7; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(connect4[i][j]==symbol&&connect4[i-1][j+1]==symbol&&connect4[i-2][j+2]==symbol&&connect4[i-3][j+3]==symbol)
                return true;
        }
    }
    return false;
}
bool play(string player1, string player2) {
    char connect4[7][7]={};
    string position;
    bool flag=true;
    select(player1,flag);
    int play_again;
    for (int i = 0; i < 49; ++i) {
        design(connect4);
        if (flag) {
            cout << "Enter position of X (from 1 to 7):" << endl;
            cin>>position;
            check_input(connect4,position,flag);
            if (check_win(connect4, 'X')) {
                cout << endl << "The player " << player1 << " is the Winner" << endl;
                design(connect4);
                cout<<"press 1 to play again or enter any number to exit "<<endl;
                cin>>play_again;
                if (play_again==1)
                    return true ;
                else
                    return false;
            }
            flag= false;
        }
        else{
            cout << "Enter position of O (from 1 to 7):" << endl;
            cin>>position;
            check_input(connect4,position,flag);
            if (check_win(connect4, 'O')) {
                cout << endl << "The player " << player2 << " is the Winner" << endl;
                design(connect4);
                cout<<"press 1 to play again or enter any number to exit "<<endl;
                cin>>play_again;
                if (play_again==1)
                    return true ;
                else
                    return false;
            }
            flag=true;
        }
    }
    cout << "End of the Game it is Draw " << endl;
    design(connect4);
    cout<<"press 1 to play again or enter any number to exit "<<endl;
    cin>>play_again;
    if (play_again==1)
        return true ;
    else
        return false;
}
int main(){
    string player1, player2;
    name_players(player1,player2);
    bool game=true;
    while(game) {
game=play(player1,player2);
    }
    return 0;
}/* draw
 1 2 1 2 1 2 2 1 2 1 2 1 1 2 3 4 3 4 3 4 4 3 4 3  4 3 3 4 5 6 5 6  5 6 6 5 6 5 6 5 5 6 7 7 7 7 7 7 7
 */
