#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> &board){
    cout<<"\n";
    for(int x=0;x<board.size();x++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[x][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool isSafe(int x,int y,vector<vector<char>> &board){
    int n = board.size();
    for(int i=x,j=y;i>=0 && j>=0;i--,j--){ //&& important hai
        if(board[i][j] == 'Q') return false;
    }
    for(int i=x,j=y;i>=0 && j<n;i--,j++){
        if(board[i][j] == 'Q') return false;
    }
    for(int i=x;i>=0;i--){
        if(board[i][y] == 'Q') return false;
    }
    return true;
}

void nQueens(int i,vector<vector<char>> &board,int n){
    if(i >= n){
        printBoard(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(i,j,board)){
            board[i][j] = 'Q';
            nQueens(i+1,board,n);
            board[i][j] = '-';
        }
    }
}

void fun(int i,vector<vector<char>> &board,int n,vector<int> &col
,vector<int> &lowdiag,vector<int> &updiag){
    if(i >= n){
        printBoard(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(col[j]==0 && lowdiag[i+j]==0 && updiag[i+n-1-j]==0){
            board[i][j] = 'Q';
            col[j] = 1;
            lowdiag[i+j] = 1;
            updiag[i+n-1-j] = 1;
            fun(i+1,board,n,col,lowdiag,updiag);
            board[i][j] = '-';
            col[j] = 0;
            lowdiag[i+j] = 0;
            updiag[i+n-1-j] = 0;
        }
    }
}

void nQueensOptimized(int n,vector<vector<char>> &board){
    vector<int> col(n,0);
    int m = 2*n -1;
    vector<int> updiag(m,0),lowdiag(m,0);
    fun(0,board,n,col,lowdiag,updiag);
}

int main(){

    int n;
    cout<<"enter value of n: "; cin>>n;
    cout<<"\n";

    vector<vector<char>> board(n,vector<char>(n,'-'));

    nQueensOptimized(n,board);

    return 0;
}