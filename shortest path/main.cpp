#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

typedef pair<int,int> pint;
class Graph{
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight);

    int dijkstra(int src, int dest, int n);
    
};

void Graph::addEdge(int u, int v, int weight){
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}


int Graph::dijkstra(int src, int dest, int n){
    priority_queue<pint, vector<pint>, greater<pint>> pq;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({src,0});
    while (!pq.empty())
    {
        pint p = pq.top();
        pq.pop();
        int u = p.first;
        int w = p.second;
        
        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int weight = neighbour.second;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist[dest];
    

}

int main(){

    int n,e;
    Graph g;
    cin>>n>>e;
    for(int i = 0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w);
        g.addEdge(v, u, w);
    }

    cout<<"answer: "<<g.dijkstra(0, 2, n);


}