#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Arc
{
    Arc(T next, double w): next{next}, w{w} {}
    Arc() = default;
    bool operator() (Arc f, Arc s){
        return f.next < s.next;
    }
    T next;
    double w;
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
    Cost(int from, int to, double w): from{from}, to{to}, w{w} {}
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
    double w{};

};

class KruskalMIT
{
public:
    KruskalMIT() = default;
    ~KruskalMIT()  = default;
    KruskalMIT(int n): uf{UnionFind(n)}{}

    void add(int from, int to, double w){
        costsOfArc.push(Cost(from, to, w));
    }
    
    double compute(int n){
        int nodeCount{};
        double totalCost{};
        while (nodeCount < n-1){
            if (costsOfArc.empty())
                return -1;
            Cost cost = costsOfArc.top();
            costsOfArc.pop();

            if (uf.find(cost.from) != uf.find(cost.to)){
                uf.uni(cost.from, cost.to);
                ++nodeCount;
                totalCost += cost.w;
            }
        }
        return totalCost;
    }

private:
    UnionFind uf;
    priority_queue<Cost, vector<Cost>, Cost> costsOfArc;
};

int main() {
    int n{}, m{};
    double x{}, y{}, dx{}, dy{}, d{};

    scanf("%d", &n);
    for (int i{}; i < n ; i++){
        scanf("%d\n\n", &m);
        vector<pair<double, double>> pos;
        pos.reserve(m);
        KruskalMIT mit = KruskalMIT(m);
        for (int j{}; j < m; j++ ){
            scanf("%lf %lf", &x, &y);
            for (int k{}; k < j; k++){
                dx = pos[k].first - x;
                dy = pos[k].second - y;
                d  =  sqrt(dx*dx + dy*dy);
                mit.add(j, k, d);
            }
            pos[j] = {x, y};
        }
        double tot = mit.compute(m); 
        printf("%.2lf\n",tot);
    }


    return 0;
}
