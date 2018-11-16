using namespace std;
class space{
    int pos[3]; 
    int posval;
    char room_name[20];
    public:
    void getSpaceVal(int x, int y, int z) {
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        cout<<"Enter Position Value["<<x<<","<<y<<","<<z<<"]: ";
        cin>>posval;
        if(posval == 0) {
            strncpy(room_name, "No Entry", 20);
        } else if (posval == 1) {
            strncpy(room_name, "Corridor", 20);
        } else if (posval == 2) {
            strncpy(room_name, "Staircase", 20);
        } else if (posval == 3) {
            strncpy(room_name, "Lift", 20);
        } else if (posval == 5) {
            strncpy(room_name, "Washroom", 20);
        } else if (posval == 6) {
            strncpy(room_name, "Library", 20);
        } else if (posval == 7) {
            strncpy(room_name, "Play Area", 20);
        } else {
            cin.ignore();
            cout<<"Enter the name of the room: ";
            cin.getline(room_name, 20);
        }
    }
    void putSpaceVal() {
        cout<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<" "<<posval<<" "<<room_name<<endl;
    }
    int returnLevel() {
        return pos[0];
    }
    int returnRow() {
        return pos[1];
    }
    int returnCol() {
        return pos[2];
    }
    int returnSpaceVal() {
        return posval;
    }
    char const* returnRoomVal() {
        return room_name;
    }
    void setPosVal(int z) {
        posval = z;
    }
    void setRoomVal( char const* z) {
        strncpy(room_name, z, 20);
    }
    void setObjVal(int a, int b, int c, int d, char const* e) {
        pos[0] = a;
        pos[1] = b;
        pos[2] = c;
        posval = d;
        strncpy(room_name, e, 20);
    }
} temp, grid[7][10];
// class character {
//     int pos[3];
//     int type;
//     char room_current[20];
//     char room_next[20];
//     public:
//     character(int a, int b, int c, int d) {
//         pos[0] = a;
//         pos[1] = b;
//         pos[2] = c;
//         type = d;
//         strncpy(room_current, grid[b][c].returnRoomVal(), 20);
//     }
//     int returnRow() { return pos[1]; }
//     int returnCol() { return pos[2]; }
//     void moveLeft(int x, int y);
//     void moveRight(int x, int y);
//     void moveUp(int x, int y);
//     void moveDown(int x, int y);
//     void checkRoom(int x);
//     void stairUp(int x, int y);
//     void stairDown(int x, int y);
//     void checkSurroundings(int x);
//     void setLocation(int x, int y, int z) {
//         pos[0] = x;
//         pos[1] = y;
//         pos[2] = z;
//     }
// };
// void intro(int x, int y) {
//     char const *intro[] = {
//         "ARCADIA",
//         "Game created and designed by Lael John",
//         "To move, use the arrow keys",
//         "To check the room, press <space>",
//         "To check your surroundings, press c",
//         "To exit, press x",
//         "On the screen, . represents your current position",
//         "Good Luck!"
//     };
//     for(int i = 0; i < 7; i++) {
//         mvprintw(x/2, (y- strlen(intro[i]))/2, "%s", intro[i]);
//         refresh();
//         getch();
//         clear();
//     }
// }
// void loadlevel(int x) {
//     ifstream fin;
//     fin.open("layout.dat", ios::in | ios::binary);
//     if(fin) {
//     fin.read((char *)&temp, sizeof(temp));
//         while(!fin.eof()) {
//             if(temp.returnLevel() == x) {
//                 int row, col, pos;
//                 row = temp.returnRow();
//                 col = temp.returnCol();
//                 pos = temp.returnSpaceVal();
//                 grid[row][col].setPosVal(pos);
//                 grid[row][col].setRoomVal(temp.returnRoomVal());
//             }
//             fin.read((char *)&temp, sizeof(temp));
//         }
//     fin.close();
//     } else {
//         cout<<"Unable to open file;";
//     }
// }
// void loadScreen(int x, int y) {
//     for(int i = 0; i < 7; i++){
//         for(int j = 0; j < 10; j++) {
//             if(y == i && x == j) {
//                 mvprintw(5 + i, 5+ (3*j), " ^ ");
//             } else if(grid[i][j].returnSpaceVal() == 0){
//                 mvprintw(5 + i, 5+ (3*j), "|X|");
//             } else if(grid[i][j].returnSpaceVal() == 1){
//                 mvprintw(5 + i, 5+ (3*j), "   ");
//             } else {
//                 mvprintw(5 + i, 5+ (3*j), "|O|");
//             }
//         }
//     }
// }