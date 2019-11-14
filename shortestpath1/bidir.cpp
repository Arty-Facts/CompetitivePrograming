#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Arc
{
    Arc(T* next, int64_t w): next{next}, w{w} {}
    T* next;
    int64_t w;
};

struct Node
{
    Node(int64_t id): id{id} {}
    Node(Node const&) = default;
    ~Node() = default;

    void add_neighbor_from_to(Node* neighbor, int64_t w){
        //cout << "ft    id: " <<id << " neighbor " << neighbor->id << endl;
        neighbors_from_to.push_back(Arc<Node>(neighbor, w));
    }
    void add_neighbor_to_from(Node* neighbor, int64_t w){
        //cout << "tf   id: " <<id << " neighbor " << neighbor->id << endl;
        neighbors_to_from.push_back(Arc<Node>(neighbor, w));
    }
    int64_t id{};
    vector<Arc<Node>> neighbors_from_to;
    vector<Arc<Node>> neighbors_to_from;
    int64_t cost{};
};
struct NodeComp
{
    bool operator() (Node f, Node s){
        return f.cost > s.cost;
    }
};

class Graf
{
    public:
        Graf(int64_t n):n{n} {
            nodes.resize(n, nullptr);
        }
        ~Graf(){
            for(auto it: nodes)
                if(it != nullptr)
                    delete it;
        }

        bool exists(int64_t id){
            return nodes[id] != nullptr;
        }

        void add_node(int64_t id){
            nodes[id] = new Node(id);
        }

        void add_arc_from_to(int64_t from, int64_t to, int64_t w){
            nodes[from]->add_neighbor_from_to(nodes[to], w);
        }

        void add_arc_to_from(int64_t to, int64_t from, int64_t w){
            nodes[to]->add_neighbor_to_from(nodes[from], w);
        }
        int64_t cost(int64_t from, int64_t to){
            Node f_start =  *nodes[from];
            Node t_start =  *nodes[to];
            vector<int64_t> f_viseted;
            vector<int64_t> t_viseted;
            f_viseted.resize(n, -1);
            t_viseted.resize(n, -1);
            t_viseted[to] = 0;
            //deque<Node> frontear{root};
            priority_queue<Node, std::vector<Node>, NodeComp> f_frontear;
            priority_queue<Node, std::vector<Node>, NodeComp> t_frontear;
            f_frontear.push(f_start);
            t_frontear.push(t_start);
            while (!f_frontear.empty() && !t_frontear.empty()){
                Node f_node = f_frontear.top();
                //cout <<"f: " << f_node.id << endl;
                if (t_viseted[f_node.id] != -1){
                    return f_node.cost + t_viseted[f_node.id]; // the first you find is the best
                }
                else{
                    for(auto n: f_node.neighbors_from_to){
                        Node next_node = *n.next;
                        next_node.cost += f_node.cost + n.w;
                        f_viseted[next_node.id] = next_node.cost;
                        f_frontear.push(next_node);
                    }
                }
                f_frontear.pop();

                Node t_node = t_frontear.top();
                //cout <<"t: " << t_node.id <<" n: " << t_node.neighbors_to_from.size() << endl;

                if (f_viseted[t_node.id] != -1){
                    return t_node.cost + f_viseted[t_node.id]; // the first you find is the best
                }
                else{
                    for(auto n: t_node.neighbors_to_from){
                        Node next_node = *n.next;
                        next_node.cost += t_node.cost + n.w;
                        t_viseted[next_node.id] = next_node.cost;
                        t_frontear.push(next_node);
                    }
                }
                t_frontear.pop();
                //cout << "t_f " << t_frontear.size() << " f_f " << f_frontear.size() << endl;  
            }
            return -1;
        }

    private:
        vector<Node*> nodes;
        int64_t n{};
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n{}, m{}, qs{}, q{}, s{};
    int64_t from{}, to{}, w{};


    while (cin >> n >> m >> qs >> s){
        if (n + m + qs + s == 0)
            break;
        Graf graf = Graf(n);
        for (int64_t i{}; i < m; i++ ){
            cin >> from >> to >> w;
            if (!graf.exists(from))
                graf.add_node(from);
            if (!graf.exists(to))
                graf.add_node(to);

            graf.add_arc_to_from(to,from, w);
            graf.add_arc_from_to(from,to, w);           
            
        }

        for (int64_t i{}; i < qs; i++ ){
            cin >> q;
            int64_t res{};
            res = graf.cost(s,q);           
            
            if (res == -1)
                cout << "Impossible" << endl;
            else 
                cout << res << endl;
        }
        
        cout << endl;
    }
    return 0;
}
