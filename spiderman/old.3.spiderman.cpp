#include <bits/stdc++.h>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
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
    int roof{}, deck{}, at{},remainding{}, iterations{};
    cin >> N;
    string result{};
    deque<Node>::iterator it;
    deque<Node> fronterar{};
    bool print = false;

    for(int i{}; i < N; i++){
        cin >> steps;
        fronterar.clear();
        fronterar.push_back(Node("",0,0));
        gmax = gsum= rsum = sum = at = iterations = 0;
        vector<int> data(steps);
        for(int j{}; j < steps; j++){
            cin >> tmp;
            data[j] = tmp;
            sum += tmp;
            if (gmax < tmp){
                gsum = sum;
                gmax = tmp;
                at = j;
            }
        }
        vector<int> max_at(steps);
        vector<int>::iterator max_it = data.begin();
        vector<int> sum_at(steps);
        for(int j{}; j < steps; j++){

            auto ans = max_element(max_it, data.end());
            max_at[j] = *ans;
            sum_at[j] = accumulate(max_it, ans + 1, 0);
    
            max_it++;
        }
        if (print){
            for(auto n: data)
                cout << n << " ";
            cout << endl;
            for(auto n: max_at)
                cout << n << " ";
            cout << endl;
            for(auto n: sum_at)
                cout << n << " ";
            cout << endl;
        }
        //cout << "gsum: " << gsum << endl;
        if(sum%2 != 0){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        rsum = sum;
        int curr{};
        for(int j{}; j < steps; j++){
            //cout << "sum: " << sum << " at: "<< at << " fsize: " << fsize <<  endl;
            tmp = data[j];
            curr += tmp;
            rsum -= tmp;
            fsize = fronterar.size();
            gmax = sum_at[j];
            if (print)
                cout << " gmax: " << gmax << " curr: "<< curr << " sum_at: " <<  sum_at[j] << endl;
            roof = gmax < rsum ? gmax: rsum;
            roof = roof > sum/2 ? sum/2 : roof;
            deck = sum_at[j] - max_at[j];
            if (print)
                cout << "deck: " << deck <<" roof: " << roof << " j: "<< j << endl;
            for (int k{}; k < fsize ; k++){
                iterations++;
                it = begin(fronterar);
                remainding = steps-j;
                if (print)
                    cout <<"remainding: "<< remainding << " higth: " << it->higth <<" tmp: " << tmp << " result: " << it->value<< endl;
                //cout << "result: " << it->value << endl;
                //cout << "J: " << j <<" tmp: "<< tmp << " value: " << it->value << " max: "<< it->max << " higth: "<< it->higth <<'\n';
                if (remainding == 1 && tmp == it->higth){
                    if (print)
                        cout << "D" << endl;
                    fronterar.push_back(Node(it->value + "D",it->max,0));
                }else if (j == 0){
                    if (print)
                        cout << "U" << endl;
                    fronterar.push_back(Node(it->value + "U",tmp,tmp));
                }else if ( (roof >= it->higth + tmp || it->higth - tmp >= deck) && remainding > 1){
                    if (print)
                        cout << "U and D" << endl;
                    higth = it->higth + tmp;
                    max = higth > it->max ? higth: it->max;
                    if (roof >= higth)
                        fronterar.push_back(Node(it->value + "U",max,higth));
                    higth = it->higth - tmp;
                    if (higth >= deck && higth >= 0)
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
        if (print)
            cout <<"result: " << result << endl;
        cout << result << endl;
        data.clear();
    }
    

    return 0;
}