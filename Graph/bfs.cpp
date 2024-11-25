#include<bits/stdc++.h>
using namespace std;

vector<int> graphBFS(int nodes, vector<vector<int>> &adj){
    vector<bool> visited(nodes, false);
    queue<int> q;
    vector<int> ls;
    visited[0]=true;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ls.push_back(node);
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return ls;
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

    vector<int> ls = graphBFS(n, adj);

    printAdjList(adj);

    cout<<"BFS Traversal:"<<endl;
    for(auto i: ls){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}