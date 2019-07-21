//
// Created by nithin muthukumar on 2019-07-19.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
bool is_prime(int p){
    if(p%2==0){
        return false;
    }
    for(int i=3;i<sqrt(p)+1;i+=2){
        if(p%i==0){
            return false;
        }
    }
    return true;
}

using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        for(int d=0;d<q;d++){
            if(is_prime(q-d)&&is_prime(q+d)){
                cout<<q-d<<" "<<q+d<<"\n";
                break;
            }
        }
    }
    return 0;
}
