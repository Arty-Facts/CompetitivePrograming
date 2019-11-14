#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Arc
{
    Arc(T next, T t0, T P, T d)
        :next{next}, t0{t0}, P{P}, d{d} {}
    T next{};
    T t0{};
    T P{};
    T d{};
};
struct Node{
    Node(int id, int c): id{id}, c{c} {}
    Node() = default;
    Node(Node const & ) = default;
    ~Node() = default;
    bool operator() (Node const & f, Node const & s){
        return f.c > s.c;

    }
    int id{};
    int c{};
};
class Graf
{
    public:
        Graf(int n, int s) {
            costs.resize(n, -1);
            neighbors.resize(n, vector<Arc<int>>());
        }

        void add_arc(int from, int to, int t0, int P, int d){
            neighbors[from].push_back(Arc<int>(to, t0, P, d));
        }
        
        void precalc(int start){
            priority_queue<Node, vector<Node>, Node> frontear;
            frontear.push(Node(start, 0));
            costs[start] = 0;
            while (!frontear.empty()){
                Node node = frontear.top();
                frontear.pop();
                for(Arc<int> arc: neighbors[node.id]){
                    int diff = node.c - arc.t0;
                    if (arc.P == 0 && diff > 0 ) //skip if after t0
                        continue;
                    if (diff > 0 && diff%arc.P == 0)
                        diff = diff/arc.P;
                    else
                        diff = diff > 0 ? diff/arc.P+1: 0;
                    
                    int cost = arc.t0 + diff*arc.P  + arc.d;
                    if(cost < costs[arc.next] || costs[arc.next] == -1 ){
                        costs[arc.next] = cost;
                        frontear.push(Node(arc.next, cost));

                    }
                        
                }
                
            }
            // for(int i: costs){
            //     cout << i << " ";
            // }
            // cout << endl;

        }
        int calc(int to){
            return costs[to];
        }

    private:
        vector<vector<Arc<int>>> neighbors;
        vector<int> costs;
};


int main() {
    int n{}, m{}, qs{}, q{}, s{};
    int from{}, to{}, t0{}, P{}, d{};

    while (true){
        scanf("%d %d %d %d", &n, &m, &qs, &s);
        if(n == 0) break;
        Graf graf = Graf(n, s); 
        for (int i{}; i < m; i++ ){
            scanf("%d %d %d %d %d", &from, &to, &t0, &P, &d);
            graf.add_arc(from, to, t0, P, d);
        }
        graf.precalc(s);
        for (int i{}; i < qs; i++ ){
            scanf("%d", &q);
            int res = graf.calc(q);
            if (res == -1)
                printf("Impossible\n");
            else 
                printf("%d\n", res);
        }
        printf("\n");
    }


    return 0;
}
