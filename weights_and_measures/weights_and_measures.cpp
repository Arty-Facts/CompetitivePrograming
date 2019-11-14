//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w{}, s{};
    vector<pair<int, int>> turtels;
    turtels.reserve(5700);
    while(cin >> w >> s){
        turtels.push_back({w,s});
    }
    sort(turtels.begin(), turtels.end(), [](pair<int,int> f, pair<int,int> s) {return f.second < s.second;});
    vector<int> strength(5700, std::numeric_limits<int>::max()/2);
    strength[0] = 0;
    int max_turtels{};
    // for (int i{}; i < (int)turtels.size() ; i++)
    //     cout << turtels[i].first  << " " << turtels[i].second << endl;
    // cout << endl;
    for (int i{}; i < (int)turtels.size() ; i++){
        for (int j{ (int)turtels.size() }; j >= 1 ; j--){
            if(strength[j-1] + turtels[i].first <= turtels[i].second) {
                strength[j] = min(strength[j], strength[j-1] + turtels[i].first);
                max_turtels = max(max_turtels, j);
            }
        }
    }
    // for (int i{}; i < (int)turtels.size() ; i++)
    //     cout << strength[i]  << " ";
    // cout << endl;
    cout << max_turtels << endl;

    
    return 0;
}
