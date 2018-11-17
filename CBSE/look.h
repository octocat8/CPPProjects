using namespace std;
void character::checkRoom(int x) {
        mvprintw(x - 4, 0, "You are located at ( %i , %i )\n\nThe space you are currently in is %i", pos[1], pos[2], grid[pos[1]][pos[2]].returnSpaceVal());
}
void character::checkSurroundings(int x) {
        int row, col;
        row = pos[1];
        col = pos[2];
        for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++) {
                        if(i == 0 && j == 0) {
                                mvprintw((x-5)+i, (1+j)*15, "|*%s* ",grid[row+i][col+j].returnRoomVal());        
                        } else {
                                if(row+i < 0 || col+j < 0 || row+i > 6 || col+j > 9) {
                                        mvprintw((x-5)+i, (1+j)*15, "| ");        
                                } else {
                                        mvprintw((x-5)+i, (1+j)*15, "| %s", grid[row+i][col+j].returnRoomVal());
                                }
                        }
                }
        }
}