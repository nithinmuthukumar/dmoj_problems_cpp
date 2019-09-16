//
// Created by nithin muthukumar on 2019-07-22.
//

//input=sys.stdin.readline
//n=int(input())
//for i in range(n):
//x,a,b,t=[int(i) for i in input().split()]
//ans=-1
//for i in range(x+1):
//if i*a-(x-i)*b>t:
//ans=i
//
//break
//print(ans)
#include <stdc++.h>

using namespace std;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;

    cin>>n;
    for(int i=0;i<n;i++){
        long x,a,b,t;
        cin>>x>>a>>b>>t;
        long q=(t+x*b)/(a+b)+1;
        if(q>x){
            cout<<-1<<"\n";
        }else {


            cout <<q<< "\n";
        }
    }

    return 0;
}
//Good writing is good
// writing is good
// is good writing.