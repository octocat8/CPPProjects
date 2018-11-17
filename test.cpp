#include <fstream>
#include <iostream>
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
}temp;
int main() {
    ifstream fin;
    fin.open("layout.dat", ios::in | ios::binary);
    if (fin) {
        fin.read((char *)&temp, sizeof(temp));
        while(!fin.eof()) {
            temp.putSpaceVal();
            fin.read((char *)&temp, sizeof(temp));
        }
    } else {
        cout<<"Unable to open file\n\n";
    }
}