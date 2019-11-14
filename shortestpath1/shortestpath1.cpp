#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Arc
{
    Arc(T next, int w): id{next}, w{w} {}
    T id;
    int w;
};

class Graf
{
    public:
        Graf(int n, int s) {
            costs.resize(n, -1);
            neighbors.resize(n, vector<Arc<int>>());
            costs[s] = 0;
        }

        void add_arc(int from, int to, int w){
            neighbors[from].push_back(Arc<int>(to, w));
        }
        
        void precalc(int start){
            queue<int> frontear;
            frontear.push(start);
            while (!frontear.empty()){
                int node_id = frontear.front();
                for(Arc<int> next_node: neighbors[node_id]){
                    if(costs[node_id] + next_node.w < costs[next_node.id] || costs[next_node.id] == -1 ) {
                        costs[next_node.id] = costs[node_id] + next_node.w;;
                        frontear.push(next_node.id);
                    }
                }
                frontear.pop();
            }

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
    int from{}, to{}, w{};

    while (true){
        scanf("%d %d %d %d", &n, &m, &qs, &s);
        if(n == 0) break;
        Graf graf = Graf(n, s);
        for (int i{}; i < m; i++ ){
            scanf("%d %d %d", &from, &to, &w);
            graf.add_arc(from, to, w);
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
