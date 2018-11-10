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
    int returnPosVal() {
        return posval;
    }
    void setPosVal(int z) {
        posval = z;
    }
} temp, grid[7][10];
class character {
    int pos[3];
    int type;
    public:
    character(int a, int b, int c, int d) {
        pos[0] = a;
        pos[1] = b;
        pos[2] = c;
        type = d;
    }
    // 1 = user
    // 2 = senior
    // 3 = teacher 
};
void intro(int x, int y) {
    char *intro[] = {
        "ARCADIA",
        "Game created and designed by Lael John",
        "To move, use the arrow keys",
        "To check the room, press <space>",
        "To check your surroundings, press c",
        "Good Luck!"
    };
    for(int i = 0; i < 6; i++) {
        mvprintw(x/2, (y- strlen(intro[i]))/2, "%s", intro[i]);
        refresh();
        getch();
        clear();
    }
}
void loadlevel(int x) {
    ifstream fin;
    fin.open("layout.dat", ios::in | ios::binary);
    if(fin) {
    fin.read((char *)&temp, sizeof(temp));
        while(!fin.eof()) {
            if(temp.returnLevel() == x) {
                int row, col, pos;
                row = temp.returnRow();
                col = temp.returnCol();
                pos = temp.returnPosVal();
                grid[row][col].setPosVal(pos);
            }
            fin.read((char *)&temp, sizeof(temp));
        }
    fin.close();
    } else {
        cout<<"Unable to open file;";
    }
}