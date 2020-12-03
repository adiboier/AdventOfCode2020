#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    ifstream fin("input.txt");

    string input;
    int valid = 0;
    while(getline(fin,input)){

        int minApp = 0;
        int isValid = 0;
        int maxApp = 0;
        int foundDelim = 0;
        int foundCount = 0;
        int countOf = 0;
        int index=0;
        char toCount;
        for(int i=0;i<input.size();i++){
            if(isdigit(input[i]) && foundDelim==0){
                minApp = minApp * 10 + (input[i]-'0');
            }
            else if(input[i]=='-'){
                foundDelim=1;
            }
            else if(isdigit(input[i]) && foundDelim==1){
                maxApp = maxApp * 10 + (input[i]-'0');
            }
            else if(i>0 && input[i-1]==' ' && foundCount==0){
                toCount = input[i];
                foundCount=1;
            }
            else if(foundDelim==1 && foundCount==1 && input[i]!=' ' && input[i]!=':'){
                index++;
                if(index==minApp){
                    if(input[i]==toCount)
                        isValid=1;
                }
                if(index==maxApp && isValid==0){
                    if(input[i]==toCount)
                        isValid=1;
                }
                else if(index==maxApp && isValid==1){
                    if(input[i]==toCount)
                        isValid=0;
                }

            }
        }

        if(isValid==1)
        {
            valid++;
        }
    }

    cout<<valid;
    return 0;
}
