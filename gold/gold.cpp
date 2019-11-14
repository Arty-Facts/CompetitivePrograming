#include <bits/stdc++.h>
using namespace std;
struct Node{
    ~Node() = default;
    Node(int posX, int posY): posX{posX}, posY{posY} {}
    int posX{};
    int posY{};
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
bool breez(Node* node, World const& world){
    if(world.data[node->posX-1][node->posY] == 'T'){
        return true;
    } 
    if(world.data[node->posX+1][node->posY] == 'T'){
        return true;
    }
    if(world.data[node->posX][node->posY-1] == 'T'){
        return true;
    }
    if(world.data[node->posX][node->posY+1] == 'T'){
        return true;
    }
    return false;
}
void add_node(int posX, int posY, int w, vector<int> &visited,deque<Node*>& frontear){
    if (visited[posX + posY * w] == 0){
        visited[posX + posY * w] += 1;
        frontear.push_back(new Node(posX,posY));
    }
}

int main() {
    deque<Node*> frontear;
    int gold{};

    int w{}, h{};
    cin >> w >> h;
    vector<int> visited(w * h);
    fill(visited.begin(), visited.end(), 0);
    World world = World();
    for (int i{}; i < h; i++){
        for (int j{}; j <= w; j++ ){
            scanf("%c", &world.data[j][i]);
            if (world.data[j][i] == 'P'){
                frontear.push_back(new Node(j,i));
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
        if(world.data[node->posX][node->posY] == 'G')
            ++gold;

        if(!breez(node, world)){
            if(valid_tile(world.data[node->posX-1][node->posY])){
                add_node(node->posX-1, node->posY, w, visited, frontear);
            } 
            if(valid_tile(world.data[node->posX+1][node->posY])){
                add_node(node->posX+1, node->posY, w, visited, frontear);
            }
            if(valid_tile(world.data[node->posX][node->posY-1])){
                add_node(node->posX, node->posY-1, w, visited, frontear);
            }
            if(valid_tile(world.data[node->posX][node->posY+1])){
                add_node(node->posX, node->posY+1, w, visited, frontear);
            }
        }
        delete node;
        frontear.pop_front();
    }
    int sum = accumulate(visited.begin(), visited.end(), 0);
    cout << gold << endl;
    return 0;
}
