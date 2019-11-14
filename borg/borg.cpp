#include <bits/stdc++.h>
using namespace std;
//bfs to all alien then kruscov minimal spaning tree
struct Node{
    ~Node() = default;
    Node(int posX, int posY, Node* p): posX{posX}, posY{posY}, parent{p} {}
    int posX{};
    int posY{};
    Node* parent;
};
struct World
{
    char data[51][51];
};


bool valid_tile(char tile){
    if(tile == '#')
        return false;
    if(tile == 'T')
        return cout << "T", false;
    return true;
}

void add_node(int posX, int posY, Node* p,int w, vector<int> &visited,deque<Node*>& frontear){
    if (visited[posX + posY * w] == 0){
        visited[posX + posY * w] += 1;
        frontear.push_back(new Node(posX,posY,p));
    }
}

int main() {
    deque<Node*> frontear;
    int steps{};

    int tests{}, w{}, h{};
    cin >> tests;
    for (int t{}; t < tests; t++){
            
        cin >> w >> h;
        vector<int> visited(w * h);
        fill(visited.begin(), visited.end(), 0);
        World world = World();
        for (int i{}; i < h; i++){
            for (int j{}; j <= w; j++ ){
                scanf("%c", &world.data[j][i]);
                if (world.data[j][i] == 'S'){
                    frontear.push_back(new Node(j,i, 0));
                }
            }
        }
        // for (int i{}; i < h; i++){
        //     for (int j{}; j <= w; j++ ){ 
        //         cout << world.data[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        while (!frontear.empty()){

            Node* node = frontear.front();
            if(world.data[node->posX][node->posY] == 'A')
                cout << "found " << endl;

            if(valid_tile(world.data[node->posX-1][node->posY])){
                add_node(node->posX-1, node->posY,node, w, visited, frontear);
            } 
            if(valid_tile(world.data[node->posX+1][node->posY])){
                add_node(node->posX+1, node->posY, node, w, visited, frontear);
            }
            if(valid_tile(world.data[node->posX][node->posY-1])){
                add_node(node->posX, node->posY-1, node, w, visited, frontear);
            }
            if(valid_tile(world.data[node->posX][node->posY+1])){
                add_node(node->posX, node->posY+1, node, w, visited, frontear);
            }
            
            //delete node;
            frontear.pop_front();
        }
        cout << steps << endl;
    }
    return 0;
}
