/*
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
map<string,int> peeps;
vector<string> names;
int main(){
    ifstream in("gift1.in");
    ofstream out("gift1.out");
    int n;
    in>>n;
    for(int i=0;i<n;i++){
        string name;
        in>>name;
        names.push_back(name);
        peeps[name]=0;

    }
    for(int i=0;i<n;i++){
        string name;
        in>>name;
        int amount;
        in>>amount;
        int k;
        in>>k;
        if(amount==0){
            continue;
        }
        int to_each=amount/k;
        peeps[name]+=amount-to_each*k-amount;

        for(int j=0;j<k;j++){
            string person;
            in>>person;
            peeps[person]+=to_each;
        }
    }
    for(string name:names){
        out<<name<<" "<<peeps[name]<<"\n";
    }

    return 0;
}