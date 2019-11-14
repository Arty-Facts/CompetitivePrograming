//Arturas Aleksandrauskas artal938 - TDDD95
#include <bits/stdc++.h>
using namespace std;
// AhoCorasick

struct OutNode{
    OutNode(string p, OutNode *n) : patern(p), next(n) { }
    string patern;
    OutNode* next;
};
struct Node{
    map<char , Node*> next;
    Node* failure;
    OutNode* out;
};

struct AhoCorasick{
    Node *go_to;
    int N;
    map<string,int> p_to_i;

    AhoCorasick(vector<string> const & paterns) {
        N = paterns.size();
        go_to = new Node();
        int index{};
        for(auto p: paterns) {
            Node *cur = go_to;
            p_to_i[p] = index++;
            for(auto c: p)
                cur = cur->next.find(c) != cur->next.end() ? cur->next[c] :
                    cur->next[c] = new Node();
            cur->out = new OutNode(p, cur->out);
        }
        queue<Node*> q;
        for(auto a: go_to->next) {
            q.push(a.second);
        }

        while (!q.empty()) {
            Node *r = q.front(); 
            q.pop();
            for(auto a: r->next) {
                Node *s = a.second;
                q.push(s);
                Node *st = r->failure;
                while (st && st->next.find(a.first) == st->next.end())
                    st = st->failure;
                if (!st) 
                    st = go_to;
                s->failure = st->next[a.first];
                if (s->failure) {
                    if (!s->out) 
                        s->out = s->failure->out;
                    else {
                        OutNode* out = s->out;
                        while (out->next) 
                            out = out->next;
                        out->next = s->failure->out;
                    }
                }
            }
        }
    }

    vector<vector<int>> match(string const & sentence) {
        vector<vector<int>> res(N);
        Node *cur = go_to;
        for(auto c=sentence.begin(); c!=sentence.end(); ++c ){
            while (cur && cur->next.find(*c) == cur->next.end())
                cur = cur->failure;
            if (!cur) 
                cur = go_to;
            cur = cur->next[*c];
            if (!cur) 
                cur = go_to;
            for (OutNode *out = cur->out; out; out = out->next){
                int pos = c - sentence.begin() - out->patern.size()+1;
                if(res[p_to_i[out->patern]].empty() || pos != res[p_to_i[out->patern]].back()){
                    res[p_to_i[out->patern]].push_back(pos);
                }
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string sentence{};
    string tmp{};
    int p{};
    while (cin >> p)
    {
        vector<string> paterns(p);
        getline(cin,tmp);
        for (int i{}; i < p; i++){
            getline(cin,paterns[i]);
        }
        AhoCorasick AC(paterns);
        getline(cin,sentence);
        vector<vector<int>> res = AC.match(sentence);
        for (auto patern: paterns){
            for (int pos : res[AC.p_to_i[patern]]){
                printf("%d ", pos); 
            }
            printf("\n");
        }
    }


    
    return 0;
}