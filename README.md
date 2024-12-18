### 시험 치기전 필수 메서드


1. **알파벳 순환 시프트 (Caesar Cipher)** 
위에서 제공된 함수처럼 알파벳을 순환적으로 시프트하는 함수입니다.


```cpp
char shift_char(char c, int shift) {
    if ('a' <= c && c <= 'z') {
        return (c - 'a' + shift) % 26 + 'a';
    }
    else if ('A' <= c && c <= 'Z') {
        return (c - 'A' + shift) % 26 + 'A';
    }
    return c;
}
```


---

2. **소수 판별 함수** 
숫자가 소수인지 판별하는 함수입니다.


```cpp
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```


---

3. **문자열 회문 판별 함수** 
문자열이 회문(앞뒤가 동일한 문자열)인지 확인하는 함수입니다.


```cpp
bool is_palindrome(const std::string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}
```


---

4. **배열에서 최댓값/최솟값 찾기** 
배열에서 최댓값 또는 최솟값을 찾는 함수입니다.


```cpp
int find_max(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

int find_min(const std::vector<int>& arr) {
    return *std::min_element(arr.begin(), arr.end());
}
```


---

5. **배열의 합 구하기** 
배열의 모든 원소 합을 구하는 함수입니다.


```cpp
int sum_of_array(const std::vector<int>& arr) {
    return std::accumulate(arr.begin(), arr.end(), 0);
}
```


---

6. **팩토리얼 구하기** 
정수의 팩토리얼을 구하는 함수입니다.


```cpp
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
```


---

7. **최대공약수 (GCD)와 최소공배수 (LCM)** 
최대공약수(GCD)와 최소공배수(LCM)를 구하는 함수입니다.


```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
```


---

8. **문자열 뒤집기** 
문자열을 뒤집는 함수입니다.


```cpp
std::string reverse_string(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}
```


---

9. **이진 탐색 (Binary Search)** 
배열에서 특정 값이 존재하는지 이진 탐색으로 찾는 함수입니다.


```cpp
bool binary_search(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
```


---

10. **이진수로 변환** 
정수를 이진수 문자열로 변환하는 함수입니다.


```cpp
std::string to_binary(int n) {
    std::string result = "";
    while (n > 0) {
        result = (n % 2 ? "1" : "0") + result;
        n /= 2;
    }
    return result.empty() ? "0" : result;
}
```


---

11. **조합 (Combination) 계산** 
조합(Combination)을 계산하는 함수입니다.


```cpp
int combination(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}
```


---

12. **두 수의 거듭제곱** 
두 수의 거듭제곱을 계산하는 함수입니다. (빠른 거듭제곱 방법)


```cpp
long long power(int base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}
```


13. **BFS (Breadth-First Search)** 
BFS는 큐(Queue)를 사용하여 노드를 레벨 순으로 탐색하는 알고리즘입니다.


```cpp
#include <iostream>
#include <vector>
#include <queue>

void bfs(const std::vector<std::vector<int>>& adj, int start) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";  // 방문한 노드 출력
        
        // 인접한 노드들 탐색
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```
**사용법** : 
- `adj`는 인접 리스트 형태로 그래프를 나타냅니다. 예를 들어, `adj[0]`은 노드 0과 연결된 노드들의 리스트입니다.
 
- `start`는 BFS 시작 노드입니다.


---

14. **DFS (Depth-First Search)** 
DFS는 스택(혹은 재귀)을 사용하여 깊이 우선으로 노드를 탐색하는 알고리즘입니다.


```cpp
#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& adj, int node, std::vector<bool>& visited) {
    visited[node] = true;
    std::cout << node << " ";  // 방문한 노드 출력

    // 인접한 노드들 탐색
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(adj, neighbor, visited);
        }
    }
}

void dfs_iterative(const std::vector<std::vector<int>>& adj, int start) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            std::cout << node << " ";  // 방문한 노드 출력
        }

        // 인접한 노드들을 스택에 추가
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}
```
**사용법** : 
- `adj`는 그래프의 인접 리스트입니다.
 
- `node`는 DFS를 시작할 노드입니다.
 
- `visited`는 방문한 노드를 추적하는 배열입니다.


---

15. **BFS와 DFS를 이용한 연결 요소 찾기** 
이 코드는 그래프에서 연결된 모든 요소(컴포넌트)를 찾는 데 유용합니다. BFS 또는 DFS를 사용하여 각 연결 요소를 탐색합니다.


```cpp
void find_connected_components(const std::vector<std::vector<int>>& adj, int n) {
    std::vector<bool> visited(n, false);

    // 모든 노드를 탐색하여 연결된 모든 요소를 찾아 출력
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            std::cout << "Connected Component: ";
            bfs(adj, i);  // 또는 dfs(adj, i, visited) 사용 가능
            std::cout << std::endl;
        }
    }
}
```
**사용법** : 
- `adj`는 그래프의 인접 리스트입니다.
 
- `n`은 노드의 개수입니다.


---

16. **BFS를 이용한 최단 경로 찾기 (Unweighted Graph)** 
BFS를 사용하여 가중치가 없는 그래프에서 시작 노드부터 각 노드까지의 최단 경로를 찾는 함수입니다.


```cpp
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfs_shortest_path(const std::vector<std::vector<int>>& adj, int start) {
    int n = adj.size();
    std::vector<int> distance(n, -1);  // -1은 아직 방문하지 않음을 의미
    std::queue<int> q;
    
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distance[neighbor] == -1) {  // 아직 방문하지 않았다면
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}
```
**사용법** : 
- `adj`는 인접 리스트 형태의 그래프입니다.
 
- `start`는 시작 노드입니다.
 
- 반환 값인 `distance` 배열은 시작 노드에서 각 노드까지의 최단 거리를 나타냅니다.


---

17. **DFS를 이용한 순회 (Topological Sort)** 
그래프에서 위상 정렬을 찾는 DFS 알고리즘입니다. 이 함수는 방향 그래프에서 사이클이 없을 때 사용됩니다.


```cpp
#include <iostream>
#include <vector>
#include <stack>

void dfs_topological_sort(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::stack<int>& result) {
    visited[node] = true;
    
    // 인접한 노드들 방문
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs_topological_sort(neighbor, adj, visited, result);
        }
    }
    
    // 모든 자식 노드를 방문한 후에 현재 노드를 스택에 넣음
    result.push(node);
}

std::stack<int> topological_sort(const std::vector<std::vector<int>>& adj, int n) {
    std::vector<bool> visited(n, false);
    std::stack<int> result;
    
    // 모든 노드에 대해 DFS 수행
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_topological_sort(i, adj, visited, result);
        }
    }
    
    return result;
}
```
---
**사용법** : 
- `adj`는 방향 그래프의 인접 리스트입니다.
 
- `n`은 노드의 개수입니다.
 
- 반환 값인 `result` 스택은 위상 정렬된 노드들의 순서입니다.

18. **백트래킹 기본 구조** 
백트래킹의 기본 구조를 잡은 함수입니다. 이 예제는 재귀를 사용해 가능한 모든 경우를 탐색하며, 조건에 맞지 않으면 다시 되돌아가서 다른 경로를 시도합니다.


```cpp
#include <iostream>
#include <vector>

void backtrack(std::vector<int>& arr, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    // 조건을 만족하는 해답이 발견되면 결과에 추가
    if (index == arr.size()) {
        result.push_back(current);
        return;
    }

    // 현재 인덱스를 포함하지 않는 경우
    backtrack(arr, index + 1, current, result);

    // 현재 인덱스를 포함하는 경우
    current.push_back(arr[index]);
    backtrack(arr, index + 1, current, result);
    current.pop_back();  // 현재 인덱스를 포함했으므로 다시 되돌림
}

std::vector<std::vector<int>> generate_subsets(const std::vector<int>& arr) {
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    backtrack(arr, 0, current, result);
    return result;
}
```
**사용법** : 
- `arr`는 입력 배열입니다.
 
- 함수 `generate_subsets`는 배열의 모든 부분 집합을 구합니다.


---

19. **조합 구하기 (Combination)** 백트래킹을 사용하여 주어진 배열에서 **r** 개의 원소를 고르는 모든 조합을 구하는 함수입니다.

```cpp
#include <iostream>
#include <vector>

void combine(std::vector<int>& arr, int start, int r, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (current.size() == r) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < arr.size(); i++) {
        current.push_back(arr[i]);
        combine(arr, i + 1, r, current, result);  // i + 1을 하는 이유는 같은 원소를 중복해서 고르지 않기 위함
        current.pop_back();
    }
}

std::vector<std::vector<int>> combinations(const std::vector<int>& arr, int r) {
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    combine(arr, 0, r, current, result);
    return result;
}
```
**사용법** : 
- `arr`는 입력 배열입니다.
 
- `r`은 고를 원소의 개수입니다.
 
- 함수 `combinations`는 배열에서 고를 수 있는 모든 **r** 개의 조합을 구합니다.


---

20. **순열 구하기 (Permutation)** 백트래킹을 사용하여 주어진 배열에서 **r** 개의 원소로 가능한 모든 순열을 구하는 함수입니다.

```cpp
#include <iostream>
#include <vector>

void permute(std::vector<int>& arr, int start, std::vector<int>& current, std::vector<bool>& visited, std::vector<std::vector<int>>& result) {
    if (current.size() == arr.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        current.push_back(arr[i]);
        permute(arr, 0, current, visited, result);  // 모든 자리를 순차적으로 채워 나감
        current.pop_back();
        visited[i] = false;
    }
}

std::vector<std::vector<int>> permutations(const std::vector<int>& arr) {
    std::vector<int> current;
    std::vector<bool> visited(arr.size(), false);
    std::vector<std::vector<int>> result;
    permute(arr, 0, current, visited, result);
    return result;
}
```
**사용법** : 
- `arr`는 입력 배열입니다.
 
- 함수 `permutations`는 배열에서 가능한 모든 순열을 구합니다.


---

21. **수도(숫자) 배치 문제** 주어진 조건에 맞는 숫자를 배치하는 백트래킹 문제입니다. 예를 들어, `1`부터 `n`까지 숫자를 **r** 개씩 배치하는 문제를 해결하는 예제입니다.

```cpp
#include <iostream>
#include <vector>

void backtrack(std::vector<int>& arr, int n, int r, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (current.size() == r) {
        result.push_back(current);
        return;
    }
    
    for (int i = index; i <= n; i++) {
        current.push_back(i);
        backtrack(arr, n, r, i + 1, current, result);  // i + 1을 하는 이유는 중복 배치를 피하기 위해
        current.pop_back();
    }
}

std::vector<std::vector<int>> number_placement(int n, int r) {
    std::vector<int> arr;
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    backtrack(arr, n, r, 1, current, result);  // 숫자 1부터 시작
    return result;
}
```
**사용법** : 
- `n`은 숫자 범위 (1~n)입니다.
 
- `r`은 고를 숫자의 개수입니다.
 
- 함수 `number_placement`는 숫자 1부터 `n`까지의 수 중에서 `r`개의 숫자를 배치하는 모든 방법을 구합니다.


---

22. **부분 집합의 합 구하기** 
배열의 원소들 중에서 부분 집합의 합이 특정 값이 되는 경우를 찾는 문제입니다. 백트래킹을 이용하여 해결할 수 있습니다.


```cpp
#include <iostream>
#include <vector>

void find_subset_sum(const std::vector<int>& arr, int target, int index, int current_sum, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (current_sum == target) {
        result.push_back(current);
        return;
    }

    if (index == arr.size() || current_sum > target) {
        return;  // 종료 조건
    }

    // 현재 원소를 포함하는 경우
    current.push_back(arr[index]);
    find_subset_sum(arr, target, index + 1, current_sum + arr[index], current, result);

    // 현재 원소를 포함하지 않는 경우
    current.pop_back();
    find_subset_sum(arr, target, index + 1, current_sum, current, result);
}

std::vector<std::vector<int>> subset_sum(const std::vector<int>& arr, int target) {
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    find_subset_sum(arr, target, 0, 0, current, result);
    return result;
}
```
**사용법** : 
- `arr`는 입력 배열입니다.
 
- `target`은 목표 합입니다.
 
- 함수 `subset_sum`은 배열의 부분 집합들 중 합이 `target`이 되는 부분 집합들을 구합니다.



---

