//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;
// found at https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
// Returns modulo inverse of a with respect 
// to m using extended Euclid Algorithm 
// Assumption: a and m are coprimes, i.e., 
// gcd(a, m) = 1 
int64_t modInverse(int64_t a, int64_t m) 
{ 
    int64_t m0 = m; 
    int64_t y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int64_t q = a / m; 
        int64_t t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n{}, t{}, x{}, y{}, ans{};
    char op;

    while(cin >> n >> t){
        if(n+t == 0) break;
        for(int64_t i{}; i<t; i++){
            cin >> x >> op >> y;
            if (op == '+') 
                ans = x + y;
            else if (op == '-') 
                ans = x - y;
            else if (op == '/'){
                if (__gcd(y,n) != 1){ 
                    cout << "-1" << endl;
                    continue;
                }
                ans = x * modInverse(y,n);
            }
            else if (op == '*')
                ans = x * y;
            ans %= n;
            if (ans < 0)
                ans += n;
            cout << ans << endl;

        }
    }
    
    return 0;
}
