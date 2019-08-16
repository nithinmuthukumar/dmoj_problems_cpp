//
// Created by nithin muthukumar on 2019-07-30.
//
#include <stdc++.h>
using namespace std;
int main(){
    int t;

    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        queue<int> branch;
        vector<int> cars;
        int num=0;
        for(int j=0;j<n;j++){
            int w;
            cin>>w;
            cars.push_back(w);
        }
        while(!cars.empty()||!branch.empty()) {
            int x=0;
            if (!cars.empty()) {
                int x = cars[cars.size() - 1];
                cars.pop_back();
            }

            if(!branch.empty()&&branch.front()==num+1){
                branch.pop();
                num++;


            }
            else if(x!=0&&num+1==x) {
                num = x;
            }else if(!cars.empty()){
                branch.push(x);



            }else{
                break;
            }


        }
        if(!cars.empty()&&!branch.empty()){
            cout<<"Y"<<endl;
        }else{
            cout<<"N"<<endl;
        }

    }



    return 0;
}