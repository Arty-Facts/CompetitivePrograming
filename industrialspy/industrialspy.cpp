//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;
#define REP(var, k) for (int var = 0; var < (int) k; ++var)

vector<bool> getprimes(int n){
    vector<bool> primes;
    primes.resize(n+1, true);
    primes[0] = false;
    primes[1] = false;
    int p = 2;

    while ( p*p <= n){
        // cout <<"p" <<  p << endl;
        if(primes[p]){
            // cout << "if" << endl;
            for (int i{p*2}; i <= n; i += p){
                // cout <<"i" <<  i << endl;
                primes[i] = false;
            }
        }
        p++;
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c = 0;
    string string_numbers;
    cin >> c;
    getline(cin, string_numbers);
    REP(i, c) 
    {
        vector<int> numbers;
        getline(cin, string_numbers);
        for(auto c: string_numbers)
        {
            int n = (int)c-48;
            //cout << (int)c-48 << endl;
            numbers.push_back(n);
        }
        sort(numbers.begin(), numbers.end(), greater<int>());

        int greatest_number = 0;
        for(auto n: numbers)
        {
            greatest_number *= 10;
            greatest_number += n;

        }

        int curr_number = 0;
        int nr_primes = 0;
        vector<bool> primes;
        primes = getprimes(greatest_number);
        sort(numbers.begin(), numbers.end());
        
        set<int> s;
        do
        {
            curr_number = 0;
            for(auto n: numbers)
            {
                curr_number *= 10;
                curr_number += n;
            }
            //cout << "curr number: " << curr_number << endl;
            //cout << "length of primes: " << primes.size() << endl;
            
            if(primes[curr_number] && s.find(curr_number) == s.end())
            {
                s.insert(curr_number);
                nr_primes++;
            }



            while(curr_number > 0)
            {
                curr_number /= 10;
                if(primes[curr_number] && s.find(curr_number) == s.end())
                {   
                    s.insert(curr_number);
                    nr_primes++;
                } 
            }

            
        } while (next_permutation(numbers.begin(), numbers.end()));
        cout << nr_primes << "\n";
        

        //cin >> number;
        //cout << number << endl;
    }   
    // cout << "n: " << n << " q: " << q << endl;
    vector<bool> primes;

    
    return 0;
}