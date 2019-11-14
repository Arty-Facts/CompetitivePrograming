#include <bits/stdc++.h>
using namespace std;
struct BIT{
    BIT( int64_t n)
    :n{n}
    {
        fw.reserve(n+1);
    }
    int64_t sum(int64_t i){
        int64_t sum = 0; 
        while(i > 0){
            sum += fw[i];
            i -= i & (-i);// i & (-i)  returns the decimal value of last set digit
        }
        // cout << "sum: " << sum << endl;
        return sum;   
    }  
    void update(int64_t i, int64_t val){ 
        i++;
        while (i <= n){
            fw[i] += val;
            i += i & (-i); // i & (-i)  returns the decimal value of last set digit
        } 
        // for (int64_t i{}; i <= n; i++)
        //     cout << fw[i] << " ";
        // cout << endl;
    }
    vector<int64_t> fw;
    int64_t n{};
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t N{}, Q{}, i{}, v{};
    char op;
    cin >> N >> Q;
    BIT fw = BIT(N);
    for (int64_t x{}; x < Q ; x++){
        cin >> op;
        if (op == '+'){
            cin >> i >> v;
            fw.update(i, v);
        }else{
            cin >> i;
            printf("%ld\n", fw.sum(i));
        }

    }
    return 0; 
}
