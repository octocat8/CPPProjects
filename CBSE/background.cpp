#include <iostream>
#include <string.h>
#include <fstream>
#include "create.h"
using namespace std;
int main() {
    ofstream fout;  
    fout.open("layout.dat", ios::out);
    if(fout) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 7; j++) {
                for(int k = 0; k < 10; k++) {
                    temp.getSpaceVal(i, j, k);
                    fout.write((char *)&temp, sizeof(temp));
                }
                cout<<endl<<"End row"<<endl;
            }
            cout<<endl<<"End floor"<<endl;
        }
        fout.close();
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