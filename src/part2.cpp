#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int checkLoop(vector<string> instructions,int index){

    int visited[1000]={0};
    int j =0;
    int found = 0;
    int accumulator = 0;

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

    if(found==1) return 1;
    else return accumulator;
}

void part2(vector<string>instructions,int index){

    for(int i=0;i<index;i++){
        if(instructions[i].find("nop")!=string::npos){
            vector<string> newInst = instructions;
            newInst[i].replace(0,3,"jmp");
            if(checkLoop(newInst,index)!=1) cout<<checkLoop(newInst,index)<<'\n';
        }
        else if(instructions[i].find("jmp")!=string::npos){
            vector<string> newInst = instructions;
            newInst[i].replace(0,3,"nop");
            if(checkLoop(newInst,index)!=1) cout<<checkLoop(newInst,index)<<'\n';
        }
    }
}
int main()
{
    ifstream fin("input.txt");

    string input;
    vector<string> instructions;
    int index = 0;

    while(getline(fin,input)){
        instructions.push_back(input);
        index++;
    }
    /*for(int i=0;i<index;i++)
        cout<<instructions[i]<<'\n';*/

    part2(instructions,index);

    return 0;
}
