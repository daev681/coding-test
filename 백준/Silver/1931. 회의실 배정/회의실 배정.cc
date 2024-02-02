#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int,int>> v;
    
    while (n--) {
        int f, s;
        cin >> s >> f;
        v.push_back(make_pair(f, s));
        
    }

    sort(v.begin(), v.end());

    int endTime = 0;
    int answer = 0;

    for (const auto& meeting : v) {
        if (meeting.second >= endTime) {
          
            endTime = meeting.first;
            answer++;
        }

    }
     std::cout << answer << std::endl;

    return 0;
}