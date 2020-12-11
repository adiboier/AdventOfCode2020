#include <iostream>
#include <fstream>
using namespace std;

int part1Check(int i,int j, int m,int n,char original[][100]){

    int countOfEmpty = 0;
    if(i-1>=0 && original[i-1][j]=='#') countOfEmpty++;
    if(i-1>=0 && j+1<m && original[i-1][j+1]=='#') countOfEmpty++;
    if(i-1>=0 && j-1>=0 && original[i-1][j-1]=='#') countOfEmpty++;
    if(j-1>=0 && original[i][j-1]=='#') countOfEmpty++;
    if(j+1<m && original[i][j+1]=='#') countOfEmpty++;
    if(i+1<n && original[i+1][j]=='#') countOfEmpty++;
    if(i+1<n && j-1>=0 && original[i+1][j-1]=='#') countOfEmpty++;
    if(i+1<n && j+1<m && original[i+1][j+1]=='#') countOfEmpty++;

    return countOfEmpty;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char seats[100][100];
    char original[100][100];
    int n=0;
    int m=0;

    string input;
    while(getline(fin,input)){

        for(int i=0;i<input.size();i++){
            seats[n][i]=input[i];
            original[n][i]=input[i];
        }

        m = input.size();
        n++;
    }

    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<seats[i][j]<<' ';
        cout<<'\n';
    }*/

    int countOfEmpty;
    int steps = 0;
    bool chaos = true;
    while(chaos){

        chaos = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(seats[i][j]=='L'){
                    countOfEmpty = part1Check(i,j,m,n,original);
                    if(countOfEmpty==0){
                        chaos=true;
                        seats[i][j]='#';
                    }
                }
                else if(seats[i][j]=='#'){
                    countOfEmpty = part1Check(i,j,m,n,original);
                    if(countOfEmpty>=4){
                        chaos=true;
                        seats[i][j]='L';
                    }
                }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                original[i][j]=seats[i][j];
                fout<<seats[i][j];
            }
            fout<<'\n';
        }
        fout<<'\n';
    }

    int occupiedSeats = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(seats[i][j]=='#') occupiedSeats++;
    }


    cout<<occupiedSeats;
    return 0;
}
