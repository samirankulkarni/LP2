#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<string> symptoms = {"Fever", "Cough", "Headache", "Sore throat"};

map<string, vector<string>> diseases = {
    {"Common Cold", {"Fever", "Cough", "Headache", "Sore throat"}},
    {"Flu", {"Fever", "Cough", "Headache"}},
    {"Strep Throat", {"Fever", "Sore throat"}},
    {"Migraine", {"Headache"}}
};

vector<string> get_user_input() {
    vector<string> user_symptoms;
    for (const string& symptom : symptoms) {
        cout << "Do you have " << symptom << "? (y/n): ";
        char response;
        cin >> response;
        if (response == 'y' || response == 'Y') {
            user_symptoms.push_back(symptom);
        }
    }
    return user_symptoms;
}

void diagnose() {
    vector<string> user_symptoms = get_user_input();
    vector<string> possible_diseases;

    for (const auto& p : diseases) {
        string disease_name = p.first;
        vector<string> disease_symptoms = p.second;
        for (const string& symptom : disease_symptoms) {
            if (find(user_symptoms.begin(), user_symptoms.end(), symptom) != user_symptoms.end()) {
                possible_diseases.push_back(disease_name);
                break;
            }
        }
    }

    if (!possible_diseases.empty()) {
        cout << "Possible diseases:" << endl;
        for (const string& disease_name : possible_diseases) {
            cout << "- " << disease_name << endl;
        }
    } else {
        cout << "No matching diseases found." << endl;
    }
}

int main() {
    diagnose();
    return 0;
}
