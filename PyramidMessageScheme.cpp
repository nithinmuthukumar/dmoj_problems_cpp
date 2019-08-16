//
// Created by nithin muthukumar on 2019-07-24.
//
//work on tommorrow
#include <stdc++.h>
#define present(c,x) ((c).find(x) != (c).end())
using namespace std;
/*this problem reduces down to the
 * efficient way being the length of the longest branch
 * vs the number of calls in the dfs
 */
int find_height(string cur,unordered_map<string,vector<string>> adj,int height){
        int max_height=height;
        for(auto a:adj[cur]){
            max_height=max(max_height,find_height(a,adj,height+1));
        }
        return max_height;
}
int main(){
    int L;
    cin>>L;
    int total=0;
    for(int i=0;i<L;i++){
        int n;
        cin>>n;
        unordered_map<string,vector<string>> adj;
        vector<string> names;
        for(int j=0;j<n;j++){
            string name;
            cin>>name;
            names.push_back(name);
        }
        int index=names.size()-1;
        while(index>0){

            string s1=names[index];
            string s2=names[index-1];
            bool p1=present(adj,s1);
            bool p2=present(adj,s2);


            if(!p1&&!p2){
                adj[s1]={};
                adj[s1].push_back(s2);
            }
            if(p1&&!p2) {
                adj[s1].push_back(s2);
            }
            index-=1;
        }
        total+=names.size()*10-find_height(names[names.size()-1],adj,0)*20;
    }
    cout<<total<<"\n";

    return 0;
}
