#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;



bool isValid(int x, int y, int n, int m){
    if(x>=0 && x<n && y>=0 && y<m){
        return true;
    }
    return false;
}


vector<pair<int,int>> neighbors(int x, int y, int n, int m){
    vector<pair<int,int> > v;
    if(isValid(x-1,y,n,m)){
        v.push_back(make_pair(x-1,y));
    }
    if(isValid(x+1,y,n,m)){
        v.push_back(make_pair(x+1,y));
    }
    if(isValid(x,y-1,n,m)){
        v.push_back(make_pair(x,y-1));
    }
    if(isValid(x,y+1,n,m)){
        v.push_back(make_pair(x,y+1));
    }

    return v;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
    queue<pair<int,int> > q;
    int n = image.size();
    int m = image[0].size();
    int oldColor = image[sr][sc];
    q.push(make_pair(sr,sc));
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        image[p.first][p.second] = newColor;
        vector<pair<int,int>> v = neighbors(p.first,p.second,n,m);
        for(int i=0;i<v.size();i++){
            if(image[v[i].first][v[i].second] == oldColor){
                q.push(v[i]);
            }
        }
    }

    return image;

}
int main(){

    vector<vector<int>> image = { 
{1, 1, 1, 1, 1, 1, 1, 1}, 
{1, 1, 1, 1, 1, 1, 0, 0}, 
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 2, 2, 2, 2, 0, 1, 0}, 
{1, 1, 1, 2, 2, 0, 1, 0}, 
{1, 1, 1, 2, 2, 2, 2, 0}, 
{1, 1, 1, 1, 1, 2, 1, 1}, 
{1, 1, 1, 1, 1, 2, 2, 1}} ;
    int sr = 4, sc = 4, newColor = 3;

    image = floodFill(image,sr,sc,newColor);

    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[0].size();j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
    

}