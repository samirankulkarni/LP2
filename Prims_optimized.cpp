#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cout<<'\n';
    cout<<"enter number of vertices: ";
    cin>>n; cout<<"\n";
    cout<<"enter number of edges: ";
    cin>>m; cout<<'\n';

    vector<vector<pair<int,int>>> graf(n);
    cout<<"enter edges in a b wt format: \n";
    for(int i=0;i<m;i++){
        int a,b,w; cin>>a>>b>>w;
        graf[a].push_back({b,w});
        graf[b].push_back({a,w});
    }
    cout<<"\n";

    vector<int> vis(n,0);
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

    int cost = 0;
    pq.push({0,{0,0}});

    set<int> mst;

    while(mst.size()<n){
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        int a = p.second.first;
        int b = p.second.second;
        if(vis[b]){
            continue;
        }else{
            cout<<"added node from "<<a<<" to "<<b<<" with cost "<<w<<"\n";
            mst.insert(b);
            vis[b] = 1;
            for(auto i:graf[b]){
                int x = i.first;
                int wt = i.second;
                if(!vis[x]) pq.push({wt,{b,x}});
            }
            cost += w;
        }
    }

    cout<<"total cost is "<<cost<<"\n";

    return 0;
}