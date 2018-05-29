#include<iostream>
#include<iomanip>
using namespace std;
#define n 8
#define endl '\n'
int board[n][n];
int gboard[n][n];
int score,sum;

bool isSafe(int col,int row){
	for(int i=0;i<col;i++){
		if(board[row][i])return false;
	}
	
	for(int i=row,j=col;i>=0 && j >=0;j--,i--){
		if(board[i][j])return false;
	}
	
	for(int i=row,j=col;i<n && j>=0;j--,i++){
		if(board[i][j])return false;
	}
	return true;
}


void backtrack(int col){
    if(col ==n){
        score=max(score,sum);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(col,i)){
            board[i][col]=1;
            sum += gboard[i][col];
            backtrack(col+1);
            board[i][col]=0;
            sum -= gboard[i][col];
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    
    int m;
    cin >> m;
    for(int k=0;k<m;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> gboard[i][j];
                board[i][j]=0;
            }
        }
        score=0,sum=0;
        backtrack(0);
        cout<<setw(5)<<setiosflags(ios::right)<<score<<endl;
        
    }
}
