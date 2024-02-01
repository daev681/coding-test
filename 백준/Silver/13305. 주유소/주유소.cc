#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    vector<long long> roadLengths(n - 1, 0);
    vector<long long> fuelPrices(n, 0);

    for (int i = 0; i < n - 1; i++) {
        cin >> roadLengths[i];
    }


    for (int i = 0; i < n; i++) {
        cin >> fuelPrices[i];
    }

    long long answer = 0;
    long long minFuelPrice = fuelPrices[0];

    for (int i = 0; i < n - 1; i++) {
   
        minFuelPrice = min(minFuelPrice, fuelPrices[i]);

   
        answer += minFuelPrice * roadLengths[i];
    }

    cout << answer << endl;

    return 0;
}