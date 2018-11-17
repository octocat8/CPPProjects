#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class space{
    int pos[3]; 
    int posval;
    char room_name[20];
    public:
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
    void setObjVal(int a, int b, int c, int d, char const* e) {
        pos[0] = a;
        pos[1] = b;
        pos[2] = c;
        posval = d;
        strncpy(room_name, e, 20);
    }
}temp, temp2;
int main() {
    char ch; long pos;
    ifstream fin("layout.dat", ios::in);
    ofstream fout("school.dat", ios::out | ios::binary);
    fin.read((char *)&temp, sizeof(temp));
    while(!fin.eof()) {
        temp.putSpaceVal();
        cout<<"Do you wish to modify the data?";
        cin>>ch;
        if(ch == 'y') {
            int d;
            char e[20];
            cout<<"Enter Pos Val: ";cin>>d;
            if(d == 0) {
                strncpy(e, "No Entry", 20);
            } else if (d == 1) {
                strncpy(e, "Corridor", 20);
            } else if (d == 2) {
                strncpy(e, "Staircase", 20);
            } else if (d == 3) {
                strncpy(e, "Lift", 20);
            } else if (d == 5) {
                strncpy(e, "Washroom", 20);
            } else if (d == 6) {
                strncpy(e, "Library", 20);
            } else if (d == 7) {
                strncpy(e, "Play Area", 20);
            } else {
                cin.ignore();
                cout<<"Enter the name of the room: ";
                cin.getline(e, 20);
            }
            temp2.setObjVal(temp.returnLevel(), temp.returnRow(), temp.returnCol(), d, e);
            fout.write((char *)&temp2, sizeof(temp2));
        } else {
            temp2.setObjVal(temp.returnLevel(), temp.returnRow(), temp.returnCol(), temp.returnSpaceVal(), temp.returnRoomVal());
            fout.write((char *)&temp2, sizeof(temp2));
        }
        fin.read((char *)&temp, sizeof(temp));
    }
    fin.close();
    fout.close();
    remove("layout.dat");
    rename("school.dat","layout.dat");
    return 0;
}