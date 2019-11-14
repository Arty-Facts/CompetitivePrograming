#include <bits/stdc++.h>
#include <algorithm> 
#include <iostream> 
#include <iterator> 
#include <cstdint>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    uint64_t recived{}, result{}, M{}, first{}, second{};
    int N{}, i{1};
    cin >> M >> N;
    std::priority_queue<uint64_t> demand{};
    istream_iterator<uint64_t> cin_it(cin); // Get input stream and end of stream iterators 
    istream_iterator<uint64_t> eos; 
    // colect childrens wishes and put them in a max qeueu 
    demand.push(0);
    for_each(cin_it, eos, [&demand] (uint64_t n){
        demand.push(n);
    }); 
    while(!demand.empty()){
        first = demand.top();
        demand.pop();
        second = demand.top();
        recived += (first - second) * i++; 
        if(recived > M){
            uint64_t lvl = second + (recived-M)/(--i); //calc the level/number when the last handout accures  
            uint64_t plvl = (recived-M)%(i); // calc number of children that recived candy on the last round 
            result = lvl*lvl*(i-plvl); //children that recived
            lvl++;
            result += lvl*lvl*(plvl); // super angry children
            break;
        }else if(recived == M){
            result = second*second*(--i); // add the hole line to result
            break;
        }
    }
        
    while(!demand.empty()){
        first = demand.top();
        result += first * first; 
        demand.pop();
    }
    return cout << result << endl, 0;
}
