//
// Created by nithin muthukumar on 2019-07-19.
//

//not done
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int d;
    cin>>d;
    int t;
    cin>>t;
    int dp[d+1];
    memset(dp, 0, sizeof dp);
    int a[d];
    for(int i=0;i<t;i++){
        cin>>a[i];

    }
    for(int i=0;i<d;i++){
        for(int j=0;j<t;j++){
            if(a[j]<=i){
                cout<<dp[i]<<endl;
                dp[i]=max(dp[i],dp[i-a[j]]+1);


            }
        }
    }

    cout<<dp[d];
    return 0;


}