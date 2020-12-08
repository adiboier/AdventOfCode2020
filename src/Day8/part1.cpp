#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int visited[1000];
int main()
{
    ifstream fin("input.txt");

    string input;
    vector<string> instructions;
    int index = 0;
    int accumulator = 0;

    while(getline(fin,input)){
        instructions.push_back(input);
        index++;
    }
    /*for(int i=0;i<index;i++)
        cout<<instructions[i]<<'\n';*/

    int j =0;
    int found = 0;

    while(found==0 && j<index){

        visited[j]=1;
        int no=0;
        string currentInstruction = instructions[j];

        for(int i=5;i<currentInstruction.size();i++)
            no=no*10+(currentInstruction[i]-'0');

        if(currentInstruction[4]=='-') no*=(-1);

        if(currentInstruction.find("acc")!=string::npos){
            accumulator+=no;
            j++;
        }
        else if(currentInstruction.find("jmp")!=string::npos){
            if(visited[j+no]==1) found=1;
            else j+=no;
        }
        else j++;

    }

    cout<<accumulator;

    return 0;
}
