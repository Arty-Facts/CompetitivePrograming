//Arturas Aleksandrauskas artal938 - TDDD95
#include <bits/stdc++.h>
using namespace std;
// KMP

void create_lps(string const & patern, vector<int>& lps){
    int size = patern.size();
    lps.resize(size);
    int ps{};
    for(int ci{1}; ci < size; ci++){
        if (patern[ci] == patern[ps]){
            lps[ci] = ++ps;
        }else{
            if (ps != 0){
                ps = lps[ps-1];
            }else{
                ps = 0;
            }
        }
    }
}

void kmp(string const & sentence, string const & patern, vector<int> const & lps){
    int size = patern.size();
    int pi{};
    for(int it{}; it <= sentence.size(); it++){
        // cout << sentence[it] << endl;
        if (pi == size){
            cout <<  it - size << " ";
            pi = lps[pi-1];
        }else{
            while(pi != 0 && sentence[it] != patern[pi]){
                pi = lps[pi-1];

            }
        }
        if (sentence[it] == patern[pi]){
            ++pi;
        }
        
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string patern{}; 
    string sentence{};
    vector<int> lps;
    while(getline(cin,patern)){
        create_lps(patern, lps);
        //cout << patern << endl;
        // for(int i{}; i < size; i++){
        //     cout << lps[i] << " " ;
        // }
        // cout << endl;
        getline(cin,sentence);
        //cout << sentence << endl;
        kmp(sentence, patern, lps);
    }

    
    return 0;
}
