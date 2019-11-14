#include <bits/stdc++.h>
using namespace std;

int64_t calc_p(int64_t b, int64_t x){
    int64_t p{1}, prod{b};
    while(x > prod){
        prod *= b; p++;
    }
    if (prod == x)
        return p;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t x{},p{};
    bool neg{true};
    while(cin >> x){
        if (x == 0)
            break;
        neg = x < 0 ? true: false;    
        x = neg ? -x: x;
        p = 0;
        for (int64_t b{2}; b*b < x+1 ; b++ ){
            if (x%b == 0){
                p = calc_p(b, x);
                if (p == 0)
                    continue;
                if(neg){
                    if(p%2 != 0){
                        printf("%ld\n", p);
                        break;
                    }
                    p = 0;
                }else{
                    printf("%ld\n", p);
                    break;
                }
            }
        }
        if(p == 0)
           printf("%d\n", 1); 
    }
    return 0;
}
