#include <fstream>
#include <iostream>
#include <string.h>
#include "create.h"
using namespace std;
int main() {
    space temp2;
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
}