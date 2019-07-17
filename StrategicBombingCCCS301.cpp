#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;
bool findPath(map<char,unordered_set<char>> paths,char v,char t){

    queue<char> q;
    unordered_set<char> visited;
    q.push('A');
    while(!q.empty()){

        char next =q.front();

        q.pop();
        if(next=='B'){
            return true;
        }
        for(char c:paths[next]){
            if((c==v&&next==t)||(c==t&&next==v)){
                continue;
            }
            if(visited.find(c)==visited.end()){
                q.push(c);
                visited.insert(c);
            }


        }
    }
    return false;



}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    map<char,unordered_set<char>> paths;



    while(true){
        string x="";
        cin>>x;
        if(x!="**"){
            if(paths[x[0]].find(x[1])==paths[x[0]].end()){


            }

            paths[x[0]].insert(x[1]);
            paths[x[1]].insert(x[0]);
        }
        else{
            break;
        }
    }



    set<string> answers;
    for(pair<char,unordered_set<char>> p:paths){


        for(char v:p.second){
            if(!findPath(paths,p.first,v)){
                string ans=(string(1,p.first)+v);
                sort(ans.begin(),ans.end());

                answers.insert(ans);

            }
        }
    }
    for(string answer: answers){
        cout<<answer<<"\n";
    }
    cout<<"There are "+to_string(answers.size())+" disconnecting roads."<<"\n";


    return 0;
}
