#include <iostream>
#include <string>

using namespace std;
const int ALPHABET_RANGE = 26;
int parent[ALPHABET_RANGE];

void makeElem(int u) {
    parent[u] = u;
}

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
}

int main() {
    int numOfTestcases, changeChar, ans;
    cin >> numOfTestcases;

    string s;
    cin.ignore();
    getline(cin, s);

    for (int i = 1; i <= numOfTestcases; i++) {
        getline(cin, s);
        changeChar = s[0] - 'A' + 1;

        for (int k = 0; k < changeChar; k++) {
            makeElem(k);
        }

        while (getline(cin, s) && s != "") {
            int u = s[0] - 'A', v = s[1] - 'A';
            unionSet(u, v);
        }

        int count = 0;
        for (int j = 0; j < changeChar; j++) {
            if (parent[j] == j) {
                count++;
            }
        }

        if (i != 1) cout << endl;
        cout << count << endl;
    }
}