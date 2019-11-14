#include <bits/stdc++.h>
using namespace std;
#define MAX 100000001   

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
        Graf(int n, int s){
            cap.resize(n, vector<int>(n));
            rcap.resize(n, vector<int>(n));
            adj.resize(n, vector<int>());
            viseted.resize(n, false);
            parent.resize(n, -1);
            print_nodes.reserve(n);
        }

        void add_arc(int from, int to, int c){
            cap[from][to] = c;
            rcap[from][to] = c;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        bool has_aug_path(int start, int end){
            fill(viseted.begin(), viseted.end(), false);
            deque<int> frontear;
            frontear.push_back(start);
            parent[start] = -1;
            viseted[start] = true;
            while (!frontear.empty()){
                int node = frontear.front();
                frontear.pop_front();
                for(int next_node: adj[node]){
                    if (!viseted[next_node] && rcap[node][next_node] > 0){
                        viseted[next_node] = true;
                        parent[next_node] = node;
                        frontear.push_back(next_node);
                        if(next_node == end)
                            return true;
                    }
                }
            }
            return false; 
        }

        int find_min(int start, int end){
            int flow{MAX};
            for(int curr{end} ; curr != start; curr = parent[curr]){
                int p = parent[curr];
                flow = min(flow, rcap[p][curr]);
            }
            return flow;
        }
        
        void adjust(int start, int end, int flow){
            for(int curr{end} ; curr != start; curr = parent[curr]){
                int p = parent[curr];
                rcap[p][curr] -= flow;
                rcap[curr][p] += flow;
            }
        }

        int max_flow(int start, int end){
            int maxFlow{};
            int flow;
            while(has_aug_path(start, end)){
                flow = find_min(start, end);
                adjust(start, end, flow);
                maxFlow += flow;
            }
            return maxFlow;
        }
        void min_cut(int start){
            printf("%d\n", accumulate(viseted.begin(), viseted.end(), 0));
            for(int i{} ; i<viseted.size() ; i++){
                if (viseted[i])
                    printf("%d\n", i);
            }

        }
        
        int used_nodes(){
            for (int from{}; from < cap.size(); from++)
    	        for (int to{}; to < cap.size(); to++)
                    if (cap[from][to] > 0 && rcap[from][to] < cap[from][to])
                        print_nodes.push_back(Order(from,to,cap[from][to]-rcap[from][to]));
            return print_nodes.size();
        }

        void print(){
            for(Order n: print_nodes)
                printf("%d %d %d\n", n.from , n.to ,n.flow);
        }

    private:
        vector<vector<int>> cap;
        vector<vector<int>> rcap;
        vector<vector<int>> adj;
        vector<int> parent;
        vector<bool> viseted;
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
    graf.min_cut(s);
    printf("\n");
    //int nodeUsed = graf.used_nodes();
    //printf("%d %d %d\n",n , maxFlow, nodeUsed);
    //graf.print();


    return 0;
}
