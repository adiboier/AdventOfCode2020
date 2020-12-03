#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    int columnIndex3D = 0;
    int columnIndex1D = 0;
    int columnIndex5D = 0;
    int columnIndex7D = 0;
    int columnIndex1R2D = 0;
    int currentRow = 0;
    string input;

    int trees3D = 0, trees1D = 0, trees5D = 0, trees7D = 0, trees1R2D = 0;
    while(getline(fin,input)){
        //cout<<input<<endl;
        if(columnIndex3D>=input.size())
            columnIndex3D=columnIndex3D%input.size();
        if(input[columnIndex3D]=='#') trees3D++;
        columnIndex3D+=3;

        if(columnIndex1D>=input.size())
            columnIndex1D=columnIndex1D%input.size();
        if(input[columnIndex1D]=='#') trees1D++;
        columnIndex1D++;

        if(currentRow%2==0){
            if(columnIndex1R2D>=input.size())
                columnIndex1R2D=columnIndex1R2D%input.size();
            if(input[columnIndex1R2D]=='#') trees1R2D++;

            columnIndex1R2D++;
        }

        if(columnIndex5D>=input.size())
            columnIndex5D=columnIndex5D%input.size();
        if(input[columnIndex5D]=='#') trees5D++;
        columnIndex5D+=5;

        if(columnIndex7D>=input.size())
            columnIndex7D=columnIndex7D%input.size();
        if(input[columnIndex7D]=='#') trees7D++;
        columnIndex7D+=7;

        currentRow++;
    }

    /*int trees = 0;

    int searchRow = 0, searchColumn = 0;
    while(searchRow < rowIndex || searchColumn < columnIndex){
        if(maP[searchRow][searchColumn]=='#'){
            trees++;
        }
        searchRow++;
        searchColumn+=3;
    }*/

    cout<<trees1D<<' '<<trees3D<<' '<<trees5D<<' '<<trees7D<<' '<<trees1R2D<<'\n';

    return 0;
}
