#include <bits/stdc++.h>
using namespace std;
class UnionFind {
    int *id;
    int *size;
    
    public:
        UnionFind(int N) 
        {
            size = new int[N];
            id = new int[N];

            if (N<0) {
                throw invalid_argument( "received negative value");
            }

            for (int i{}; i <  N; ++i){
                size[i] = 1;
                id[i] = i;
            }
            
        }
        ~UnionFind(){
	        delete [] id;
	        delete [] size;
        }

        int find(int p){
            int root = p;
            while(root != id[root]){
                root = id[root];
            }

            //Path compression
            while(p != root){
                int next = id[p];
                id[p] = root;
                p = next;
            }

            
            return root;
        }

        void uni(int x, int y)
        {
            int root_x = find(x);
            int root_y = find(y);

            if(root_x == root_y)
                return;

            if(size[x] > size[y]){
                id[root_y] = root_x;
                size[x] += size[y];
            } else {
                id[root_x] = root_y;
                size[y] += size[x];
            }
            
            
        }

};


struct Node{
    ~Node() = default;
    Node() = default;
    Node(int posX, int posY)
    : posX{posX}, posY{posY} {}

    int posX{};
    int posY{};
};
struct World
{
    World(int x, int y):x{x},y{y}, uf{UnionFind(x*y)} {
        map.resize(x, vector<int>(y));
        viseted.resize(x, vector<bool>(y));
    }

    void precalc(){ 
        deque<Node*> frontear;
        frontear.push_back(new Node(0,0));
        viseted[0][0] = true;
        while (!frontear.empty()){
            Node* node = frontear.front();
            frontear.pop_front();

            if(valid_tile(node->posX-1, node->posY))
                add_node(node->posX-1, node->posY, node, frontear);
            if(valid_tile(node->posX+1, node->posY))
                add_node(node->posX+1, node->posY, node, frontear);
            if(valid_tile(node->posX, node->posY-1))
                add_node(node->posX, node->posY-1, node, frontear);
            if(valid_tile(node->posX, node->posY+1))
                add_node(node->posX, node->posY+1, node, frontear);

            delete node;
        }
    


    }
    bool find(int fromX,int fromY, int toX, int toY){
        if (uf.find(fromX+x*fromY) ==  uf.find(toX+ x*toY))
            return true;
        return false;
    }

    bool valid_tile(int xcurr, int ycurr){
        return xcurr >= 0 && xcurr < x && ycurr >= 0 && ycurr < y ;
    }

    void add_node(int posX, int posY, Node*& node, deque<Node*>& frontear){
        if (map[posX][posY] == map[node->posX][node->posY])
            uf.uni(node->posX+ x*node->posY, posX+x*posY);
        if(!viseted[posX][posY]){
            viseted[posX][posY] = true;
            frontear.push_back(new Node(posX,posY));
        }
        
    }
    int x{};
    int y{};
    UnionFind uf;
    vector<vector<int>> map;
    vector<vector<bool>> viseted;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string tmp;
    int y{}, x{}, fromX{}, fromY{}, toX{}, toY{}, q{};
    cin >> x >> y;
    World world = World(x, y);
    for (int i{}; i < x; i++){
        cin >> tmp;
        for (int j{}; j < y; j++ ){
            world.map[i][j] = ((int)tmp[j])-48;
        }
    }
    world.precalc();
    cin >> q;
    for(int i{}; i<q ; i++){
        cin >> fromX >> fromY >> toX >> toY;
        if (!world.find(fromX-1 ,fromY-1 ,toX-1 ,toY-1))
            cout <<"neither" << endl;
        else{
            if(world.map[fromX-1][fromY-1] == 1)
                cout <<"decimal" << endl;
            else
                cout <<"binary" << endl;  
        }
        
    }

    return 0;
}
