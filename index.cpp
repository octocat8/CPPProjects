#include <iostream>
#include <string.h>
#include <fstream>
#include <ncurses.h>
#include "create.h"
#include "look.h"
#include "move.h"
using namespace std;
int row, col, ch;
int main() {
    loadlevel(0);
    character user(0,0,0);
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    getmaxyx(stdscr, row, col);
    intro(row, col);
    loadScreen(user.returnCol(), user.returnRow());
    do {
        ch = getch();
        if(ch == KEY_LEFT || ch == 'h') {
            clear();
            user.moveLeft(col,row);
            loadScreen(user.returnCol(), user.returnRow());
            refresh();
        } else if (ch == KEY_RIGHT || ch == 'l') {
            clear();
            user.moveRight(col,row);
            loadScreen(user.returnCol(), user.returnRow());
            refresh();
        } else if (ch == KEY_UP || ch == 'k') {
            clear();
            user.moveUp(col,row);
            loadScreen(user.returnCol(), user.returnRow());
            refresh();
        } else if(ch == KEY_DOWN || ch == 'j') {
            clear();
            user.moveDown(col, row);
            loadScreen(user.returnCol(), user.returnRow());
            refresh();
        } else if(ch == 'u') {
            clear();
            user.Up(user.returnCol(), user.returnRow());
            loadScreen(user.returnCol(), user.returnRow());
            refresh();
        } else if(ch == 'd') {
            clear();
            user.Down(user.returnCol(), user.returnRow());
            loadScreen(user.returnCol(), user.returnRow());
            refresh();
        } else if(ch == 'c') {
            clear();
            user.checkRoom(row);
            loadScreen(user.returnCol(), user.returnRow());
            mvprintw(row-6, 0, "CHECK CURRENT ROOM");
            refresh();
        } else if(ch == ' ') {
            clear();
            user.checkSurroundings(row);
            loadScreen(user.returnCol(), user.returnRow());
            mvprintw(row-2, 0, "CHECK SURROUNDING ROOMS");
            refresh();
        }
        refresh();
    } while (ch != 'x');
    endwin();
    return 0;
}
