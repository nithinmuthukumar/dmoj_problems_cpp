//
// Created by nithin muthukumar on 2019-07-22.
//
//actually easy
//sort all values and find the difference between the first and second value
//theres more to the compare to maximize the value but mine works for some reason
#include <stdc++.h>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;

}
int main(){
    pair<int,int> d[1001];
    for(int i=0;i<1001;i++){
        d[i]=make_pair(i,0);
    }
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        d[x].second+=1;

    }
    int z = sizeof(d)/sizeof(d[0]);
    sort(d,d+1001,compare);

    cout<<abs(d[0].first-d[1].first);
    return 0;
}