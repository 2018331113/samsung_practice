#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int ANS = INT_MAX;

vector<bool> visited(35, false);


int distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

void wormhole(int sx, int sy, int dx, int dy, int dis, vector<vector<int>>& wormholes){
    ANS = min(ANS, distance(sx, sy, dx, dy) + dis);

    int temp;
    for(int i = 0; i < wormholes.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            
            temp = distance(sx, sy, wormholes[i][0], wormholes[i][1])+ wormholes[i][4] +dis;
            wormhole(wormholes[i][2], wormholes[i][3], dx, dy, temp, wormholes);

            temp = distance(sx, sy, wormholes[i][2], wormholes[i][3])+ wormholes[i][4] + dis;
            wormhole(wormholes[i][0], wormholes[i][1], dx, dy, temp, wormholes);
           
            visited[i] = false;
        }
        
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int sx,sy,dx,dy;
        cin>>n>>sx>>sy>>dx>>dy;
        vector<vector<int>> wormholes(n, vector<int>(5));
        for(int i = 0; i < n; i++){
            visited[i] = false;
            cin>>wormholes[i][0]>>wormholes[i][1]>>wormholes[i][2]>>wormholes[i][3]>>wormholes[i][4];
        }

        wormhole(sx, sy, dx, dy, 0, wormholes);

        cout<<"answer: "<<ANS<<endl;

    }

    return 0;
}