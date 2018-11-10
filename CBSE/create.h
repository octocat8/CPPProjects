#include <string.h>
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

} temp;