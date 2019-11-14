//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, q{}, p{2}, qi{};
    cin >> n >> q;
    // cout << "n: " << n << " q: " << q << endl;
    vector<bool> primes;
    primes.resize(n+1, true);
    primes[0] = false;
    primes[1] = false;

    while ( p*p <= n){
        // cout <<"p" <<  p << endl;
        if(primes[p]){
            // cout << "if" << endl;
            for (int i{p*2}; i <= n; i += p){
                // cout <<"i" <<  i << endl;
                primes[i] = false;
            }
        }
        p++;
    }
    //printf("%d\n", accumulate(primes.begin(), primes.end(), 0));
    cout << accumulate(primes.begin(), primes.end(), 0) << endl;
    for(int i{}; i < q; i++){
        cin >> qi;
        //printf("%d\n", primes[qi]);
        cout << primes[qi] << endl;
    }
    
    return 0;
}
