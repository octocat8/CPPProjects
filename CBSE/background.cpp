#include <fstream.h>
#include <iostream>
#include <ctype.h>
#include <ncurses.h>
using namespace std;
class space{
    int floor, col, row;
    int space_val;
    char space_name[10];
    bool objective;
    int objective_no;
};
space grid[4][7][9];
void writedata() {
    ofstream fout;
    fout.open("FLOORS.DAT");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            for(int k = 0; k < 9; k++) {
                grid[i][j][k].floor = i;
                grid[i][j][k].row = j;
                grid[i][j][k].col = k;
                cout<<"Enter space_val: ";
                cin>>grid[i][j][k].space_val;
                // 0 = Air
                // 1 = corridor
                // 2 = staircase
                // 3 = classroom
                // 4 = washroom
                // 5 = library
                // 6 = Niche/Room/Subject Room
                if(grid[i][j][k].space_val == 3 || grid[i][j][k].space_val == 6) {
                    cout<<"Enter name of classroom";
                    cin.getline(grid[i][j][k].space_name,10);
                }
            }
        }
    }
}