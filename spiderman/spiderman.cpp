#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node(Node const& ) = default;
    Node() = default;
    Node(int value,int index, int max_value, string path)
        : value{value}, index{index}, max_value{max_value}, path{path}
        {}
    int value{};
    int index{};
    int max_value{};
    string path;
};

void expand_node(int heigth, Node* &n, Node* p, queue<Node*> &q, string opt, int M ){
        if(n == nullptr){
            if (p->index < M-2 || heigth == 0){
                Node*  next_node = new Node(heigth, p->index+1 ,(heigth > p->max_value ? heigth : p->max_value), p->path + opt);
                if (p->index < M-2){
                    q.push(next_node);
                }
                n = next_node;
            }
        }else{
            if(p->max_value < n->max_value){
                n->max_value = (n->value > p->max_value) ? n->value : p->max_value;
                n->path = p->path + opt;
            }
        }
}

int main() {
    int tests{};
    int M{};
    scanf("%d", &tests);
    
    for(int i{}; i < tests; i++){
        scanf("%d", &M);
        queue<Node*> q;
		int data[M];
        int heigth{};
        Node* dp_array[40][1000];
        for(int j{}; j < 40; j++){
            for(int k{}; k < 1000; k++){
                dp_array[j][k] = nullptr; 
            }
        }
		for(int j{}; j < M; j++)
            scanf("%d", &data[j]);
        
        Node* root = new Node(data[0],0 , data[0], "U");
        q.push(root);
        dp_array[0][root->value] = root;

        while(!q.empty()){ 
            Node* p = q.front();
            // U
            heigth = p->value+data[p->index+1];
            Node* &n = dp_array[p->index+1][heigth];
            expand_node(heigth, n, p, q, "U", M);
            dp_array[p->index+1][heigth] = n;
            //D
            if(p->value >= data[p->index+1]){
                heigth = p->value - data[p->index+1];
                Node* n = dp_array[p->index+1][heigth]; 
                expand_node(heigth, n, p, q, "D", M);
                dp_array[p->index+1][heigth] = n;
            }
            q.pop();
            delete p;
        }
        Node* n = dp_array[M-1][0];
        if (n == nullptr)
            printf("IMPOSSIBLE\n");
        else{
            cout << n->path << endl;
        }
        delete n;
		
	} 
    return 0;
} 
