#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int l,vector<int> &vis,vector<vector<int>> &graf){ //levels bhi print hone chaiye
    if(vis[i]) return;
    cout<<"we visit node "<<i<<" with its level of "<<l<<'\n';
    vis[i] = 1;
    for(int j:graf[i]) dfs(j,l+1,vis,graf);
}

void bfs(vector<vector<int>> &graf){
    int n = graf.size();
    vector<int> vis(n,0);
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first;
        int l = p.second;
        vis[x] = 1;
        cout<<"visited node "<<x<<" at level "<<l<<'\n';
        for(int j:graf[x]){
            if(!vis[j]){
                vis[j] = 1;
                q.push({j,l+1});
            }
        }
    }
}

void bfs_rec(queue<pair<int,int>> &q,vector<int> &vis,vector<vector<int>> &graf){
    if(q.empty()) return;
    auto p = q.front();
    q.pop();
    int x = p.first;
    int l = p.second;
    vis[x] = 1;
    cout<<"visited node "<<x<<" at level "<<l<<'\n';
    for(int j:graf[x]){
        if(!vis[j]){
            vis[j] = 1;
            q.push({j,l+1});
        }
    }
    bfs_rec(q,vis,graf);
}

int main(){

    int n; 
    cout<<"enter number of vertices: "; cin>>n; cout<<'\n';
    int m;
    cout<<"enter number of edges in graph: "; cin>>m; cout<<'\n';

    vector<vector<int>> graf(n);
    cout<<"enter "<<m<<" edges in a b format: \n";
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    cout<<"assuming 0 as start\n";
    vector<int> vis(n,0);
    queue<pair<int,int>> q;
    q.push({0,0});
    bfs_rec(q,vis,graf);

    return 0;
}