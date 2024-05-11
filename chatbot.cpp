#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> responses = {
    {"greeting", {"Hello!", "Hi there!", "Greetings!", "Hey!"}},
    {"farewell", {"Goodbye!", "Farewell!", "Take care!", "See you later!"}},
    {"mobile_screen", {"Try adjusting the brightness settings.", "Check for any cracks on the screen.", "Restart your phone.", "Update your phone's software."}},
    {"battery_issue", {"Make sure your charger is working properly.", "Check for any background apps draining the battery.", "Try using a different charger.", "Consider replacing the battery."}},
    {"display", {"Check the display settings on your device.", "Restart your device to see if the issue resolves.", "Adjust the screen resolution.", "Update your graphics drivers."}},
    {"network_error", {"Check your internet connection.", "Restart your router or modem.", "Contact your internet service provider.", "Try connecting to a different network."}},
    {"default", {"I'm sorry, I didn't quite catch that.", "Could you please repeat?", "I'm not sure I understand.", "Let me get back to you on that.", "Please provide more details."}}
};

bool contains(string txt,string word){
    string t = "";
    for(auto &c:txt){
        if(c==' '){
            if(t==word) return true;
            t = "";
        }else{
            t += c;
        }
    }
    if(t==word) return true;
    return false;
}

void print(string prompt){
    vector<string> v = responses[prompt];
    int n = v.size();
    int i = rand()%n;
    cout<<v[i]<<'\n';
}

int main(){

    string input;

    cout<<"\nHello I'm a moblie service chatbot how may I assist you today!\n";

    while(1){

        getline(cin,input);
        transform(input.begin(),input.end(),input.begin(),::tolower);

        if(input=="bye" || input=="exit"){
            cout<<"Thanks for using me\n";
            break;
        }

        if(contains(input,"hi") || contains(input,"hello")){
            print("greeting");
        }else if(contains(input,"break") || contains(input,"screen")){
            print("mobile_screen");
        }else if(contains(input,"drain") || contains(input,"battery")){
            print("battery_issue");
        }else if(contains(input,"bright") || contains(input,"display")){
            print("display");
        }else if(contains(input,"connection") || contains(input,"network")){
            print("network_error");
        }else{
            print("defualt");
        }

    }

    return 0;
}