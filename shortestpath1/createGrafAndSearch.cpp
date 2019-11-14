#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Arc
{
    Arc(T* next, int w): next{next}, w{w} {}
    T* next;
    int w;
};

struct Node
{
    Node(int id): id{id} {}
    Node(Node const&) = default;
    ~Node() = default;

    void add_neighbor(Node* neighbor, int w){
        neighbors.push_back(Arc<Node>(neighbor, w));
    }

    int id{};
    vector<Arc<Node>> neighbors;
    int cost{};
};
struct NodeComp
{
    bool operator() (Node* f, Node* s){
        return f->cost > s->cost;
    }
    bool operator() (Node f, Node s){
        return f.cost > s.cost;
    }
};

class Graf
{
    public:
        Graf(int n, int s) {
            nodes.resize(n, nullptr);
            costs.resize(n, -1);
            costs[s] = 0;
        }
        ~Graf(){
            //cout << "kill all" << endl;
            for(auto it: nodes)
                if(it != nullptr)
                    delete it;
        }

        bool exists(int id){
            return nodes[id] != nullptr;
        }

        void add_node(int id){
            nodes[id] = new Node(id);
        }

        void add_arc(int from, int to, int w){
            nodes[from]->add_neighbor(nodes[to], w);
        }
        void precalc(int start){
            if(nodes[start] == nullptr)
                return ;
            Node* root = nodes[start];
            queue<Node*> frontear;
            frontear.push(root);
            while (!frontear.empty()){
                Node* node = frontear.front();
                for(auto n: node->neighbors){
                    Node* next_node = n.next;
                    if(costs[node->id] + n.w < costs[n.next->id] || costs[n.next->id] == -1 ) {
                        next_node->cost += node->cost + n.w;
                        costs[next_node->id] = next_node->cost;
                        frontear.push(next_node);
                    }
                }
                frontear.pop();
            }
            // for(int i: costs){
            //     cout << i << " ";
            // }
            // cout << endl;
        }
        int calc(int to){
            return costs[to];
        }

        int path_cost(int from, int to){
            Node start =  *nodes[from];
            priority_queue<Node, vector<Node>, NodeComp> frontear;
            frontear.push(start);
            while (!frontear.empty()){
                Node node = frontear.top();
                if (node.id == to){
                    return node.cost; // the first you find is the best
                }
                else{
                    for(auto n: node.neighbors){
                        Node next_node = *n.next;
                        next_node.cost += node.cost + n.w;
                        frontear.push(next_node);
                    }
                }
                frontear.pop();
            }
            return -1;
        }

    private:
        vector<Node*> nodes;
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
            if (!graf.exists(from))
                graf.add_node(from);
            if (!graf.exists(to))
                graf.add_node(to);
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
