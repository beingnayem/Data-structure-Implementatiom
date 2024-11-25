#include<bits/stdc++.h>
using namespace std;

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

    printAdjList(adj);

    return 0;
}