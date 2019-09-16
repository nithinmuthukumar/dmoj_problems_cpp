//
// Created by nithin muthukumar on 2019-09-02.
//


#include <stdc++.h>
#define f first
#define s second

using namespace std;


int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    cin>>m;
    int cups=0;
    while(true){
        if(pow(pow(2,cups),m)>=n){
            cout<<cups;
            break;
        }else{
            cups+=1;
        }



    }











    return 0;
}