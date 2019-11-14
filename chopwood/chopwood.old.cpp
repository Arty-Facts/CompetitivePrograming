#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, tmp{}, chop{};
    cin >> n;

    unordered_map<int, int> uniqVal{};
    uniqVal.reserve(2*n);
    vector<int> order{};

    priority_queue<int, vector<int>, greater<int>> nextToChop{}; 
    for (int i{}; i < n; i++){
        cin >> tmp;
        if (auto node = uniqVal.find(tmp); node == end(uniqVal))
            uniqVal.insert({tmp, 1});
        else
            node->second += 1;
        order.push_back(tmp);
    }
    if (*rbegin(order) != n+1)
        return cout << "Error" << endl, 0;

    for (int i{1}; i < n+1; i++)
        if (uniqVal.find(i) == end(uniqVal))
            nextToChop.push(i);

    for (int p: order){
        chop = nextToChop.top();
        nextToChop.pop();
        if (auto node = uniqVal.find(p);node != end(uniqVal))
            if (node->second == 1){
                uniqVal.erase(node);
                nextToChop.push(p);
            }else{
                node->second -= 1;
            }
        cout << chop << endl;
    }
    return 0;
}