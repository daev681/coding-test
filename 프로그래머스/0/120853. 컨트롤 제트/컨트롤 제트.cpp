#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    stack<int> st;
    
    stringstream ss(s);
    string token;
    
 while (getline(ss, token, ' ')) {
        cout << token << endl;
        if (token != " " && token != "Z") { 
            int num = stoi(token);
            answer += num;
            st.push(num);
        } else if (token == "Z" && !st.empty()) {
            int data = st.top();    
            answer -= data;
            st.pop();
        }
    }

    return answer;
}