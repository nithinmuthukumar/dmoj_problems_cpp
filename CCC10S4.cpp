//
// Created by nithin muthukumar on 2019-08-04.
//
#include <stdc++.h>
using namespace std;
vector<pair<int,int>> adjl[1010];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int M;
    cin>>M;

    for(int i=0;i<M;i++){
        int e;
        cin>>e;
        vector<int> corners;
        for(int j=0;j<e;j++){
            int w;
            cin>>w;
            corners.push_back(w);
        }
        for(int j=0;j<e-1;j++){
            int w;
            cin>>w;
            adjl[i].push_back(make_pair(corners[e],corners[e+1]));
        }
    }


    return 0;
}