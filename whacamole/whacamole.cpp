#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main() {
    int n{}, m{}, d{}, steps{};
    int x{}, y{}, t{}, tmp{}, hitt{};
    while (true){
        scanf("%d %d %d", &n, &d, &m);
        if(n + d + m  == 0) break; 
        steps = d;
        d = min(d, 2);
        int maxT{}, currX{}, currY{}, ans{}, gcd{};
        double dist{};
        vector<vector<vector<int>>> map;
        map.resize(11, vector<vector<int>>(n+2*d, vector<int>(n+2*d)));
        vector<vector<vector<int>>> dp;
        dp.resize(11, vector<vector<int>>(n+2*d, vector<int>(n+2*d)));
        vector<vector<pair<int,int>>> mole(11);

        for (int i{}; i < m; i++ ){
            scanf("%d %d %d", &x, &y, &t);
            mole[t].push_back({x,y});
            if (t > maxT)
                maxT = t;
            map[t][x+d][y+d] = 1;
        }
        for(int t{1}; t <= maxT; t++){
        for(int x{}; x < n+2*d; x++){
        for(int y{}; y < n+2*d; y++){
        for(int i{-steps}; i <= steps; i++){   
        for(int j{-steps}; j <= steps; j++){
        gcd = __gcd(abs(i), abs(j));
        currX = x-i;
        currY = y-j;
        hitt = 0;

        if(currX >= 0 && currX < n+2*d && currY >= 0 && currY < n+2*d && sqrt(j*j+i*i) <= steps){
            hitt += map[t][x][y];
            for(int k{}; k < gcd; k++){
                hitt += map[t][currX+(k*i)/gcd][currY+(k*j)/gcd];

            }
            tmp = max(dp[t][x][y], hitt + dp[t-1][currX][currY]);
            dp[t][x][y] = tmp;
            ans = max(ans, tmp);
        }}}}}}
        printf("%d\n",ans);
    }
    return 0;
}
