//
// Created by nithin muthukumar on 2019-07-27.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace nQueens{
    bool is_valid(vector<string> grid,int row,int col,pair<int,int> qPos){
        if(qPos.first==col){
            return false;
        }
        for(int i=0;i<col;i++){
            if(grid[row][i]!='.') {
                return false;
            }
        }
        int i=1;

        while(col-i>=0){
            if(row+i<grid.size()&&grid[row+i][col-i]!='.'){
                return false;

            }if(row-i>=0&&grid[row-i][col-i]!='.'){
                return false;
            }
            i+=1;
        }
        return true;

    }
    vector<string> backtrack(vector<string> grid,int col,pair<int,int> iniQPos){

        if(col==grid.size()){
            return grid;
        }
        if(col==iniQPos.first){
            return backtrack(grid,col+1,iniQPos);
        }

        for(int i=0;i<grid.size();i++){
            if(is_valid(grid,i,col,iniQPos)){
                vector<string> newGrid=grid;

                newGrid[i][col]='Q';

                newGrid=backtrack(newGrid,col+1,iniQPos);

                if(newGrid.size()!=0){
                    return newGrid;
                }
            }

        }
        vector<string> g;
        return g;


    }

    static string solveNQueens(uint_fast16_t n, std::pair<uint_fast16_t, uint_fast16_t> mQC)
    {
        string row(n, '.');
        vector<string> board(n,row);

        board[mQC.second][mQC.first]='Q';
        board=backtrack(board,0,mQC);
        string s="";

        for(auto b:board){
            s+=b+"\n";
            cout<<b<<endl;
        }
        return s;
    }

}
int main(){
    nQueens::solveNQueens(4,make_pair(2,0));
    return 0;
}