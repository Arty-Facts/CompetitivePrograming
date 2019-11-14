//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int manhatan(pair<int, int> & f,pair<int, int> & t){
    return abs(f.first-t.first) + abs(f.second-t.second);
}

int calc_dist(pair<int, int> start, vector<pair<int,int>> & pappers){
    pair<int, int> tmp = start;
    int dist{};
    for(pair<int, int> p: pappers){
        dist += manhatan(tmp, p);
        tmp = p;
    }
    dist += manhatan(tmp, start);
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int p{}, t{}, startX{}, startY{}, x{}, y{}, dist{};
    cin >> t;
    vector<pair<int, int>> pappers;
    for (int i{}; i < t; i++){
        cin >> startX >> startY;
        cin >> startX >> startY;
        cin >> p;
        pappers.clear();
        pappers.reserve(p);
        for (int j{}; j < p; j++){
            cin >> x >> y;
            pappers.push_back(make_pair(x,y));
        }
        sort(pappers.begin(), pappers.end());
        dist = 400;
        do{
            dist = min(dist, calc_dist({startX, startY},pappers));
        } while (next_permutation(pappers.begin(), pappers.end()));
        cout << dist << "\n";
    }

    
    return 0;
}
