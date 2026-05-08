class dsu {
    vector<int> parent;
    vector<int> rank;
public:
    dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find_set(int v) {
        if(parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }

    bool union_set(int a, int b) {
        if(find_set(a) == find_set(b)) return true;
        int p_a = find_set(a);
        int p_b = find_set(b);
        if(rank[p_a] > rank[p_b]) swap(p_a, p_b);
        parent[p_a] = p_b;
        if(rank[p_a] == rank[p_b]) {
            rank[p_b]++;
        }
        return false;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        dsu d = dsu(n);
        for(auto &e: edges) {
            if(d.union_set(e[0], e[1])) return false;
        }
        return true;
    }
};
