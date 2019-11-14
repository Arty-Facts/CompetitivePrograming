//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool hifen = true;
    for (auto c: s){
        if (hifen){
            cout << c;
            hifen = false;
        }else if(45 == (int)c ){
            hifen = true;
        }
    }

    
    return 0;
}
