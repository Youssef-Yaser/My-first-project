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
    cout<<" ---------------------"<<endl;
}
void design(char xo[4][4],int repeat[4][4]){
    lines();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << " | " ;
            if (repeat[i][j]!=0&&i*4+j+1>=10)
            cout<<repeat[i][j];
            else if(repeat[i][j]!=0&&i*4+j+1<10)
            cout<<repeat[i][j]<<" ";
            else
                cout<<xo[i][j]<<" ";
        }
        cout<<" |"<<endl;
    }
lines();
    cout<<endl;

}
void check_input(char xo[4][4], string position , int repeat[4][4], bool flag) {
    //check for correct input
    int range=0;
    for (int i = position.size()-1; i>=0; --i) {
       range += (position[i] - '0') * pow(10, position.size() - i - 1);
    }
    //check for range
    if (range > 0 && range < 17) {
        //check for repeat
        bool fix = true;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (repeat[i][j] == range) {
                    repeat[i][j] = 0;
                    fix = false;
                }
            }
        }
        if (fix) {
            cout << "Dont repeat and Enter position of  (from 1 to 16):" << endl;
            cin >> position;
            return check_input(xo, position, repeat, flag);
        }
        //replace X
        if (flag) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (range == i * 4 + j + 1)
                        xo[i][j] = 'X';
                }
            }
        }
            //replace O
        else{
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (range == i * 4 + j + 1)
                        xo[i][j] = 'O';
                }
            }
        }
    } else {
        cout << " please Enter position of  (from 1 to 16) : " << endl;
        cin >> position;
         return check_input(xo, position, repeat, flag);
    }
}
bool check_win(char xo[4][4], char symbol) {
    for (int i = 0; i < 4; ++i) {
        // Check rows
        if (xo[i][0] == symbol && xo[i][1] == symbol && xo[i][2] == symbol && xo[i][3] == symbol) {
            return true;
        }
        // Check columns
        if (xo[0][i] == symbol && xo[1][i] == symbol && xo[2][i] == symbol && xo[3][i] == symbol) {
            return true;
        }
    }
    // Check diagonal
    if (xo[0][0] == symbol && xo[1][1] == symbol && xo[2][2] == symbol && xo[3][3] == symbol) {
        return true;
    }
    // Check reverse diagonal
    if (xo[0][3] == symbol && xo[1][2] == symbol && xo[2][1] == symbol && xo[3][0] == symbol) {
        return true;
    }
    return false;
}
bool play(string &player1,string &player2) {
    char xo[4][4] = {};
    string position;
    int repeat[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    bool flag = true;
    select(player1,flag);
    int play_again;
    for (int i = 0; i < 16; ++i) {
            design(xo, repeat);
            if (flag) {
                cout << "Enter position of X (from 1 to 16):" << endl;
                cin >> position;
                check_input(xo, position, repeat, flag);
                if (check_win(xo, 'X')) {
                    cout << endl << "The player " << player1 << " is the Winner" << endl;
                    design(xo, repeat);
                    cout<<"press 1 to play again or enter any number to exit "<<endl;
                    cin>>play_again;
                    if (play_again==1)
                       return true ;
                    else
                       return false;
                }
                flag = false;
            } else {
                cout << "Enter position of O (from 1 to 16) : " << endl;
                cin >> position;
                check_input(xo, position, repeat, flag);
                if (check_win(xo, 'O')) {
                    cout << endl << "The player " << player2 << " is the Winner" << endl;
                    design(xo, repeat);
                    cout<<"press 1 to play again or enter any number to exit "<<endl;
                    cin>>play_again;
                    if (play_again==1)
                        return true ;
                    else
                        return false;
                }
                flag = true;
            }
    }
    cout << "End of the Game it is Draw " << endl;
    design(xo, repeat);
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
}
