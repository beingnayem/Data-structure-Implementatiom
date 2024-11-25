#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin>>n>>e;
    int adj[n][n]={0};

// input the edges in adjency matrix
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

// print the adjency matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}