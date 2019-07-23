//
// Created by nithin muthukumar on 2019-07-22.
//
#include <stdc++.h>
using namespace std;
int hoses_needed(int l,vector<int> houses){
    

}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> houses;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        houses.push_back(x);
    }
    int h;
    cin>>h;
    sort(houses.begin(),houses.end());
    set<int> dists;
    for(int i=0;i<houses.size();i++){
        for(int j=i+1;j<houses.size();j++){
            dists.insert(houses[j]-houses[i]);
            dists.insert(1000000-(houses[j]-houses[i]));
        }
    }
    vector<int> d;
    for(int i:dists){
        d.push_back(i);
    }
    int l=0;
    int u=d.size();
    while(l-u!=1){
        int m=(l+u)/2;
        if(h<hoses_needed(d[m],houses)){
            l=m+1;

        }else{
            u=m;

        }
    }
    cout<<d[0];
    return 0;

}