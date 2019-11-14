#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

struct Node{
    ~Node() = default;
    Node(int posX, int posY): posX{posX}, posY{posY} {}
    int posX{};
    int posY{};
};

class GameMap{
    public:
        GameMap(int n, int d): n{n}, d{d} {
            map.resize(11, vector<vector<int>>(n+2*d, vector<int>(n+2*d)));
        }

        void add(int x, int y, int t){
            if (t > maxT)
                maxT = t;
            map[t][x+d][y+d] = 1;
        }

        void all_cuts(int x, int y,int t, int step, vector<vector<int>>& privios){
            int hitt{};
            for(int i{-step}; i <= step; i++){   
                for(int j{-step}; j <= step; j++){
                    int gcd = __gcd(abs(i), abs(j));
                    int currX = x-i;
                    int currY = y-j;
                    double dist = sqrt(j*j+i*i);

                    if(valid_tile(currX, currY) && dist <= step){
                        hitt += map[t][x][y];
                        for(int k{}; k < gcd; k++){
                            hitt += map[t][currX+(k*i)/gcd][currY+(k*j)/gcd];

                        }
                        map[0][x][y] = max(map[0][x][y], hitt + privios[currX][currY]);
                    }
                    hitt = 0;
                }
            }
        }

        void all_cuts_bfs(int x, int y,int t, int step, vector<vector<int>>& privios){
            //cout << "time " << t << endl;
            deque<Node*> frontear;
            frontear.push_back(new Node(x,y));
            vector<vector<bool>> viseted;
            viseted.resize(n+2*d , vector<bool>(n+2*d));
            while (!frontear.empty()){
                Node* node = frontear.front();
                frontear.pop_front();

                int dx = x - node->posX;
                int dy = y - node->posY;
                int gcd = __gcd(abs(dx), abs(dy));
                double dist = sqrt(dx*dx+dy*dy);

                if (dist > (double)step){
                    delete node;
                    continue;
                }

                int hitt{map[t][x][y]};
                for (int k{0}; k < gcd ; k++ ){
                    hitt += map[t][node->posX + (k*dx)/gcd][node->posY + (k*dy)/gcd];   
                }

                map[0][x][y] = max(map[0][x][y], hitt + privios[node->posX][node->posY]);

                if(valid_tile(node->posX, node->posY-1))
                    add_node(node->posX, node->posY-1, x, y, step , frontear, viseted);
                if(valid_tile(node->posX, node->posY+1))
                    add_node(node->posX, node->posY+1, x, y, step , frontear, viseted);
                if(valid_tile(node->posX-1, node->posY))
                    add_node(node->posX-1, node->posY, x, y, step , frontear, viseted);
                if(valid_tile(node->posX+1, node->posY))
                    add_node(node->posX+1, node->posY, x, y, step , frontear, viseted);

                delete node;
            }
        }

        bool valid_tile(int x, int y){
            return x >= 0 && x < n+2*d && y >= 0 && y < n+2*d;
        }

        void add_node(int posX, int posY, int inX, int inY, int steps, deque<Node*>& frontear, vector<vector<bool>>& viseted){
            if (viseted[posX][posY])
                return;
            viseted[posX][posY] = true;
            frontear.push_back(new Node(posX,posY));
            
        }
        void at_time(int t, int step, vector<vector<int>> privios){
            for(int x{}; x < n+2*d; x++){
                for(int y{}; y < n+2*d; y++){
                    all_cuts(x, y, t, step, privios);
                }
                //printT(0);
            }
        }
        

        int compute(int step){
            for(int t{1}; t <= maxT; t++){
                //printT(t);
                at_time(t, step,  map[0]);
                //printT(0);
            }
            int m{};
            for(int x{}; x < n+2*d; x++){
                for(int y{}; y < n+2*d; y++){
                    m = max(map[0][x][y], m);
                }
            }
            return m;

        }
        void printT(int t){
            cout << "--------" << " time: " << t << " --------"<< endl;
            for(int j{}; j < n+2*d; j++){
                for(int k{}; k < n+2*d; k++){
                    cout << map[t][k][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        void print_all(){
            for(int i{}; i <= maxT; i++){
                printT(i);
            }
        }
    private:
        int n{};
        int d{};
        int maxT{};
        vector<vector<vector<int>>> map;
};

int main() {

    int n{}, m{}, d{};
    int x{}, y{}, t{};
    while (true){
        scanf("%d %d %d", &n, &d, &m);
        if(n + d + m  == 0) break; 
        GameMap map = GameMap(n, min(2, d));
        for (int i{}; i < m; i++ ){
            scanf("%d %d %d", &x, &y, &t);
            map.add(x, y, t);
        }
        printf("%d\n",map.compute(d));
        //map.print_all();



    }
    return 0;
}
