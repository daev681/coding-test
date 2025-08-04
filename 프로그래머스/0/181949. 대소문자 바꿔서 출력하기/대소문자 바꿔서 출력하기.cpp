#include <iostream>
#include <string>
#include <cctype>  // toupper, tolower

using namespace std;

int main() {
    string str;
    cin >> str;

    for (char& c : str) {
        if (islower(c)) c = toupper(c);  // 소문자 → 대문자
        else if (isupper(c)) c = tolower(c);  // 대문자 → 소문자
    }

    cout << str << endl;
    return 0;
}