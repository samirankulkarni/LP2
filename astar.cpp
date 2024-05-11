#include <bits/stdc++.h>
using namespace std;

map<char,int> h = {
    {'A',3},{'B',5},{'C',3},{'D',2},{'E',3},{'F',1},{'G',0}
};

map<char,vector<pair<char,int>>> graf = {
    {'A',{{'B',2},{'C',1},{'D',3}}},
    {'B',{{'E',2}}},
    {'C',{{'E',2},{'F',2}}},
    {'D',{{'F',2}}},
    {'E',{{'G',3}}},
    {'F',{{'G',1}}}
};

void AStar(char start,char goal){

    // datastructures used
    map<char,int> g;
    set<char> open_list,closed_list;
    map<char,char> par;

    //start initializations
    g[start] = 0;
    open_list.insert(start);
    par[start] = start;

    while(open_list.size() > 0){

        char n = '\0';

        //check in open list node with least g[c]+h[c] value
        for(auto &c:open_list){
            if(n == '\0' || g[c]+h[c] < g[n] + h[n]){
                n = c;
            }
        }

        if(n == '\0'){
            cout<<"NO PATH EXISTS\n";
            return;
        }

        if(n == goal){
            //do nothing
        }else{
            for(auto &p:graf[n]){
                int nxt = p.first;
                int wt = p.second;
                if(open_list.find(nxt)==open_list.end() && closed_list.find(nxt)==closed_list.end()){
                    g[nxt] = g[n] + wt;
                    par[nxt] = n;
                    open_list.insert(nxt);
                }else if(g[nxt] > g[n]+wt){
                    g[nxt] = g[n] + wt;
                    par[nxt] = n;
                    if(closed_list.find(nxt)!=closed_list.end()){
                        closed_list.erase(nxt);
                        open_list.insert(nxt);
                    }
                }
            }
        }

        if(n == goal){
            vector<char> ans;
            while(par[n]!=n){
                ans.push_back(n);
                n = par[n];
            }
            ans.push_back(start);
            reverse(ans.begin(),ans.end());
            cout<<"OPTIMAL PATH: ";
            for(char i:ans) cout<<i<<' ';
            cout<<"\n";
            cout<<"OPTIMAL PATH LENGTH: "<<g[goal]<<"\n";
            return;
        }

        open_list.erase(n);
        closed_list.insert(n);
    }
}

int main(){

    AStar('A','G');

    return 0;
}