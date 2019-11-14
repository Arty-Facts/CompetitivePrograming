#include <bits/stdc++.h>
using namespace std;

struct Node{
    ~Node() = default;
    Node() = default;
    Node(int posX, int posY, int trueCost, int d)
        : posX{posX}, posY{posY}, trueCost{trueCost},huristic{huristic} {}

    
    bool operator() (Node* f, Node* s){
        return f->huristic < s->huristic;
    }

    int posX{};
    int posY{};
    int trueCost{};
    int huristic{};
};
struct World
{
    World(int x, int y):x{x},y{y} {
        map.resize(x, vector<int>(y));
    }
    int manhatan_dist(int fromX, int fromY){
        int dx = fromX - endX;
        int dy = fromY - endY;
        dx = dx < 0 ?-dx:dx;
        dy = dy < 0 ?-dy:dy;
        return dx + dy;

    }
    int aStar(int fromX,int fromY, int toX, int toY){
        if (fromX == toX && fromY == toY)
            return true;

        endX = toX;
        endY = toY;
        valid = map[fromX][fromY];

        vector<vector<int>> viseted;
        viseted.resize(x, vector<int>(y));

        priority_queue<Node*, vector<Node*>, Node> frontear;
        frontear.push(new Node(fromX,fromY,0, manhatan_dist(fromX, fromY)));
        while (!frontear.empty()){
            Node* node = frontear.top();
            frontear.pop();
            if(node->posX == toX && node->posY == toY){
                int ans = node->trueCost;
                delete node;
                while (!frontear.empty()){
                    Node* node = frontear.top();
                    frontear.pop();
                    delete node;
                }
                return ans;
            }

            if(valid_tile(node->posX-1, node->posY))
                add_node(node->posX-1, node->posY, node->trueCost+1 , frontear, viseted);
            if(valid_tile(node->posX+1, node->posY))
                add_node(node->posX+1, node->posY, node->trueCost+1 , frontear, viseted);
            if(valid_tile(node->posX, node->posY-1))
                add_node(node->posX, node->posY-1, node->trueCost+1 , frontear, viseted);
            if(valid_tile(node->posX, node->posY+1))
                add_node(node->posX, node->posY+1, node->trueCost+1 , frontear, viseted);

            delete node;
        }
        return -1;
    }

    bool valid_tile(int xcurr, int ycurr){
        return xcurr >= 0 && xcurr < x && ycurr >= 0 && ycurr < y && map[xcurr][ycurr] == valid;
    }

    void add_node(int posX, int posY, int w, priority_queue<Node*,vector<Node*>, Node>& frontear, vector<vector<int>>& v){
        if(v[posX][posY] == 0){
            v[posX][posY] = 1;
            frontear.push(new Node(posX,posY, w, manhatan_dist(posX,posY)));
        }
        
    }
    int x{};
    int y{};
    int endX{};
    int endY{};
    int valid;
    vector<vector<int>> map;
};


int main() {
    string tmp;
    int y{}, x{};
    cin >> x >> y;
    World world = World(x, y);
    for (int i{}; i < x; i++){
        cin >> tmp;
        for (int j{}; j < y; j++ ){
            world.map[i][j] = ((int)tmp[j])-48;
        }
    }
    int q{};
    cin >> q;
    int fromX{}, fromY{}, toX{}, toY{};
    for(int i{}; i<q ; i++){
        cin >> fromX >> fromY >> toX >> toY;
        cout << world.aStar(fromX-1 ,fromY-1 ,toX-1 ,toY-1) << endl;    
    }

    return 0;
}

