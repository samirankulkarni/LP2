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

    set<int> mst; // vertices that are in mst
    int cost = 0;

    mst.insert(0);

    while(mst.size() != n){
        priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
        for(int i:mst){
            for(auto p:graf[i]){
                int x = p.first;
                int w = p.second;
                if(mst.find(x) == mst.end()){
                    pq.push({{w,x},i});
                }
            }
        }
        auto p = pq.top();
        int w = p.first.first;
        int a = p.first.second;
        int b = p.second;
        cout<<"edge from "<<a<<" to "<<b<<" added with weight "<<w<<'\n';
        mst.insert(a);
        cost += w;
    }

    cout<<"cost is"<<cost<<'\n';

    return 0;
}