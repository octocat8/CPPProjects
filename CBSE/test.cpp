#include <fstream>
#include <iostream>
#include "create.h"
using namespace std;
int main() {
    ifstream fin;
    fin.open("layout.dat", ios::in | ios::binary);
    if(fin) {
    fin.read((char *)&temp, sizeof(temp));
        while(!fin.eof()) {
            temp.putSpaceVal();
            fin.read((char *)&temp, sizeof(temp));

        }
    fin.close();
    } else {
        cout<<"Unable to open file;";
    }
    return 0;
}