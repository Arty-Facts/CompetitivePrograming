#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Arc
{
    Arc(T next, int w): next{next}, w{w} {}
    Arc() = default;
    bool operator() (Arc f, Arc s){
        return f.next < s.next;
    }
    T next;
    int w;
};

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

struct Cost
{
    Cost(int from, int to, int w): from{from}, to{to}, w{w} {}
    ~Cost() = default;
    Cost() = default;
    bool operator() (Cost* f, Cost* s){
        return f->w > s->w;
    }
    bool operator() (Cost& f, Cost& s){
        return f.w > s.w;
    }
    int from{};
    int to{};
    int w{};

};

class Graf
{
    public:
        Graf(int n):n{n} {
            neighbors.resize(n, vector<Arc<int>>());
        }

        void add_arc(int from, int to, int w){
            int f = min(from, to);
            int t = max(from, to);
            neighbors[f].push_back(Arc<int>(t, w));
        }
        
        void print(int start){
            for(int i{start}; i < n; i++){
                sort(neighbors[i].begin(), neighbors[i].end(), Arc<int>());
                for(Arc<int> node: neighbors[i])
                    printf("%d %d\n", i, node.next);
            }

        }

    private:
        int n{};
        vector<vector<Arc<int>>> neighbors;
};


class KruskalMIT
{
public:
    KruskalMIT() = default;
    ~KruskalMIT()  = default;
    KruskalMIT(int n):imp{true}, uf{UnionFind(n)} , graf{Graf(n)}{}
    void add(int from, int to, int w){
        costsOfArc.push(Cost(from, to, w));
    }
    
    int64_t compute(int n){
        int nodeCount{};
        int64_t totalCost{};
        while (nodeCount < n-1){
            if (costsOfArc.empty())
                return -1;
            Cost cost = costsOfArc.top();
            costsOfArc.pop();
            if (uf.find(cost.from) != uf.find(cost.to)){
                graf.add_arc(cost.from, cost.to, cost.w);
                uf.uni(cost.from, cost.to);
                ++nodeCount;
                totalCost += cost.w;
            }
        }
        imp = false;
        return totalCost;
    }

    void print(int64_t tot){
        if(!imp){
            printf("%ld\n", tot);
            graf.print(0);
        }else{
            printf("Impossible\n");
        }
    }

private:
    bool imp{true};
    UnionFind uf;
    Graf graf;
    priority_queue<Cost, vector<Cost>, Cost> costsOfArc;
};

int main() {
    int n{}, m{};
    int from{}, to{}, w{};

    while (true){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        KruskalMIT mit = KruskalMIT(n);
        for (int i{}; i < m; i++ ){
            scanf("%d %d %d", &from, &to, &w);
            mit.add(from, to, w);
        }
        int64_t tot = mit.compute(n); 
        mit.print(tot);
    }


    return 0;
}
