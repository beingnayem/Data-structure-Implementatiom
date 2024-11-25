#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ls){
    visited[node]=true;
    ls.push_back(node);
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, ls);
        }
    }
}

void graphDFS(int nodes, vector<vector<int>> &adj, vector<int> &ls){
    vector<bool> visited(nodes, false);
    int cnt=0;
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            dfs(i, adj, visited, ls);
        }
    }
}

void printAdjList(vector<vector<int>> &adj){
    cout<<"Adjacency List:"<<endl;
    for(int i=0; i<adj.size(); i++){
        cout<<i<<"->";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int n, e;
    cin>>n>>e;

    vector<vector<int>> adj(n, vector<int>());

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ls;
    graphDFS(n, adj, ls);

    printAdjList(adj);

    cout<<"DFS Traversal:"<<endl;
    for(auto i: ls){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}