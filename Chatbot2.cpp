#include <bits/stdc++.h>
using namespace std;

map<string,vector<string>> mp = {
  {"greeting",{"hello","hi how may I help you","welcome"}},
  {"bye",{"goodbye","see you later","I'm glad bye"}},
  {"screen",{"replace screen","check display setiings","replace gorilla glass"}},
  {"battery",{"check battery health","replace battery","check for malware"}},
  {"connection",{"check if sim card present","check network connectivity"}},
  {"audio",{"check in device settings","replace audio drivers"}},
  {"default",{"sorry i didnt get that","I am incapable to answer this"}}
};

set<string> defs = {"greeting","bye","screen","battery","connection","audio","default"};

set<string> fun(string s){
    set<string> st;
    string t = "";
    for(char c:s){
        if(c == ' '){
            st.insert(t);
            t = "";
        }else{
            t += c;
        }
    }
    st.insert(t);
    return st;
}

int main(){

    cout<<"hello I'm a laptop chatbot ask me questions type quit to exit\n";

    while(1){
        string s;
        getline(cin,s);
        for(auto &c:s){
            if(c>='A' && c<='Z'){
                c = 'a' + (c-'A');
            }
        }
        set<string> wl = fun(s);
        bool f = false;
        for(auto str:wl){
            if(str == "quit"){
                cout<<"thanks"<<"\n";
                return 0;
            }
            if(defs.find(str)!=defs.end()){
                int m = mp[str].size();
                int p = rand()%m;
                cout<<mp[str][p]<<"\n";
                f = true;
            }
        }
        if(!f){
            string str = "default";
            int m = mp[str].size();
            int p = rand()%m;
            cout<<mp[str][p]<<"\n";
            f = true;
        }
    }

    return 0;
}