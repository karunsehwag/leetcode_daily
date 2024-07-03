#include <vector>
using namespace std;

class Disjointset {
    vector<int> rank, parent;
public:
    Disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findupar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findupar(parent[node]);
    }

    bool unionr(int u, int v) {
        int p1 = findupar(u);
        int p2 = findupar(v);
        if (p1 == p2)
            return false;
        if (rank[p1] > rank[p2])
            parent[p2] = p1;
        else if (rank[p1] < rank[p2])
            parent[p1] = p2;
        else {
            parent[p2] = p1;
            rank[p1]++;
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Disjointset r1(n), r2(n);
        int remove = 0;
        int mer1 = 0, mer2 = 0;

        for (vector<int> it : edges) {
            if (it[0] == 3) {
                bool val1 = r1.unionr(it[1], it[2]);
                bool val2 = r2.unionr(it[1], it[2]);
                if (val1) {
                    mer1++;
                }
                if (val2) {
                    mer2++;
                }
            
                if (!val1 && !val2) {
                    remove++;
                }
            }
        }

        for (vector<int> it : edges) {
            if (it[0] == 1) {  
                if (r1.unionr(it[1], it[2])) {
                    mer1++;
                } else {
                    remove++;
                }
            } else if (it[0] == 2) { 
                if (r2.unionr(it[1], it[2])) {
                    mer2++;
                } else {
                    remove++;
                }
            }
        }

        if (mer1 != n - 1 || mer2 != n - 1) {
            return -1;
        }
        return remove;
    }
};
