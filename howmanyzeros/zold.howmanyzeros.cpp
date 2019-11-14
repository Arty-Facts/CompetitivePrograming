#include <bits/stdc++.h>
using namespace std;

int64_t zeros_counter(int64_t number) {
    int64_t ans{}, pos{1}, rest{};
    while (number > 0) {
        int64_t digi = number%10;
        number /= 10;
        if (digi == 0)
            ans += (number-1)* pos + 1 + rest;
        else 
            ans += number*pos;
        rest += pos*digi;
        pos *= 10;
    }
    return ans;
}

int64_t initial_zeros(int64_t number) {
    int64_t ans{};
    do { 
        if (number%10 == 0) 
            ans++;
        number /= 10;
    } while ( number > 0 );
    return ans;
}

int main () {
    int64_t m,n;
    while (true) {
        scanf("%ld%ld", &m,&n);
        if ( m < 0 ) 
            break;

        int64_t ans;
        ans = zeros_counter(n);
        ans -= zeros_counter(m);
        ans += initial_zeros(m);
        printf("%ld\n",ans);
    }
}