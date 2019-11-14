#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// BFS Graf
struct Node
{ 
    int max{};
    int value{};
    Node(string s, int max,int v)
        : max{max}, value{v}{}
}; 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N{}, sum{}, steps{}, tmp{}, max{},value{};
    cin >> N;
    string result{};

    for(int i{}; i < N; i++){
        cin >> steps;
        unordered_map<string,Node> Candy_map{};
        vector<int> data(steps);
        for(int j{}; j < steps; j++){
            cin >> tmp;
            sum += tmp;
            data[j] = tmp;
        }
        if(sum%2 != 0){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        
        for(auto n : data) {
            cout << n << " ";
            //cout << "steps: " << steps << " value: " << n.value << " max: "<< n.max << " higth: "<< n.higth <<'\n';
        }
        cout << endl;
        cout << result << endl;
        data.clear();
    }
    

    return 0;
}

