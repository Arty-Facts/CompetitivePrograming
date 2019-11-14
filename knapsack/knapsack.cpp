#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node(int p, int w, int i): p{p}, w{w}, i{i} {}
    int p; // profit
    int w; // weight
    int i; // index
};

int max(int a, int b) { return (a > b)? a : b; } 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, cap{}, p{}, w{};
    double capacity{};
    while(cin >> capacity >> n){
        cap = static_cast<int>(capacity);
        vector<Node> obj;
        for (int i{}; i < n; i++){
            cin >> p >> w;
            obj.push_back(Node(p,w,i));
        }
        sort(obj.begin(), obj.end(), [](auto f, auto s){return f.p < s.p;});
        // for (int i{}; i < n; i++){
        //     cout << obj[i].q <<" => " <<  obj[i].w << endl;
        // }
        int dp[n+1][cap+1];
        for (int i{}; i <= n; i++){ 
            for (int w{}; w <= cap; w++){
                dp[i][w] = 0;
            } 
        }
        // solve
        for (int i{}; i <= n; i++){ 
            for (int c{}; c <= cap; c++){ 
                if (i==0 || c==0) 
                    dp[i][c] = 0; 
                else if (obj[i-1].w <= c) 
                    dp[i][c] = max(obj[i-1].p + dp[i-1][c-obj[i-1].w],  dp[i-1][c]); 
                else
                    dp[i][c] = dp[i-1][c]; 

            } 
        }
        // for (int i{n}; i >= 0; i--){ 
        //     for (int w{}; w <= cap; w++){ 
        //         cout << dp[i][w] << " "; 
        //     } 
        //     cout << endl;
        // }
        // cout << endl;
        // print

        int count{};
        string ans("");
        
        while(n > 0 && cap > 0){
            //cout <<"n: " << n << " cap " << cap << " see: " << dp[n][cap] <<" W: " << obj[n-1].p << endl;
            if(dp[n][cap] != dp[n-1][cap]){
                count++;
                ans += to_string(obj[n-1].i) + " ";
                cap -= obj[n-1].w;
            }
            n--;
        }
        if(count != 0)
            ans.replace(ans.end()-1, ans.end(),"");

        cout << count << endl;
        cout << ans << endl;

    }
    return 0;
}
