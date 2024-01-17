#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
public:
    unordered_map<int, bool> visited;
    vector<int> reverseTopologicalArray;

    stack<int> dfs_stack;
    queue<int> bfs_queue;
    unordered_map<int, vector<int>> neighbours;

    void addEdge(int u, int v);

    void addDirectedEdge(int u, int v);

    void BFS(int node);

    void DFS_postorder(int node);

    void DFS_preorder(int node);

    void topologicalSort();
    void DFS_iterative(int node);

    bool cycleDetection(int node);

    bool isBiPartite(int i);
};

void Graph::addEdge(int u, int v)
{
    neighbours[u].push_back(v);
    neighbours[v].push_back(u);
}

void Graph::addDirectedEdge(int u, int v)
{
    neighbours[u].push_back(v);
}
void Graph::DFS_preorder(int node)
{
    visited[node] = true;
    cout << node << " "; // this is what we call traverse or show. You can also store
    for (auto neighbour : neighbours[node])
    {
        if (!visited[neighbour])
        {
            DFS_preorder(neighbour);
        }
    }
}

void Graph::DFS_iterative(int node)
{
    dfs_stack.push(node);
    while (!dfs_stack.empty())
    {
        int top = dfs_stack.top();
        dfs_stack.pop();
        if (!visited[top])
        {
            cout << top << " ";
            visited[top] = true;
            for (auto neighbour : neighbours[top])
            {
                if (!visited[neighbour])
                {
                    dfs_stack.push(neighbour);
                }
            }
        }
    }
}

void Graph::DFS_postorder(int node)
{
    visited[node] = true;
    for (auto neighbour : neighbours[node])
    {
        if (!visited[neighbour])
        {
            DFS_postorder(neighbour);
        }
    }
    cout << node << " "; // this is what we call traverse or show. You can also store
    reverseTopologicalArray.push_back(node);
}

void Graph::topologicalSort()
{
    cout << endl;
    for (int i = reverseTopologicalArray.size() - 1; i >= 0; i--)
    {
        cout << reverseTopologicalArray[i] << " ";
    }
}

void Graph::BFS(int node)
{
    bfs_queue.push(node);
    while (!bfs_queue.empty())
    {
        int first = bfs_queue.front();
        bfs_queue.pop();
        if (!visited[first])
        {
            cout << first << " ";
            visited[first] = true;
            for (auto neighbour : neighbours[first])
            {
                if (!visited[neighbour])
                {
                    bfs_queue.push(neighbour);
                }
            }
        }
    }
}



bool Graph::isBiPartite(int i)
{
    vector<int> color(neighbours.size(), -1);
    color[i] = 1;
    bfs_queue.push(i);
    while (!bfs_queue.empty())
    {
        int front = bfs_queue.front();
        bfs_queue.pop();

        for (auto neighbour : neighbours[front])
        {
            if (color[neighbour] == -1)
            {
                color[neighbour] = 1 - color[front];
                bfs_queue.push(neighbour);
            }

            if (color[neighbour] == color[front])
            {
                return false;
            }
        }
    }

    return true;
}

bool Graph::cycleDetection(int node)
{
    bfs_queue.push(node);
    while (!bfs_queue.empty())
    {
        int front = bfs_queue.front();
        bfs_queue.pop();
        if (!visited[front])
        {
            cout << front << endl;
            visited[front] = true;
            for (auto neighbour : neighbours[front])
            {
                if (!visited[neighbour])
                {
                    cout << "neighbour: " << neighbour << endl;
                    bfs_queue.push(neighbour);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(3, 4);
    // g.addDirectedEdge(0, 1);
    // g.addDirectedEdge(0, 2);
    // g.addDirectedEdge(1, 2);
    // // g.addDirectedEdge(2,0);
    // g.addDirectedEdge(1, 4);
    // g.addDirectedEdge(1, 3);
    // g.addDirectedEdge(3, 5);
    // g.addDirectedEdge(5, 6);
    // g.addDirectedEdge(5, 7);
    // g.addDirectedEdge(5, 8);
    // g.addDirectedEdge(7, 8);
    // g.addDirectedEdge(8, 9);

    if (g.isBiPartite(0))
    {
        cout << "BiPartite";
    }
    else
    {
        cout << "Not BiPartite";
    }
    cout << endl;
}
