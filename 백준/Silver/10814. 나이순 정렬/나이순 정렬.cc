#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    

    map<int, vector<string>> members;
    
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age;
        cin.ignore(); 
        getline(cin, name);
        
        members[age].push_back(name);
    }
    
   
    for (const auto& entry : members) {
        for (const auto& name : entry.second) {
            cout << entry.first << ' ' << name << endl;
        }
    }

    return 0;
}
