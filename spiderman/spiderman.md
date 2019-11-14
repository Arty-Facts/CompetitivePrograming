int solve(int i, int h, int end, int dp[40][1000]){
    if (i == end)
        return h;
    int next_dist{};
    cin >> next_dist;
    int next_u = solve(i+1, h + next_dist, end, &dp);
    int next_d = solve(i+1, h - next_dist, end, &dp);

    if (next_u > next_d)
        dp[i][h] = 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tests{}, steps{};
    cin >> tests;

    for(int i{}; i < tests; i++){
        cin >> steps;
        int dp[steps][1000];
        solve(0,0,steps,dp);
        


    return 0;
}