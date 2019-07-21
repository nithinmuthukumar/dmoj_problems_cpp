//
// Created by nithin muthukumar on 2019-07-19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t=0;
    int n=0;
    int j=0;
    cin>>t;
    vector<int> stations(t);
    cin>>n;
    cin>>j;
    for(int i=0;i<j;i++){
        int begin,end,num;

        cin>>begin;
        cin>>end;
        cin>>num;
        for(int v=begin-1;v<end;v++){
            stations[v]+=num;
        }
    }
    int sum=0;
    for(int i:stations){
        if(i<n){
            sum+=1;
        }
    }
    cout<<sum<<"\n";




}
int I, N,J;
long long d[100001];
int main()
{
    cin>>I>>N>>J;
    for (int i = 0, x1, x2, k; i < J; i++)
    {
        cin>>x1>>x2>>k;
        x1--;
        d[x1]+=k; d[x2]-=k;
    }
    for (int i = 1 ; i < I; i++)
        d[i] = d[i]+d[i-1];
    int cnt = 0;
    for (int i = 0 ; i < I; i++)
    {
        if (d[i]<N)
            cnt++;
    }
    cout<<cnt<<endl;
}