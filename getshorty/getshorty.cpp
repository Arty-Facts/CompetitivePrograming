#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Arc
{
    Arc(T next, double w): id{next}, w{w} {}
    T id;
    double w;
};

struct Node{
    Node(int id, double c): id{id}, c{c} {}
    Node() = default;
    Node(Node const & ) = default;
    ~Node() = default;
    bool operator() (Node const & f, Node const & s){
        return f.c < s.c;

    }
    int id{};
    double c{};
};
class Graf
{
    public:
        Graf(int n, int s) {
            costs.resize(n, -1);
            neighbors.resize(n, vector<Arc<int>>());
            costs[s] = 0;
        }

        void add_arc(int from, int to, double w){
            neighbors[from].push_back(Arc<int>(to, w));
            neighbors[to].push_back(Arc<int>(from, w));
        }
        
        double calc(int start, int end){
            priority_queue<Node, vector<Node>, Node> frontear;
            vector<bool> viseted(end);
            //fill(viseted.begin(), viseted.end(), false);
            frontear.push(Node(start, 1));
            while (!frontear.empty()){
                Node node = frontear.top();
                frontear.pop();
                if (!viseted[node.id]){
                    viseted[node.id] = true;
                    if (node.id == end)
                        return node.c;
                    for(Arc<int> next_node: neighbors[node.id]){
                        if (!viseted[next_node.id])
                            frontear.push(Node(next_node.id, node.c * next_node.w));
                    }
                }
            }
            return 1;
        }

    private:
        vector<vector<Arc<int>>> neighbors;
        vector<double> costs;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, m{};
    int from{}, to{};
    double w{};

    while (true){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        Graf graf = Graf(n, 0);
        for (int i{}; i < m; i++ ){
            scanf("%d %d %lf", &from, &to, &w);
            graf.add_arc(from, to, w);
        }
        double ans = graf.calc(0, n-1);
        printf("%.4lf\n", ans);
    }


    return 0;
}
