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

template<typename T>
bool isTensorInPolygon(const Tensor<T> &p, vector<Tensor<T>> &poly) {
    bool c{false};
    int j = poly.size() -1;
    for (int i{}; i < (int)poly.size(); i++){
        if (((poly[i].y > p.y) != (poly[j].y > p.y)) 
            && (p.x < poly[i].x + (poly[j].x - poly[i].x) * (p.y - poly[i].y) 
            /  (poly[j].y - poly[i].y)))
            c = !c;
        j = i;
    }
    return c;

}

template<typename T>
bool isTensorOnPolygon(const Tensor<T> &p, vector<Tensor<T>> &poly){
    int j = poly.size()-1;
    for (int i{}; i<(int)poly.size(); i++){
        if (onLine<T>(p, poly[i], poly[j]))
            return true;
        j = i;
    }
    return false;
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{},m{}, x{}, y{};    
    while (cin >> n){
        if (n == 0)
            break;

        vector<Tensor<double>> points;
        for (int i{}; i<n ;i++ ){
            cin >> x >> y;
            points.push_back(Tensor<double>(x,y));
        }
        cin >> m;
        for (int i{}; i<m ;i++ ){
            cin >> x >> y;
            Tensor<double> p = Tensor<double>(x,y);
            if (isTensorOnPolygon<double>(p,points)) 
                cout << "on" << endl;
            else if (isTensorInPolygon<double>(p, points)) 
                cout << "in" << endl;
            else 
                cout << "out" << endl;
        }

    }
    return 0;
}
