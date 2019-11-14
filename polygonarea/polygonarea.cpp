//Arturas Aleksandrauskas - artal938 TDDD95
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Tensor { 
    Tensor() = default;
    ~Tensor() = default;

    Tensor(T x, T y) : x(x), y(y) {}

    Tensor(const Tensor &p) : x(p.x), y(p.y) {}

    Tensor operator + (const Tensor &p) const { 
        return Tensor(x+p.x, y+p.y); 
    }

    Tensor operator - (const Tensor &p) const { 
        return Tensor(x-p.x, y-p.y); 
    }

    Tensor operator * (T c) const { 
        return Tensor(x*c, y*c); 
    }

    Tensor operator / (T c) const { 
        return Tensor(x/c, y/c); 
    }

    bool operator < (const Tensor &p) const { 
        return x < p.x || (x == p.x && y < p.y); 
    }

    T x{}, y{}; 
};

template<typename T>   
T dot(const Tensor<T> &a, const Tensor<T> &b)  { 
    return a.x * b.x + a.y * b.y; 
} 

template<typename T> 
double dist(const Tensor<T> &a, const Tensor<T> &b) { 
    return sqrt(dot<T>(a-b, b-a)); 
}

template<typename T>
T cross(const Tensor<T> &a, const Tensor<T> &b) { 
    return a.x * b.y - a.y * b.x; 
} 

template<typename T>
bool isParallel(const Tensor<T> &p,const Tensor<T> &a, const Tensor<T> &b){ 
    return abs(cross<T>(p-a, p-b)) == 0; 
}

template<typename T>
bool onLine(const Tensor<T> &p, const Tensor<T> &a, const Tensor<T> &b){ 
    if (isParallel<T>(p,a,b) && dot<T>(p-a,p-b) <= 0 ) 
        return true; 
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    double x{}, y{}, ans{};
    
    while (cin >> t){
        if (t == 0)
            break;
        ans = 0;
        vector<Tensor<double>> p;
        for (int i{}; i < t; i++){
            cin >> x >> y;
            p.push_back(Tensor<double>(x,y));
        }
        for (auto point = p.begin(); point != p.end()-1; point++){
            ans += cross<double>(*point, *(point+1));
        }
        ans += cross<double>(*(p.rbegin()), *(p.begin()));

        if (ans < 0)
            printf("CW %.1lf\n", -ans/2);
        else
            printf("CCW %.1lf\n", ans/2);
    }
    return 0;
}
