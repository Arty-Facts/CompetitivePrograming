//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n{}, m{}, a{};
    cin >> n >> m >> a;
    //cout <<"n: " << n <<" m: " << m << " a: "<< a << endl;  

    int64_t b = n * m - a;

    if (a%m == 0 || a%n == 0 ){
        cout << 1 << endl;
        return 0;
    }

    for(int64_t i{1}; i < max(n, m); ++i){
        if (a%i == 0  && a/i < m){
            cout << 2 << endl;
            return 0;
        }
        if (b%i == 0  && b/i < m){
            cout << 2 << endl;
            return 0;
        }
    }
    cout << 3 << endl;
    
    return 0;
}
