using namespace std;
void character::checkRoom(int x, int y) {
        mvprintw(x - 4, 0, "You are located at ( %i , %i )\n\nThe space you are currently in is %s", pos[1], pos[2], room_current);
}
void character::checkSurroundings(int x, int y) {
        int row, col;
        row = user.returnRow();
        col = user.returnCol();
        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++) {
                }
        }
}