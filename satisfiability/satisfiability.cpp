//Arturas Aleksandrauskas - artal938 TDDD95


#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<pair<int, bool>>> & expresions, int comb){
    for(auto expresion: expresions){
        bool satisfide{false};
        for(auto e: expresion){
            if(e.second){
                satisfide = satisfide || ((~comb) & (1 << e.first));
            }else{
                satisfide = satisfide || (comb & (1 << e.first));
            }
        }
        if (!satisfide){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, m{}, t{};
    string imput;
    cin >> t;
    for (int i{}; i < t; i++){
        cin >> n >> m;
        vector<vector<pair<int, bool>>> expresions;
        expresions.resize(m, vector<pair<int, bool>>());
        getline(cin,imput);
        for (int j{}; j < m; j++){
            getline(cin,imput); 
            bool neg{false};
            int pos{};
            for(char c: imput){
                if (c == ' '){
                    continue;
                }else if(c == '~'){
                    neg = true;
                }else if(c == 'X'){
                    continue;
                }else if(c == 'v'){
                    expresions[j].push_back({pos-1, neg});
                    pos = 0;
                    neg = false;
                }else{
                    pos *= 10;
                    pos += (int)c-48;
                }
            }
            expresions[j].push_back({pos-1, neg});
        }
        // cout << "---------------" << endl;
        // for (auto expre :expresions){
        //     for (auto e :expre){
        //         if(e.second){
        //             cout << "~" << e.first  << " ";
        //         }else{
        //             cout << e.first << " ";
        //         }
        //     }
        //     cout << endl;
        // }
        bool sati{false};
        for(int j{(1<<n)-1}; j >= 0; j--){
            if (solve(expresions, j)){
                cout << "satisfiable" << endl;
                sati = true;
                break;
            }
        }
        if(!sati){
            cout << "unsatisfiable" << endl;
        }
    }

    
    return 0;
}