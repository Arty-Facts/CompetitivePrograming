//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;
// https://brilliant.org/wiki/extended-euclidean-algorithm/
void exeuclid(int a, int b, int &x ,int &y) {
    if (!b) x = 1, y = 0;
    else exeuclid(b, a%b, y, x),y -=x * (a/b);
}
  
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t{},a{}, n{}, b{}, m{};
    cin >> t;
    for(int i{}; i< t; i++){
        cin >> a >> n >> b >> m;
        int x{}, y{};
        exeuclid(n,m, x,y);
        int k = n*m;
        int t = a*x*n+b*y*m;
        printf("%d %d\n", t, k);

    }
    return 0; 
} 