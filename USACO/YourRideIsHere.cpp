/*
PROG: ride
LANG: C++
*/
#include <stdc++.h>
using namespace std;
int main(){
    ifstream in ("ride.in");
    ofstream out ("ride.out");
    string comet;
    in>>comet;
    int cprod=1;
    string group;
    int gprod=1;
    in>>group;
    for(char c:comet){
        cprod*=c-'A'+1;
    }
    for(char g:group){
        gprod*=g-'A'+1;
    }
    if(gprod%47==cprod%47){
        out<<"GO"<<"\n";
    }else{
        out<<"STAY"<<"\n";
    }


    return 0;
}