#include <iostream> 
#include <string> 
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int p_count = 0;
int recursion(const char* s, int l, int r) {
    p_count++;

    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
    
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}


int main(void) {
    int a;
    vector<string> v;
    cin >> a;
    
    for (int i = 0; i < a; i++) {
        string str; cin >> str;
        v.push_back(str);
    }

    for (int i = 0; i < a; i++) {
        cout << isPalindrome(v[i].c_str()) << " " << p_count << endl;
        p_count = 0;

    }


    return 0;
}