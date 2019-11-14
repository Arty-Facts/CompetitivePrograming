//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    double x{}, y{}, first_x{}, first_y{}, privios_x{}, privios_y{}, ans{};
    
    while (cin >> t){
        ans = 0;
        cin >> first_x >> first_y;
        privios_x = first_x, privios_y = first_y;
        for (int i{1}; i < t; i++){
            cin >> x >> y;
            ans += privios_x*y - privios_y*x;
            privios_x = x, privios_y = y ;
        }
        ans += privios_x*first_y - privios_y*first_x;
        if (ans < 0)
            printf("CW %lf", -ans/2);
        else
            printf("CCW %lf", ans/2);
    }
    return 0;
}
