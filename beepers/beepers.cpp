//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int manhatan(vector<pair<int, int>>::iterator f,vector<pair<int, int>>::iterator t){
    return abs(f->first-t->first) + abs(f->second-t->second);
}
int manhatan(pair<int, int> const & f,pair<int, int> const & t){
    return abs(f.first-t.first) + abs(f.second-t.second);
}

int calc_dist(pair<int, int> const & start, vector<pair<int,int>> & pappers, int min_d){
    auto tmp = pappers.begin();
    int dist{manhatan(*tmp, start)};
    for(auto p = pappers.begin()+1; p != pappers.end(); ++p){
        dist += manhatan(tmp, p);
        tmp = p;
        if (dist > min_d){
            return dist;
        }
    }
    dist += manhatan(*tmp, start);
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
            dist = min(dist, calc_dist({startX, startY},pappers, dist));
        } while (next_permutation(pappers.begin(), pappers.end()));
        cout << dist << "\n";
    }

    
    return 0;
}
