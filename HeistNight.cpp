//
// Created by nithin muthukumar on 2019-09-08.
//

using namespace std;

#include <stdc++.h>

set<int> nums;
int find_height(int p,int x,vector<vector<int>> paths){
    nums.erase(p);
    int h=0;
    for(int i:paths[p-1]){
        if(i!=x){
            h+=find_height(i,x,paths);
        }
    }
    return h+1;
}
int find_qth(int j,vector<vector<int>> paths,int k){

    for(int i=1;i<=paths.size();i++){
        if(i!=j){ nums.insert(i);}
    }
    vector<int> heights;
    while(!nums.empty()) {
        int n = *nums.begin();

        heights.push_back(find_height(n,j,paths));
    }
    if(k-1>=heights.size()){
        return -1;
    }
    sort(heights.begin(),heights.end(),greater<int>());
    return heights[k-1];




}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> paths(n,vector<int>());
    for(int i=0;i<n-1;i++){
        int r,u;
        cin>>r>>u;
        paths[r-1].push_back(u);

    }

    for(int i=0;i<q;i++){
        int j,k;
        cin>>j>>k;
        cout<<find_qth(j,paths,k)<<"\n";
        nums.clear();

    }
}