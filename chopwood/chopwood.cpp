#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, tmp{}, chop{};
    cin >> n;

    vector<int> order(2*n);
    priority_queue<int, vector<int>, greater<int>> nextToChop{};
    for (int i{}; i < n; i++){
        cin >> tmp;
        order[n+tmp-1] += 1;
        order[i] = tmp;
    }
    if (order[n-1] != n+1)
        return cout << "Error" << endl, 0;

    for (int i{}; i < n; i++)
        if (order[n+i] == 0)
            nextToChop.push(i+1);

    for (int i{}; i < n; i++){
        tmp = order[i];
        chop = nextToChop.top();
        nextToChop.pop();
        order[n+tmp-1] -= 1;
        if (order[n+tmp-1] == 0)
            nextToChop.push(tmp);
        printf("%i\n", chop);
    }
    return 0;
}
