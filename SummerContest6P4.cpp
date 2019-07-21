//
// Created by nithin muthukumar on 2019-07-19.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    cin>>n>>m;
    pair<int,int> se(-1,-1);

    int grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            grid[i][j]=0;
        }
    }
    for(int i=0, x,y;i<m;i++){
        cin>>x>>y;
        grid[x-1][y-1]=1;
    }
    for(int j=0;j<n;j++){
        bool valid=true;
        for(int i=0;i<n;i++){
            if(grid[i][j]==1){
                valid=false;
            }
        }
        if(valid){
            se.first=j;
            break;
        }
    }
    for(int j=0;j<n;j++){
        bool valid=true;
        for(int i=0;i<n;i++){
            if(grid[j][i]==1){
                valid=false;
            }
        }
        if(valid){
            se.second=j;
            break;
        }
    }
    queue<pair<int,int>> q;
    unordered_set<int> visited;
    q.push(make_pair(se.first,0));
    while(!q.empty()) {

        pair<int,int> p= q.front();
        int next=p.first;
        int cost=p.second;
        q.pop();
        if (next == se.second) {
            cout << p.second<<endl;
            break;
        }
        for (int x=0;x<n;x++) {
            if(grid[next][x]==1){
                q.push(make_pair(x,cost+1));
                visited.insert(x);
            }
        }
    }

}