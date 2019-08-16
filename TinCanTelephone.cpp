//
// Created by nithin muthukumar on 2019-07-23.
//
//solved with divide and conquer
#include <stdc++.h>
using namespace std;
int main(){
    pair<int,int> r;
    cin>>r.first;
    cin>>r.second;
    pair<int,int> j;
    cin>>j.first;
    cin>>j.second;
    int n;
    cin>>n;
    float slope=(float)(r.second-j.second)/(r.first-j.first);
    float b=(float)r.second-slope*r.first;



    int total=0;

    for(int i=0;i<n;i++){
        vector<pair<int,int>> points;
        int k;
        cin>>k;
        for(int w=0;w<k;w++){
            int y,z;
            cin>>y;
            cin>>z;
            points.push_back(make_pair(y,z));
        }
        for(int a=0;a<points.size()-1;a++){
            pair<int,int> m1=points[a/2];
            pair<int,int> m2=points[a/2+1];
            float slope2=(float)(m1.second-m2.second)/(m1.first-m2.first);
            float b2=m1.second-slope*m1.first;
            if(slope-slope2==0){
                continue;
            }
            float x=(b2-b)/(slope-slope2);
            if(min(m1.first,m2.first)<=x&&x<=max(m1.first,m2.first)){
                total+=1;
                break;
            }
        }
    }
    cout<<total<<"\n";

    return 0;
}