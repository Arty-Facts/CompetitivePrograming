#include <bits/stdc++.h>
using namespace std;
struct Node{
    ~Node() = default;
    Node(int posX, int posY, int at_turn): posX{posX}, posY{posY}, at_turn{at_turn} {}
    int posX{};
    int posY{};
    int at_turn{};
};
struct World
{
    World(){
        map.resize(8, vector<int>(8));
    }
    int find(int x,int y){
        int steps{};
        map[x][y] = 1;
        deque<Node*> frontear;
        frontear.push_back(new Node(x,y, 1));
        while (!frontear.empty()){
            Node* node = frontear.front();
            frontear.pop_front();
            steps = max(steps, node->at_turn);

            if(valid_tile(node->posX+2, node->posY-1))
                add_node(node->posX+2, node->posY-1, node->at_turn+1 , frontear);
            if(valid_tile(node->posX+2, node->posY+1))
                add_node(node->posX+2, node->posY+1, node->at_turn+1 , frontear);
            if(valid_tile(node->posX-2, node->posY-1))
                add_node(node->posX-2, node->posY-1, node->at_turn+1 , frontear);
            if(valid_tile(node->posX-2, node->posY+1))
                add_node(node->posX-2, node->posY+1, node->at_turn+1 , frontear);

            if(valid_tile(node->posX-1, node->posY+2))
                add_node(node->posX-1, node->posY+2, node->at_turn+1 , frontear);
            if(valid_tile(node->posX+1, node->posY+2))
                add_node(node->posX+1, node->posY+2, node->at_turn+1 , frontear);
            if(valid_tile(node->posX-1, node->posY-2))
                add_node(node->posX-1, node->posY-2, node->at_turn+1 , frontear);
            if(valid_tile(node->posX+1, node->posY-2))
                add_node(node->posX+1, node->posY-2, node->at_turn+1 , frontear);

            delete node;
        }
        return steps;
    }

    bool valid_tile(int x, int y){
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

    void add_node(int posX, int posY, int w,deque<Node*>& frontear){
        if (map[posX][posY] == 0){
            map[posX][posY] = w;
            frontear.push_back(new Node(posX,posY, w));
        }
    }
    vector<vector<int>> map;
};


int main() {
    vector<char> trans{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int t{};
    cin >> t;
    for (int i{}; i < t; i++){
        char char_x{};
        int y{}, x{};
        cin >> char_x >> y;
        for(int j{}; j < 8; j++){
            if(trans[j] == char_x){
                x = j;
                break;
            }
        }
        World world = World();
        int max_steps = world.find(x, y-1);
        for (int i{7}; i >= 0; i--){
            for (int j{0}; j < 8; j++ )
                cout << world.map[j][i] << " ";
            cout << endl;
        }
        cout << endl;
        cout << max_steps-1 << " ";
        for (int i{7}; i >= 0; i--){
            for (int j{0}; j < 8; j++ ){ 
                if(world.map[j][i] == max_steps){
                    cout << trans[j] << i+1 << " ";
                }
            }
        }
        cout << endl;

        
    
    }

    
    return 0;
}
