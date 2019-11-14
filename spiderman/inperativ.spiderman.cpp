#include <bits/stdc++.h>

using namespace std;
//Wagner–Fisher Algorithm

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testcases{}, step{}, steps{}, max{1000}, min{0}, up{}, down{};
    cin >> testcases;
    string result{};
    for(int i{}; i < testcases; i++){
        cin >> steps;
        int data[steps], order[steps];
        int mem[steps][max];

        for(int j{}; j < steps; j++){
            cin >> step;
            data[i] = step;
            // if (max < step)
            //     max = step;
        }
        for(int j{}; j < steps; j++){
            for (int k{}; k <= max-data[i]; k++){
                up = j + data[i];
                down = j- data[i];
                if (down >= min){
                    
                }else if(up <= max){
                    
                }
            }    
        }

        for (int k{}; k < steps; k++){
           for (int d{}; d < 100; d++)
               cout << mem[k][d] << " ";
           cout << endl;
       }

    }

    return 0;
}