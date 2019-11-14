#include <bits/stdc++.h>
#include <deque>
#include <string>
#include <vector>
using namespace std;

// BFS Graf
struct Node
{ 
    string value{};
    int max{};
    int higth{};
    Node(string v, int max,int higth)
        : value{v}, max{max}, higth{higth}{}
}; 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N{}, sum{} , rsum{}, gsum{}, steps{}, tmp{}, fsize{}, gmax{}, max{},higth{};
    int roof{}, at{},remainding{}, iterations{};
    cin >> N;
    string result{};
    deque<Node>::iterator it;
    deque<Node> fronterar{};

    for(int i{}; i < N; i++){
        cin >> steps;
        fronterar.clear();
        fronterar.push_back(Node("",0,0));
        gmax = gsum= rsum = sum = at = iterations = 0;
        vector<int> data(steps);
        
        for(int j{}; j < steps; j++){
            cin >> tmp;
            sum += tmp;
            data[j] = tmp;
            if (gmax < tmp){
                gmax = tmp;
                at = j;
            }
        }
        for(int j{}; j < at; j++){
            gsum += data[j];
        }
        //cout << "gsum: " << gsum << endl;
        if(sum%2 != 0){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        for(int j{}; j < steps; j++){
            tmp = data[j];
            rsum += tmp;
            gsum -= tmp;
            fsize = fronterar.size();
            cout << "gsum: " << gsum << " at: "<< at << " fsize: " << fsize <<  endl;

            roof = 2*gmax < sum -rsum ? 2*gmax - 1 : sum - rsum;
            for (int k{}; k < fsize ; k++){
                iterations++;
                it = begin(fronterar);
                remainding = steps-j;
                //cout << "left: " << it->higth + gsum <<" max: " << max<< endl;
                //cout << "J: " << j <<" tmp: "<< tmp << " value: " << it->value << " max: "<< it->max << " higth: "<< it->higth <<'\n';
                if (remainding == 1 && tmp == it->higth){
                    //cout << "last" << endl;
                    fronterar.push_back(Node(it->value + "D",it->max,0));
                }else if (roof < it->higth-tmp || (j < at && it->higth + tmp+gsum < gmax)){
                    //cout << "kicked" << endl;
                }else if (tmp > it->higth && remainding > 1){
                    //cout << "u" << endl;
                    higth = it->higth + tmp;
                    max = higth > it->max ? higth: it->max;
                    fronterar.push_back(Node(it->value + "U",max,higth));
                }else if (roof < it->higth + tmp && remainding > 1){
                    //cout << "roof" << endl;
                    higth = it->higth - tmp;
                    fronterar.push_back(Node(it->value + "D",it->max,higth));
                }else if (remainding > 1){
                    //cout << "else" << endl;
                    higth = it->higth + tmp;
                    max = higth > it->max ? higth: it->max;
                    fronterar.push_back(Node(it->value + "U",max,higth));

                    higth = it->higth - tmp;
                    fronterar.push_back(Node(it->value + "D",it->max,higth));
                }
                fronterar.pop_front();
            }
        }
        //cout <<"iterations: " << iterations << endl;
        if (fronterar.empty()){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        max = 10000;
        for(auto n : fronterar) {
            if (n.max < max){
                max = n.max;
                result = n.value;
            }
            //cout << "steps: " << steps << " value: " << n.value << " max: "<< n.max << " higth: "<< n.higth <<'\n';
        }
        cout << result << endl;
        data.clear();
    }
    

    return 0;
}

// function TREE-SEARCH(problem) returns a solution, or failure
//     initialize the frontier using the initial state of problem
//     loop do
//         if the frontier is empty then return failure
//             choose a leaf node and remove it from the frontier
//         if the node contains a goal state then return the corresponding solution
//             expand the chosen node, adding the resulting nodes to the frontier