#include <bits/stdc++.h>
using namespace std;
struct Prest{
    Prest() = default;
    Prest(int max_states){
        prio_list.reserve(max_states);
        state_opt.reserve(max_states);
    }

    vector<int> prio_list;
    vector<int> state_opt;
};

struct States{
    vector<int> neighbors;
};

int main() {
    int n{}, m{}, N{}, state_value{}, state_min{}, N_min{}, max_states{8};
    States states[max_states];
    for(int s{}; s<max_states;s++){
        states[s] = States();
        for (int n{}; n<max_states;n++){
            int nb = (s^n);
            for(int p_two{1}; p_two < max_states; p_two*=2){
                if(nb == p_two)
                    states[s].neighbors.push_back(n);
            }
        }
    }

    scanf("%d", &n);

    for (int test{}; test < n; test++){
        scanf("%d", &m);
        Prest ps[m];
        for(int p_index{}; p_index < m ; p_index++){
            ps[p_index] = Prest(max_states);
            for(int i{}; i < max_states; i++){
                scanf("%d", &ps[p_index].prio_list[i]);
            }
        }
        for(int p_index{m-1}; p_index >= 0 ; p_index--){
            for(int s{}; s < max_states; s++){
                state_min = max_states;
                for(int n{}; n < 3; n++){
                    N = states[s].neighbors[n];
                    state_value = p_index == m-1 ? ps[p_index].prio_list[N] : ps[p_index].prio_list[ps[p_index + 1].state_opt[N]];
                    if (state_min >= state_value){
                        state_min = state_value;
                        N_min = N;
                    }            
                }
                if (p_index == m-1)
                    ps[p_index].state_opt[s] = N_min;
                else
                    ps[p_index].state_opt[s] = ps[p_index + 1].state_opt[N_min];                       
            }
        }
        int v = ps[0].state_opt[0];
        string ans = "";
        for(int i{}; i<3;i++){
            if((v&1) == 1)
                ans = "Y" + ans;
            else
                ans = "N" + ans;
            v >>= 1; 
        }
        cout << ans << endl;
    }

    
    return 0;
}
