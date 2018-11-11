using namespace std;
void character::moveLeft(int x, int y) {
    strncpy(room_current, grid[pos[1]][pos[2]].returnRoomVal(), 20);
    strncpy(room_next, grid[pos[1]][pos[2]-1].returnRoomVal(), 20);
    if(pos[2] > 0 && grid[pos[1]][pos[2] - 1].returnSpaceVal() != 0) {
        if(grid[pos[1]][pos[2]].returnSpaceVal() != 1 && grid[pos[1]][pos[2]-1].returnSpaceVal() != 1) {
            if(strncmp(room_current, room_next, 20) == 0) {
                --pos[2]; 
                strncpy(room_current, room_next, 20);
                mvprintw(y-2, 0, "MOVE LEFT");
            } else {
                mvprintw(y-2, 0, "UNABLE TO MOVE LEFT");
            }
        } else {
            --pos[2]; 
            strncpy(room_current, room_next, 20);
            mvprintw(y-2, 0, "MOVE LEFT");
        }
    } 
}
void character::moveRight(int x, int y) {
    strncpy(room_current, grid[pos[1]][pos[2]].returnRoomVal(), 20);
    strncpy(room_next, grid[pos[1]][pos[2]+1].returnRoomVal(), 20);
    if(pos[2] < 9 && grid[pos[1]][pos[2] + 1].returnSpaceVal() != 0) {
        if(grid[pos[1]][pos[2]].returnSpaceVal() != 1 && grid[pos[1]][pos[2]+1].returnSpaceVal() != 1) {
            if(strncmp(room_current, room_next, 20) == 0) {
                ++pos[2]; 
                strncpy(room_current, room_next, 20);
                mvprintw(y-2, 0, "MOVE RIGHT");
            } else {
                mvprintw(y-2, 0, "UNABLE TO MOVE RIGHT");
            }
        } else {
            ++pos[2]; 
            strncpy(room_current, room_next, 20);
            mvprintw(y-2, 0, "MOVE RIGHT");
        }
    } 
}
void character::moveUp(int x, int y) {
    strncpy(room_current, grid[pos[1]][pos[2]].returnRoomVal(), 20);
    strncpy(room_next, grid[pos[1]-1][pos[2]].returnRoomVal(), 20);
    if(pos[1] > 0 && grid[pos[1]-1][pos[2]].returnSpaceVal() != 0)  {
        if(grid[pos[1]][pos[2]].returnSpaceVal() != 1 && grid[pos[1]-1][pos[2]].returnSpaceVal() != 1) {
            if(strncmp(room_current, room_next, 20) == 0) {
                --pos[1]; 
                strncpy(room_current, room_next, 20);
                mvprintw(y-2, 0, "MOVE UP");
            } else {
                mvprintw(y-2, 0, "UNABLE TO MOVE UP");
            }
        } else {
            --pos[1]; 
            strncpy(room_current, room_next, 20);
            mvprintw(y-2, 0, "MOVE UP");
        }
    }
}
void character::moveDown(int x, int y) {
    strncpy(room_current, grid[pos[1]][pos[2]].returnRoomVal(), 20);
    strncpy(room_next, grid[pos[1]+1][pos[2]].returnRoomVal(), 20);
    if(pos[1] < 6 && grid[pos[1]+1][pos[2]].returnSpaceVal() != 0)  {
        if(grid[pos[1]][pos[2]].returnSpaceVal() != 1 && grid[pos[1]+1][pos[2]].returnSpaceVal() != 1) {
            if(strncmp(room_current, room_next, 20) == 0) {
                ++pos[1]; 
                strncpy(room_current, room_next, 20);
                mvprintw(y-2, 0, "MOVE DOWN");
            } else {
                mvprintw(y-2, 0, "UNABLE TO MOVE DOWN");
            }
        } else {
            ++pos[1]; 
                strncpy(room_current, room_next, 20);
                mvprintw(y-2, 0, "MOVE DOWN");
        }
    }
}

void character::stairUp(int x, int y) {
    if(pos[0] == 4) {
        mvprintw(y-2, 0, "NO FLOORS ABOVE");
    } else {
        if(grid[x][y].returnSpaceVal() == 2) {
            clear();
            loadlevel(pos[0]+1);
            ++pos[0];
            setLocation(pos[0], x, y);
            mvprintw(y-2, 0, "Floor Changed to %i", pos[0]);
        } else {
            mvprintw(y-2, 0, "MOVE TO STAIRCASE/LIFT AND TRY AGAIN");
        }
    }
}

void character::stairDown(int x, int y) {
    if(pos[0] == 0) {
        mvprintw(y-2, 0, "NO FLOORS BELOW");
    } else {
        if(grid[x][y].returnSpaceVal() == 2) {
            clear();
            loadlevel(pos[0]-1);
            --pos[0];
            setLocation(pos[0], x, y);
            mvprintw(y-2, 0, "Floor Changed to %i", pos[0]);
        } else {
            mvprintw(y-2, 0, "MOVE TO STAIRCASE/LIFT AND TRY AGAIN");
        }
    }
}