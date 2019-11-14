#include <bits/stdc++.h>
#include <algorithm> 
#include <iostream> 
#include <iterator> 
#include <vector>
#include <map>
#include <cstdint>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    uint64_t result{};
    int N{}, M{};
    cin >> M >> N;
    long int take{-M};

    map<int,int> Candy_map{};
    istream_iterator<int> cin_it(cin); // Get input stream and end of stream iterators 
    istream_iterator<int> eos; 
    // colect the number of distinct cande demand of the children 
    for_each(cin_it, eos, [&Candy_map, &take] (auto n){
        take += n; //calc the amount of candy to take
        map<int,int>::iterator it = Candy_map.find(n);
		if (it != Candy_map.end()) {
			it->second++;	
		}
		else {
			Candy_map.insert(make_pair(n, 1));
		}
    }); 
    if (take <= 0)
        return cout << 0 << endl, 0; // if there is enof candy
    int privios{};
    int diff{};
    int lvl{};
    int plvl{};
    map<int,int>::iterator it;
    for(auto it: Candy_map){
        diff = it.first - privios;
        cout << "it: " << it.first << " diff: " << diff<< " take: " << take << " N: " << N <<  endl;
        take -= it.second * N;
        result += (it.second * ( it.first * it.first)); //take the last candy
        cout << "result: " << result << endl;
        if (take < diff*N){
            plvl = take - N % N ;
            lvl = privios + take - N / N;
            cout << " diff: " << diff<< " plvl: " << plvl << " lvl: " << lvl << " N: " << N <<  endl;
            result += +lvl*lvl*(N-plvl);
            lvl++;
            result += lvl*lvl*(plvl);
            break;
        }else if (take == diff*N){

            break;
        }
        N -= it.second; // reduce the amount children to take from
        privios = it.first;
    }
    return cout << result << endl, 0;
}