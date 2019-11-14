//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp{}, p{2}, count{};
    int64_t ans{};
    bool recalc{};
    vector<int> lcms(MAX);
    lcms[0] = 1;

    // cout << "n: " << n << " q: " << q << endl;
    vector<int> primes;
    vector<int> factorized(78499);
    vector<int> i_to_p(MAX);
    primes.reserve(78499);
    vector<bool> is_prime;
    is_prime.resize(MAX, true);
    is_prime[0] = false;
    is_prime[1] = false;

    while ( p*p < MAX){
        // cout <<"p" <<  p << endl;
        if(is_prime[p]){
            // cout << "if" << endl;
            for (int i{p*2}; i < MAX; i += p){
                // cout <<"i" <<  i << endl;
                is_prime[i] = false;
            }
        }
        p++;
    }
    //cout << accumulate(is_prime.begin(), is_prime.end(), 0) << endl;
    for(int i{1}; i < MAX; ++i){
        if (is_prime[i]){
            i_to_p[i] = primes.size();
            primes.push_back(i);
        }
    }


    ans=1;
    for(int i{1}; i < MAX; ++i){

        tmp = i;
        recalc = false;
        for(int p: primes){
            if (p > tmp){
                break;
            }
            count = 0;
            while(tmp%p == 0){
                count += 1;
                tmp /= p; 
            }

            if (count > factorized[i_to_p[p]]){
                if (p == 2  || p == 5){
                    recalc = true;
                }
                ans *= p * (count - factorized[i_to_p[p]]);
                factorized[i_to_p[p]] = count;
                while(ans%10 == 0){
                    ans /= 10; 
                }
                ans %= 1000000;
            }
        }
        
        if (recalc){
            ans = 1;
            for(int j{}; j < MAX; ++j ){
                if (primes[j] > i){
                    break;
                }
                if (primes[j] == 2){
                    if(factorized[j] > factorized[2]){
                        ans *= (2*(factorized[j] - factorized[2]));
                    }
                }else if (primes[j] == 5){
                    if(factorized[j] > factorized[0]){
                        ans *= (5*(factorized[j] - factorized[0]));
                    }
                }else{
                    if (factorized[j] > 0)
                        ans *= (primes[j]*factorized[j]);
                }
                while(ans%10 == 0){
                    ans /= 10; 
                }
                ans %= 100000;
            }

        }
        lcms[i] = ans;
        //cout << "i: " << i << " ans: " << ans <<  endl;

        // for(int j{0}; j <= 10; ++j){
        //     cout << factorized[j] << " ";
        // }
        // cout << endl;
        
    }
    cout << "{ ";
    for(int i{0}; i < MAX; ++i){
        cout << lcms[i]%10 << ", ";
        if (i%20 == 0)
            cout << "\n";
    }
    cout << " }";
    cout << endl;
    // while (true)
    // {
    //     cin >> tmp;
    //     if (tmp == 0){
    //         break;
    //     }
    //     cout  << lcms[tmp] << endl;
    // }
    



    
    return 0;
}
