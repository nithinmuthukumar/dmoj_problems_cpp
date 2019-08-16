//
// Created by nithin muthukumar on 2019-07-23.
//
#include <stdc++.h>
using namespace std;

vector<vector<int>> matrix(10, vector<int>(9, -1));
map<pair<int,int>,vector<pair<int,int>>> adj;

void find_values(pair<int, int> p,set<pair<int, int>> visited) {
    int s=0;
    visited.insert(p);
    for(auto v:adj[p]){
        cout<<v.first<<" "<<v.second<<endl;
        if(find(visited.begin(),visited.end(),v)!=visited.end()){
            return;

        }

        if(matrix[v.second][v.first]==-1){
            cout<<"recursion"<<"\n";
            find_values(v,visited);
            if(matrix[v.second][v.first]==-1){
                return;
            }
        }


        s+=matrix[v.second][v.first];
        cout<<s<<endl;


    }
    matrix[p.second][p.first]=s;
}
int main(){

    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            string x;
            cin>>x;
            if(x.length()>1&&!isdigit(x[0])){
                for(int q=0;q<x.length();q+=3){
                    adj[make_pair(j,i)].push_back(make_pair(x[1]-'1',(int)x[i]-'A'));
                }
            }else{
                matrix[i][j]=stoi(x);
            }

        }
    }
    for(auto a:adj){
        set<pair<int,int>> g;
        find_values(a.first,g);

    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }







    return 0;
}