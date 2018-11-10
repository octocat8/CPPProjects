/*
    Welcome to Lael's Class 12 CS project, codenamed Arcadia
    Purpose: simulate a the life of a kid wandering around Step By Step School
    Support structure: 4 grids of 63 spaces each;
    each space has should have an integral value, denoting what a user can and cannot do.
    may need more than 3 header files
    As of now these remain 
    -> movement.h controls all the movement functions
    -> look.h controls all the look around functions
    -> goal.h controls the flow of the game and the goals a student (player) must acheive
    Files that I might need to create:
    -> alter.h changes how the school looks and behaves as a student grows up
    -> ncurses.h allows for graphical user interfaces
    Rules: 
    You cannot move to spaces marked 0 
    -> The objectives or goals may be spread all over the school
    -> Teachers will be moving along the corridors, they will also be present in each of the classes. You must avoid teachers if they start coming after you. You may do this by going to the washroom or entering a class nearby.
    -> Senior students will slow you down or block a corridor
    -> As you get older, your seniors will affect your speed less, but teachers will move at a faster pace
    ->  Some Subject rooms may be unavailable at certain times owing to usage by seniors for illicit activities
    -> Some rooms may contain special messages, that only appear when a user checks the room.
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include <ncurses.h>
#include "create.h"
using namespace std;

int main() {
    int row, col;
    loadlevel(2);
    character user(0,0,0,1);
    initscr();
    getmaxyx(stdscr, row, col);
    intro(row, col);
    
    endwin();
    return 0;
}
