//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

void print64_t(vector<vector<int64_t>> const & iterable){
    cout << endl;
    for (auto i: iterable){
        for (auto p : i){
            cout << p << " ";
        }
        cout << endl;
    }
}

void print64_t(vector<int64_t> const & iterable){
    cout << endl;
    for (auto i: iterable){
        cout << i << " ";
    }
    cout << endl;
}

struct Node{
    Node(int64_t id, int64_t c, int64_t s): id{id}, c{c}, s{s} {}
    Node() = default;
    Node(Node const & ) = default;
    ~Node() = default;
    bool operator() (Node const & f, Node const & s){
        return f.c > s.c;

    }
    int64_t id{};
    int64_t c{};
    int64_t s{};
};

struct Arc{
    Arc(int64_t to, int64_t c): to{to}, c{c} {}
    Arc() = default;
    Arc(Arc const & ) = default;
    ~Arc() = default;
    bool operator() (Arc const & f, Arc const & s){
        return f.c > s.c;

    }
    int64_t to{};
    int64_t c{};
};

void simplify(int64_t N, int64_t S, vector<vector<Arc>> & path, vector<int64_t>& translate, vector<vector<int64_t>> & costs, int64_t start){
    priority_queue<Node, vector<Node>, Node> frontear;
    vector<bool> viseted(N);
    // StartFrom, Cost, NumOfStrore
    frontear.push(Node(start, 0, 0));
    
    while (!frontear.empty()){
        Node node = frontear.top();
        frontear.pop();
        if (viseted[node.id]){
            continue;
        }
        viseted[node.id] = true;

        if (translate[node.id] != -1){
            node.s += 1;
            costs[translate[start]][translate[node.id]] = node.c;
            costs[translate[node.id]][translate[start]] = node.c;
            
        }

        if (node.s >= start+1){
            return;
        }

        for (auto next_node:  path[node.id]){
            if (!viseted[next_node.to]){
                frontear.push(Node(next_node.to, node.c+next_node.c, node.s));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t N{}, M{}, x{}, y{}, d{}, S{}, s{};
    vector<vector<Arc>> path;
    vector<vector<int64_t>> costs;
    vector<int64_t> shops;

    cin >> N >> M;
    path.resize(N);
    shops.resize(N, -1);
    for (int64_t j{}; j < M; j++){
        cin >> x >> y >> d;
        path[x].push_back(Arc(y,d));
        path[y].push_back(Arc(x,d));
    }
    cin >> S;
    vector<int64_t> order(S+1);
    vector<int64_t> starter(S+1);
    costs.resize(S+1, vector<int64_t>(S+1, -1));
    for (int64_t j{}; j < S; j++){
        cin >> s;
        shops[s] = j+1;
        order[j+1] = j+1;
        starter[j+1] = s;
    }
    shops[0] = 0;

    for (int64_t j{}; j <= S; j++){
        simplify(N, S, path, shops, costs, starter[j]);
    }

    uint64_t minCost = std::numeric_limits<int64_t>::max();
    do { 

        uint64_t currCost{};
        for (int64_t curr{1}; curr <= S; curr++){
            currCost += costs[order[curr-1]][order[curr]];
        } 
        currCost += costs[order[S]][order[0]];
        minCost = min(minCost, currCost);
    } while (next_permutation(order.begin(), order.end()));

    cout << minCost << endl;
    return 0;
}
