#include <iostream>
#include <fstream>
using namespace std;

void task1(){

}

int controlFreq[26];

int main()
{
    ifstream fin("input.txt");
    string input;

    string currentGroup="";
    int totalSum=0;
    int yesToAllSum = 0;


    while(getline(fin,input)){

        if(input.size()){

            if(currentGroup==""){
                for(int i=0;i<input.size();i++)
                    controlFreq[input[i]-'a']=1;
            }else{

                int freqCurrent[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                for(int i=0;i<input.size();i++){
                    freqCurrent[input[i]-'a']=1;
                }
                for(int i=0;i<26;i++)
                    controlFreq[i]=controlFreq[i] & freqCurrent[i];
            }
            currentGroup+=input;

        }
        else{
            int groupSum =0;
            int freq[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

            for(int i=0;i<currentGroup.size();i++)
                freq[currentGroup[i]-'a']++;
            for(int i=0;i<26;i++)
            {
                if(controlFreq[i]==1) yesToAllSum++;
                controlFreq[i]=0;
                if(freq[i]>0) groupSum++;
            }
            totalSum+=groupSum;
            currentGroup="";
        }

    }

    if(currentGroup!=""){
        int freq[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

            for(int i=0;i<currentGroup.size();i++)
                freq[currentGroup[i]-'a']++;
            for(int i=0;i<26;i++)
                if(freq[i]>0) totalSum++;
    }

    cout<<totalSum<<'\n'<<yesToAllSum;
    return 0;
}
