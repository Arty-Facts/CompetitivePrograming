//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, tmp{};
    cin >> n;

    for (int i{}; i < n; i++){
        cin >> tmp;
        if (tmp % 2 == 0)
            cout << tmp << " is even" << endl;
        else
            cout << tmp << " is odd" << endl;

    }

    
    return 0;
}
