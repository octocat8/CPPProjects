#include <ncurses.h>
#include <string.h>
using namespace std;
int main() {
    char mesg[]= "ARCADIA";
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    mvprintw(row/2, (col - strlen(mesg))/2,"%s",mesg);
    mvprintw(row/2 + 2, (col - strlen(mesg))/2, "This window has %d rows and %d cols.", row, col);
    refresh();
    getch();
    endwin();
    return 0;
}