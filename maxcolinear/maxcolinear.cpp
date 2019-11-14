//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

double MAX  = numeric_limits<double>::max();

int main() {
    int n{}, ans{};
    int x{}, y{};
    double dx{}, dy{}, slope{};

    unordered_map<double, int> count;
    count.reserve(5000);
    vector<pair<int,int>> points;

    while (true){
        scanf("%d", &n);
        if(n == 0) break; 
        points.resize(n);

        for (int i{}; i < n; i++ ){
            scanf("%d %d", &x, &y);
            points[i] = {x,y};
        }
        ans = 0;
        auto end = points.begin() + min(n, 63);
        for(auto origin = points.begin(); origin != end; origin++){
            count.clear();
            for(auto point = origin+1; point != points.end(); point+=1){
                dx = point->first - origin->first;
                dy = point->second - origin->second;

                if (dx == 0){
                    slope = dy < 0 ? - MAX: MAX;
                }else{
                    slope = dy/dx;
                }

                if (count.find(slope) == count.end()){
                    count.insert({slope, 1});
                }else{
                    count[slope] += 1;
                }   
            }
            for(auto& c: count){
                ans = max(ans, c.second);
            }
        }
        
        printf("%d\n",ans+1);
    }
    return 0;
}