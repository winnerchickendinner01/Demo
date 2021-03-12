#include <iostream>
#include <set>
#include <string>

using namespace std;
#define MAX_AMOUNT 100

int parent[MAX_AMOUNT], rank[MAX_AMOUNT];
set<int> trees[MAX_AMOUNT];

int findSet(int u) {
    if (u != parent[u]) {
        u = findSet(parent[u]);
    }

    return u;
}

void unionSet(int u, int v) {
    int u_set = findSet(u);
    int v_set = findSet(v);

    if (u_set == v_set) {
        return;
    }

    if (rank[up] > rank[vp]) {
        parent[vp] = up;
    }

    else if (rank[up] < rank[vp]) {
        parent[up] = vp;
    }

    else {
        parent[up] = vp;
        rank[vp]++;
    }
}

int main() {
    int numOfTestcases, numOfPeople, numOfTrees, person, tree;
    string s;

    cin >> numOfTestcases;
    cin.ignore();
    getline(cin, s);

    for (int k = 1; k <= numOfTestcases; k++) {
        stringstream ss;
        ss >> numOfPeople >> numOfTrees;

        while (getline(cin, s) && !s.empty()) {
            ss >> person >> tree;
            trees[person].insert(tree);
        }

        for (int i = 1; i <= numOfPeople; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 1; i <= numOfPeople; i++) {
            for (int j = i + 1; j <= numOfPeople; j++) {
                if (trees[i] == trees[j]) {
                    unionSet(i, j);
                }
            }
        }

        int count = 0;
        for (int i = 1; i <= numOfPeople; i++) {
            if (parent[i] == i) {
                count++;
            }
        }

        if (k != 1) cout << "\n";
        cout << count << endl;
    }

    return 0;
}