//
// Created by nithin muthukumar on 2019-07-27.
//
#include <stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    map<string,vector<int>> word_amount;
    vector<string> words;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        words.push_back(a);

    }
    int b;
    cin>>b;
    for(int i=0;i<b;i++){
        string a;
        cin>>a;
        word_amount[a].push_back(i);
    }
    for(string word:words){
        for(int i:word_amount[word]){
            cout<<i+1<<"\n";
        }
    }

    return 0;
}
