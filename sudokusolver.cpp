//
// Created by nithin muthukumar on 2019-08-08.
//
#include <stdc++.h>
#include <unordered_set>

using namespace std;


vector<int> getPossibilities(pair<int,int> curPos,vector<vector<int>> grid){

    unordered_set<int> nums;
    int x=curPos.first;
    int y=curPos.second;
    for(int i=0;i<9;i++){
        nums.insert(grid[y][i]);
        nums.insert(grid[i][x]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            nums.insert(grid[i+(y/3)*3][j+(x/3)*3]);
        }
    }
    vector<int> possibilities={};
    for(int i=1;i<=9;i++){
        if(nums.find(i)==nums.end()){
            possibilities.push_back(i);

        }
    }
    return possibilities;




}
pair<int,int> nextPos(pair<int,int> curPos){
    if(curPos.first==8){
        curPos.first=0;
        curPos.second+=1;
    }else{
        curPos.first+=1;
    }
    return curPos;
}
vector<vector<int>> backtrack(pair<int,int> curPos,vector<vector<int>> grid){
    if(curPos.second==9){
        return grid;
    }
    if(grid[curPos.first][curPos.second]!=0){
        return backtrack(nextPos(curPos),grid);
    }
    for(auto i:getPossibilities(curPos,grid)){
        vector<vector<int>> newGrid=grid;
        newGrid[curPos.second][curPos.first]=i;
        newGrid=backtrack(nextPos(curPos),newGrid);
        if(!newGrid.empty()){
            return newGrid;
        }
    }
    grid.empty();
    return grid;
}
void solver(vector<vector<int>> grid){
    grid=backtrack(make_pair(0,0),grid);

}
void printGrid(vector<vector<int>> grid){

    for(auto b:grid){
        for(int n:b){
            cout<<n<<" ";

        }
        cout<<endl;

    }
}
vector<vector<int>> sudoku_generator(){
    vector<vector<int>> grid(9,vector<int>(9,0));
    for(int y=0;y<9;y++){
        for(int x=0;x<9;x++){
            printGrid(grid);
            vector<int> p=getPossibilities(make_pair(x,y),grid);
            random_shuffle(p.begin(),p.end());
            for(int i:p){
                cout<<i<<" ";
            }
            cout<<endl;

            grid[y][x] = p[0];

        }
    }
    return grid;



}

int main(){
    printGrid(sudoku_generator());



    return 0;
}


