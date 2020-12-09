#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    long long int x;
    vector<long long int> numbers;

    int foundNumber;

    while(fin>>x){
        numbers.push_back(x);
    }

    for(int i=25;i<numbers.size();i++){

        int found = 0;

        for(int j=i-25;j<i;j++)
            for(int k=i-25;k<i;k++)
                if(j!=k)
                    if(numbers[j]+numbers[k]==numbers[i]) found=1;

        if(found==0)
            foundNumber = numbers[i];
    }

    cout<<foundNumber<<'\n';

    vector<long long int> partialSum;

    partialSum.push_back(numbers[0]);

    for(int i=1;i<numbers.size();i++)
        partialSum.push_back(partialSum[i-1]+numbers[i]);

    for(int i=0;i<numbers.size();i++)
        for(int j=i+1;j<numbers.size();j++)
            if(partialSum[j]-partialSum[i]==foundNumber){

                long long int maxEl = LLONG_MIN;
                long long int minEl = LLONG_MAX;

                for(int k=j;k>i;k--){
                    if(numbers[k]>maxEl) maxEl = numbers[k];
                    if(numbers[k]<minEl) minEl = numbers[k];
                }

                cout<<maxEl + minEl<<'\n';

            }

    return 0;
}
