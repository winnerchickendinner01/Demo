#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define MAX 30005

int parent[MAX];
vector<int> arr(MAX, 1);

int findSet(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }

    return parent[u];
}

void unionSet(int u, int v) {
    int u_set = findSet(u);
    int v_set = findSet(v);

    if (u_set == v_set) {
        return;
    }

    parent[u_set] = v_set;
    arr[v_set] += arr[u_set];
}

int main() {
    int testcase, numOfCities, numOfPairs;
    int u, v;
    cin >> testcase;

    while (testcase--) {
        cin >> numOfCities >> numOfPairs;

        for (int i = 1; i <= numOfCities; i++) {
            parent[i] = i;
            arr[i] = 1;
        }

        while (numOfPairs--) {
            cin >> u >> v;
            unionSet(u, v);
        }

        int res = -1;
        for (int i = 1; i <= numOfCities; i++) {
            res = max(res, arr[i]);
        }

        cout << res << endl;
    }

    return 0;
}
