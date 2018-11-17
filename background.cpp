#include <iostream>
#include <string.h>
#include <fstream>
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
}temp;
int main() {
    fstream file;  
    file.open("layout.dat", ios::out | ios::binary);
    if(file) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 7; j++) {
                for(int k = 0; k < 10; k++) {
                    temp.getSpaceVal(i, j, k);
                    file.write((char *)&temp, sizeof(temp));
                }
                cout<<endl<<"End row"<<endl;
            }
            cout<<endl<<"End floor"<<endl;
        }
        file.close();
    } else {
        cout<<"Unable to create file";
    }
    return 0;
}



// 0 = No Entry
// 1 = Corridor
// 2 = Staircase
// 3 = Lift
// 4 = Room
// 5 = Washroom
// 6 = Library
// 7 = Play