#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
bool flag = false;

int r,c;

void dfs(int i, int j, int jmp,vector<vector<int>>& mat, vector<vector<bool>> vis){
    if(i<0||i>r||j<0||j>c) return ;
    if(mat[i][j]== 3){
        flag = true;
        return;
    }
    if(vis[i][j]) return;
    
    vis[i][j] = true;
    if(j+1<c && (mat[i][j+1]== 1 || mat[i][j+1]== 3 ) && !vis[i][j+1])
        dfs(i,j+1,jmp,mat,vis);
    if(j-1>=0 && (mat[i][j-1]== 1 || mat[i][j-1]== 3 ) && !vis[i][j-1])
        dfs(i,j-1,jmp,mat,vis);

    for(int k =1;k<=jmp;k++){
        if(i+k<r && (mat[i+k][j]== 1 || mat[i+k][j]== 3 ) && !vis[i+k][j])
            dfs(i+k,j,jmp,mat,vis);
    }

    for(int k =1;k<=jmp;k++){
        if(i-k>=0 && (mat[i-k][j]== 1 || mat[i-k][j]== 3 ) && !vis[i-k][j])
            dfs(i-k,j,jmp,mat,vis);
    }

}



int main(){

    
    cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    
    for(int i = 0; i<r;i++){
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        dfs(r-1,0,i,mat,visited);
        if(flag){
            cout<<i<<endl;
            break;
        }
    }


}