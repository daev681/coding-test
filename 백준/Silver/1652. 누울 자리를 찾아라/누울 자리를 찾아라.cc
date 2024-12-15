#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> sv(n);


    for (int i = 0; i < n; i++) {
        cin >> sv[i];
    }

    int row_count = 0, col_count = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (sv[i][j] == '.') {
                count++;
            } else {
                if (count >= 2) {
                    row_count++;
                }
                count = 0; // Reset
            }
        }
        if (count >= 2) {
            row_count++; 
        }
    }

   
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (sv[i][j] == '.') {
                count++;
            } else {
                if (count >= 2) {
                    col_count++;
                }
                count = 0; 
            }
        }
        if (count >= 2) {
            col_count++; 
        }
    }

    cout << row_count << " " << col_count;

    return 0;
}
