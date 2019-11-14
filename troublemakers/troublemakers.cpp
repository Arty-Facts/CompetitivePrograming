//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tests{}, n{}, m{}, u{}, v{};
    cin >> tests;
    vector<vector<int>> tm;
    vector<int> cls;

    for (int i{}; i < tests; i++){
        cin >> n >> m;
        tm.clear();
        cls.clear();
        tm.resize(n+1, vector<int>());
        cls.resize(n+1);
        for (int j{}; j < m; ++j){
            cin >> u >> v;
            tm[u].push_back(v);
            tm[v].push_back(u);
        }
        // for (vector<int> path: tm){
        //     cout << path.size() << " "; 
            
        // }
        // cout << endl;
        for (int j{1}; j <= n; ++j){
            int firstCls{};
            int secondCls{};
            for(int k: tm[j]){
                if (cls[k] == 0){
                    firstCls++;
                }else{
                    secondCls++;
                }
            }
            if (secondCls < firstCls){
                cls[j] = 1;
            }
        }
        int tot = accumulate(cls.begin(), cls.end(), 0);
        cout << "Case #" << i+1 << ": " << tot << "\n";
        for (int j{1}; j <= n; ++j){
            if (cls[j] == 1){
                cout << j << " ";
            }
        }
        cout << "\n";
    }

    
    return 0;
}
