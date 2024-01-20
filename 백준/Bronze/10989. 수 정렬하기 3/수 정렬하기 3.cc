#include <cstdio>
#include <vector>

int main() {
    int N;
    int num;

    std::vector<int> count(10001, 0);
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        count[num] = count[num] + 1; 
    }

    for (int i = 1; i < 10001; i++) {
        for (int j = 1; j <= count[i]; j++) { 
            printf("%d\n", i);
        }
    }

    return 0;
}