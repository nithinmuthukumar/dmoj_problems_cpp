/*
PROG: friday
LANG: C++
*/
#include <stdc++.h>
using namespace std;
int main(){
    ifstream in("friday.in");
    ofstream out("friday.out");
    vector<int> wd={0,0,0,0,0,0,0};
    int d=1;
    int m=1;
    int y=1900;
    int n;
    int wdn=0;
    cin>>n;
    while(y!=n+1900){

        int numDays;
        if(m==4||m==6||m==9||m==11){
            numDays=30;
        }else if(m==2){
            if(y%100==0){
                if(y%400==0){
                    numDays=29;
                } else{
                    numDays=28;
                }
            }else{
                if(y%4==0){
                    numDays=29;
                }else{
                    numDays=28;
                }
            }
        }else{
            numDays=31;
        }

        if(d==numDays){
            m+=1;
            if(m==13){
                y+=1;
                m=1;
            }
            d=1;
        }else{
            d+=1;
        }
        wdn+=1;
        if(d==13) {
            wd[wdn % 7] += 1;
        }
    }
    for(int i:wd){
        cout<<i<<" ";

    }
    cout<<endl;

    return 0;
}

//36 33 34 33 35 35 34
//34 33 35 35 34 36 33
