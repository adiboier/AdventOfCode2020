#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    int input;

    vector<int> numbers;
    numbers.push_back(0);

    while(fin>>input){
        numbers.push_back(input);
    }

    sort(numbers.begin(),numbers.end());

    int ones = 0, threes=0;
    for(int i=1;i<numbers.size();i++)
        if(numbers[i]-numbers[i-1]==1) ones++;
        else threes++;

    cout<<ones*(threes+1)<<'\n';

    vector<long long int> dp;
    dp.push_back(1);

    for(int i=1;i<numbers.size();i++){

        int possibilities = 0;

        if(i-1>=0 && numbers[i]-numbers[i-1]<=3)
            possibilities++;
        if(i-2>=0 && numbers[i]-numbers[i-2]<=3)
            possibilities++;
        if(i-3>=0 && numbers[i]-numbers[i-3]<=3)
            possibilities++;

        if(possibilities==1)
            dp[i] = dp[i-1];
        else if(possibilities==2)
            dp[i] = dp[i-1] + dp[i-2];
        else if(possibilities==3)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    }

    cout<<dp[numbers.size()-1];
    return 0;
}
