#include <bits/stdc++.h>

using namespace std;
const int UP=1,DOWN=-1;
//Wagner–Fisher Algorithm
struct DP{
    int input[40];
    int data[40][1000];
    int dir[40][1000];
    int end{};

};

int solve(int i, int h, DP &dp){
    printf("h: %2d i:%2d\n", h , i);
    if (i == dp.end)
        return h;
    if (dp.dir[i][h] != 0)
        return dp.data[i][h];

    int next_dist{dp.input[i]};
    int next_d = solve(i+1, h - next_dist, dp); 
    int next_u = solve(i+1, h + next_dist, dp);

    if (h >= 0 && h <= 1000){
        if (next_u > next_d){
            dp.data[i][h] = next_d;
            dp.dir[i][h] = DOWN;
        }else{
            dp.data[i][h] = next_u;
            dp.dir[i][h] = UP;
        }
    }
    return dp.data[i][h];
}


int main() {
    int tests{};
    scanf("%d", &tests);

    for(int i{}; i < tests; i++){
        DP dp = DP();
        scanf("%d", &dp.end);
        for(int j{}; j < dp.end; j++)
            scanf("%d", &dp.input[j]);
        for(int k{}; k < dp.end; k++)
            printf("%d ", dp.input[k]);
        printf("\n");
        solve(0,0, dp);
        printf("\n");
        for(int j{}; j < 8; j++){
            for(int k{}; k < 8; k++)
                printf("%2d ", dp.data[j][k]);
            printf("\n");
        }
        
    }
    return 0;
} 