//artal938

#include <bits/stdc++.h>
using namespace std;

int solve(string& word){
    //cout << word << endl;
    //cout << "size: " << word.size() << endl;

    auto first = begin(word);
    auto last = rbegin(word);
    //cout << word << endl;
    int ans{};
    int mid = word.size();
    for (int i{}; i <= mid; i++){
        //cout << word << endl;
        //cout << *first << " " << *last << endl;
        if(*first != *last){
            auto r = next(first);
            auto l = next(last);
            int it = i;
            while(it++ <= mid-i){
                if(*l == *first){
                    ans += distance(last, l);
                    while (l != last) swap(*--l, *l);
                    break;
                }else if(*r == *last){
                    ans += distance(first, r);
                    while (r != first) swap(*--r, *r);
                    break;
                }
                ++r;
                ++l;
            }
            if(it > mid-i){
                return -1;
            }
        
        }
        ++first;
        ++last;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{};
    string word;
    cin >> n;

    getline(cin, word);
    for (int i{}; i < n; i++){
        //cin >> word;
        getline(cin, word);

        int ans = solve(word);

        if (ans == -1)
            cout <<"Impossible" << endl;
        else
            cout <<  ans << endl;        
    }
    return 0;
}
