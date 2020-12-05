#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    string input;

    int maxID = 0;
    int allIDS[870];
    int index=0;

    while(getline(fin,input)){

        int minRow = 0, maxRow = 127;
        int seatID;

        for(int i=0;i<7;i++){
            if(input[i]=='F') maxRow=(minRow+maxRow)/2;
            else minRow=(minRow+maxRow)/2+1;
        }

        int minColumn = 0, maxColumn = 7;

        for(int i=7;i<10;i++){
            if(input[i]=='R') minColumn=(minColumn+maxColumn)/2+1;
            else maxColumn=(minColumn+maxColumn)/2;
        }

        seatID = minRow*8+minColumn;

        if(seatID>maxID) maxID = seatID;

        allIDS[index] = seatID;
        index++;

    }

    cout<<maxID<<'\n';

    sort(allIDS,allIDS+index);

    int foundSeat = 0;
    for(int i=1;i<index && foundSeat==0;i++){

        if(allIDS[i]>5 && allIDS[i]< 1016){

            if(allIDS[i]-allIDS[i-1]==2){
                cout<<allIDS[i]-1<<' ';
                foundSeat=1;
            }

        }

    }
    return 0;
}
