//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

void solve(int k, int x, int y, int n, int m, int & ans){
    //cout << "k: " << k << " x: " << x << " y: " << y << " n: " << n << " m: " << m << " ans: " << ans  << endl;
    if (k == 0){
        return;
    }
    // define boundaries 
    int N{y + k};
    int S{y - k};
    int E{x + k};
    int W{x - k};

    // if inside the square
    if ( m <= N && m >= S && n >= W && n <= E ){
        ans += 1;
    }

    //expande in every corner of the squere 
    if ((abs(N - m) < k && abs(E - n) < k ) || (abs(N - n) < k && abs(E - m) < k) )
        solve(k/2, N, E, n, m, ans);

    if ((abs(N - m) < k && abs(W - n) < k ) || (abs(N - n) < k && abs(W - m) < k) )
        solve(k/2, N, W, n, m, ans);
    
    if ((abs(S - m) < k && abs(E - n) < k ) || (abs(S - n) < k && abs(E - m) < k) )
        solve(k/2, S, E, n, m, ans);

    if ((abs(S - m) < k && abs(W - n) < k ) || (abs(S - n) < k && abs(W - m) < k) )
        solve(k/2, S, W, n, m, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k{}, n{}, m{}, ans{};
    while(true){
        cin >> k >> n >> m;
        if (k == 0)
            break;
        ans = 0;
        solve(k, 1024, 1024, n, m, ans);
        printf("%3d\n", ans);
    }
    return 0;
}
