class setUnion {
    vector<int> parent;
    vector<int> size;
public:
    setUnion(int v) {
        parent.resize(v);
        size.resize(v);
    }
    void union_sets(int a, int b) {
        int p_a = find_set(a);
        int p_b = find_set(b);
        if(p_a != p_b) {
            if(size[p_a] > size[p_b]) {
                swap(p_a, p_b);
            }
            parent[p_a] = p_b;
            size[p_b] += size[p_a];
        }
        return;
    }
    int find_set(int v) {
        if(parent[v] == v) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int v1, v2;
        setUnion dsu = setUnion(n);
        for(int i=0; i<n; i++) {
            dsu.make_set(i);
        }
        for(int i=0; i<edges.size(); i++) {
            v1 = edges[i][0];
            v2 = edges[i][1];
            dsu.union_sets(v1,v2);
        }
        unordered_set<int> numComponents;
        for(int i=0; i<n; i++) {
            numComponents.insert(dsu.find_set(i));
        }
        return numComponents.size();
    }
};
