//
// Created by nithin muthukumar on 2019-09-02.
//
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    cin>>m;
    int min=1001;
    int x=0;
    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<m;j++){
            int f;
            cin>>f;
            if(f==1||f==10){
                t+=1;
            }
        }
        if(t<min){
            min=t;
            x=i;
        }
    }
    cout<<x+1;


    return 0;
}