#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    UnionFind(int N)
    {
        num_children.reserve(N);
        parent.reserve(N);
        for (int i{}; i<N; i++){
            num_children[i] = 1;
            parent[i] = i;
        }
    }


    int find(int x){
        int root{x};
        while(root != parent[root]){
            root = parent[root];
        }
        int next{};
        while(x != parent[x]){
            next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    void uni(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a == parent_b)
            return;
        
        int mamma = num_children[parent_a] < num_children[parent_b] ? parent_a : parent_b; 
        int pappa = num_children[parent_a] < num_children[parent_b] ? parent_b : parent_a; 

        parent[pappa] = mamma;

    }
    vector<int> num_children;
    vector<int> parent;

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, Q{}, a{}, b{};
    char op;
    string ans;
    cin >> N >> Q;
    UnionFind uf = UnionFind(N);
    for (int x{}; x < Q ; x++){
        cin >> op >> a >> b;
        if (op == '?'){
            ans = uf.find(a) == uf.find(b) ? "yes" : "no";
            cout << ans << endl;
        }else if(op == '='){
            uf.uni(a, b);
        }

    }
    return 0;
}
