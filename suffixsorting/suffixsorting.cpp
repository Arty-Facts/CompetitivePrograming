//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;
//use https://www.geeksforgeeks.org/suffix-array-set-1-introduction/
struct Node{

};

struct SuffixSorting{
    vector<vector<char>> suffix_array;
    void construct(string const & word){
        int size = (int)word.size();
        suffix_array.resize(size, vector<char>(size, NULL));



    }
    int get_suffix(){

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    int n{}, tmp{};
    SuffixSorting SA;
    while(getline(cin, word)){
        SA.construct(word);
        cin >> n;
        for (int i{}; i < n; i++){
            cin >> tmp;
        }
        getline(cin, word);
    }


    
    return 0;
}
