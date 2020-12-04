#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int checkYear(char char_array[], int position, int limit1,int limit2){

    int no = 0;
    int valid = 1;
    int i=position+4;
    while(i<position+8){

        if(!isdigit(char_array[i]))
            return 0;
        else{
            no=no*10+(char_array[i]-'0');
        }
        i++;

    }

    if(no>=limit1 && no<=limit2)
        return 1;
    else return 0;
}

int checkEcl(char char_array[],int position){

     int i=position+4;

     char eyeCl[3];
     int index=0;

     while(i<position+7){
        eyeCl[index]=char_array[i];
        index++;
        i++;
     }

     if(strstr(eyeCl,"amb") ||
        strstr(eyeCl,"blu") ||
        strstr(eyeCl,"brn") ||
        strstr(eyeCl,"gry") ||
        strstr(eyeCl,"grn") ||
        strstr(eyeCl,"hzl") ||
        strstr(eyeCl,"oth"))
            return 1;

     return 0;

}

int checkHcl(char char_array[],int position){

    int i=position+4;

    if(char_array[i]!='#')
        return 0;
    else{

        i++;
        for(int j=i;j<i+6;j++)
        if(!isdigit(char_array[j])){

            if(char_array[j]<'a' || char_array[j]>'f')
                return 0;
        }

    }

    return 1;


}

int checkHgt(char char_array[],int position){

    int i=position+4;
    int no=0;

    for(int j=i;j<i+4;j++){
        if(isdigit(char_array[j]))
            no=no*10 + (char_array[j]-'0');
        else{
            if(char_array[j]=='c' && char_array[j+1]=='m'){
                if(no>=150 && no<=193) return 1;
            }
            else if(char_array[j]=='i' && char_array[j+1]=='n'){
                if(no>=59 && no<=76) return 1;
            }

        }
    }

    return 0;
}

int checkPid(char char_array[],int n,int position){
    int i=position+4;
    int digits=0;

    for(int j=i;j<n;j++){
        if(isdigit(char_array[j]))
            digits++;
        else{
            if(digits==9) return 1;
            else return 0;
        }
    }

    return 1;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string input;
    int valid = 0;
    string currentPassport = "";

    while(getline(fin,input)){

        if(input.size())
            currentPassport+=input;
        else{

            int n = currentPassport.length();
            char char_array[n + 1];
            strcpy(char_array, currentPassport.c_str());


            if(strstr(char_array,"hcl") &&
               strstr(char_array,"ecl") &&
               strstr(char_array,"pid") &&
               strstr(char_array,"byr") &&
               strstr(char_array,"iyr") &&
               strstr(char_array,"eyr") &&
               strstr(char_array,"hgt")){

                  int byrPos = strstr(char_array,"byr") - char_array;

                  int iyrPos = strstr(char_array,"iyr") - char_array;

                  int eyrPos = strstr(char_array,"eyr") - char_array;

                  int eclPos = strstr(char_array,"ecl") - char_array;

                  int hgtPos = strstr(char_array,"hgt") - char_array;

                  int pidPos = strstr(char_array,"pid") - char_array;

                  int hclPos = strstr(char_array,"hcl") - char_array;

                  if(checkYear(char_array,byrPos,1920,2002)==1
                     && checkYear(char_array,iyrPos,2010,2020)==1
                     && checkYear(char_array,eyrPos,2020,2030)==1
                     && checkEcl(char_array,eclPos)==1
                     && checkHcl(char_array,hclPos)==1
                     && checkPid(char_array,n,pidPos)==1
                     && checkHgt(char_array,hgtPos)==1
                     )
                    {
                      valid++;
                      fout<<currentPassport<<endl;
                    }
               }

            currentPassport="";
        }
    }

    cout<<valid;


    return 0;
}
