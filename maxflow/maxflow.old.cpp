#include <bits/stdc++.h>
using namespace std;
#define MAX 1<<29
template <typename T>
struct Arc
{
    Arc() = default;
    Arc(Arc const& ) = default;
    Arc(T next, int c): id{next}, c{c} ,min{c} {}
    bool operator() (Arc f, Arc s){
        return f.id < s.id;
    }
    T id;
    int c;
    int min;

};

struct Node
{
    Node() = default;
    ~Node() = default;
    Node(int id, int min): id{id}, min{min} {}
    int id{};
    int min{};
};
struct Order
{
    Order() = default;
    ~Order() = default;
    Order(int from, int to, int flow)
        :from{from}, to{to}, flow{flow} {}
    bool operator() (Order f, Order s){
        return f.from < s.from;
    }

    int from;
    int to;
    int flow;
};


class Graf
{
    public:
        Graf(int n, int s):n{n} {
            neighbors.resize(n, vector<Arc<int>>());
            cap.resize(n, vector<int>(n));
            viseted.resize(n, -1);
            parent.resize(n, -1);
        }

        void add_arc(int from, int to, int c){
            cap[from][to] = c;
            neighbors[from].push_back(Arc<int>(to, c));
            neighbors[to].push_back(Arc<int>(from, 0));
        }
        
        int max_flow(int start, int end){
            int flow{};
            int maxFlow{};
            int i{};
            do{
                flow = bfs(start, end, i++);
                adjust(start, end, flow);
                maxFlow += flow;
            }while(flow != 0);
            return maxFlow;
        }
        void adjust(int start, int end, int flow){
            //adjust the caps
            if (flow == 0)
                return;
            for(int curr{end} ; curr != start; curr = parent[curr]){
                int p = parent[curr];
                cap[p][curr] -= flow;
                cap[curr][p] += flow;
            }
        }

        int min_val(int r, int l){
            if (r < l)
                return r;
            return l;
        }
        int bfs(int start, int end, int i){
            queue<Node> frontear;
            frontear.push(Node(start, MAX));
            viseted[start] = i;
            parent[start] = -1;
            Node node{};
            int min{}; 
            while (!frontear.empty()){
                node = frontear.front();
                frontear.pop();
                if (node.min == 0)
                    continue;
                for(Arc<int> next_node: neighbors[node.id]){
                    if (viseted[next_node.id] != i && cap[node.id][next_node.id] > 0){
                        viseted[next_node.id] = i;
                        parent[next_node.id] = node.id;
                        min = min_val(node.min ,cap[node.id][next_node.id]);
                        if(next_node.id == end)
                            return min;
                        frontear.push(Node(next_node.id, min));
                    }
                }
            }
            return 0; 
        }
        
        int used_nodes(int start, int end){
            queue<int> frontear;
            frontear.push(start);
            int node{};
            int count{};
            while (!frontear.empty()){
                node = frontear.front();
                frontear.pop();
                if (viseted[node] == -2)
                    continue;
                viseted[node] = -2;
                // sort(neighbors[node].begin(), neighbors[node].end(), Arc<int>());
                for(Arc<int> next_node: neighbors[node]){
                    int flow = next_node.c - cap[node][next_node.id];
                    if (flow > 0){
                        if (viseted[next_node.id] != -2){
                            ++count;
                            print_nodes.push_back(Order(node, next_node.id, flow));
                            frontear.push(next_node.id);
                        }
                    }
                }
            }
            return count;
        }

        void print(){
            // sort(print_nodes.begin(), print_nodes.end(), Order());
            for(Order n: print_nodes)
                printf("%d %d %d\n", n.from , n.to ,n.flow);
        }

    private:
        int n{};
        vector<vector<Arc<int>>> neighbors;
        vector<vector<int>> cap;
        vector<int> parent;
        vector<int> viseted;
        vector<Order> print_nodes;
};


int main() {
    int n{}, m{}, s{}, t{};
    int from{}, to{};
    int c{};

 
    scanf("%d %d %d %d", &n, &m, &s, &t);
    Graf graf = Graf(n, s);
    for (int i{}; i < m; i++ ){
        scanf("%d %d %d", &from, &to, &c);
        graf.add_arc(from, to, c);
    }
    int maxFlow = graf.max_flow(s, t);
    int nodeUsed = graf.used_nodes(s, t);
    printf("%d %d %d\n",n , maxFlow, nodeUsed);
    graf.print();


    return 0;
}
