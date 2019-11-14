#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    uint64_t n{}, ans{1}, tmp{};
    cin >> n;

    for (uint64_t i{2}; i <= n; i++){
        tmp = i;
        for( ;tmp%10 == 0 ; tmp/=10){}
        ans *= tmp;   
        for( ;ans%10 == 0 ; ans/=10){} 
        ans %=1000000000000;
    }
    ans %=1000;
    if(n > 6 && ans < 100)
        cout << "0" ;
    if(n > 6 && ans < 10)
        cout << "0" ;   
    cout << ans<< endl;
    
    return 0;
}
