//
// Created by nithin muthukumar on 2019-07-19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//don't try too hard to make everything a graph problem
//just traversing it like a sudoku would have worked
bool is_valid(int x,int y,string b[],int r){
    if(0<=x&&x<b[0].size()){
        if(0<=y&& y<r){
            return b[y][x]!='X';

        }
    }
    return false;





}
int main(){
    pair<int,int> cardinal[]={make_pair(0,-1),make_pair(1,0),make_pair(0,1),make_pair(-1,0)};
    cin.sync_with_stdio(0);
    cin.tie(0);
    int r,c,n;
    cin>>r>>c;
    string b[r];
    for(int i=0;i<r;i++){
        cin>>b[i];
    }
    cin>>n;

    char actions[n];
    for(int i=0;i<n;i++){
        cin>>actions[i];

    }
    for(int i=0;i<4;i++){
        for(int yy=0;yy<r;yy++){
            for(int xx=0;xx<c;xx++){
                int x=xx;
                int y=yy;
                int d=i;



                bool valid=true;
                for(char action: actions){


                    if(!is_valid(x,y,b,r)){
                        valid=false;

                        break;

                    }
                    switch(action){
                        case 'F':{

                            pair<int,int> dxy=cardinal[d];
                            x+=dxy.first;
                            y+=dxy.second;
                            break;
                        }
                        case 'L':
                            if(d==0){
                                d=4;
                            }
                            d-=1;break;

                        case 'R':
                            if(d==3){
                                d=-1;
                            }
                            d+=1;break;
                    }
                }
                if(valid&&is_valid(x,y,b,r)){
                    b[y][x]='*';
                }
            }
        }

    }
    for(auto a:b){
        cout<<a<<'\n';
    }

}