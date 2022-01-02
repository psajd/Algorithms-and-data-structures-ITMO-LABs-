#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int mod = 1000029;

struct node {

    string x, y;
    node *prev, *next;

    explicit node(string x1 = "", string y1 = "", node *prev1 = nullptr, node *next1 = nullptr) {
        x = std::move(x1);
        y = std::move(y1);
        next = next1;
        prev = prev1;
    }

    void del() {
        x = "";
        y = "";
        prev = nullptr;
        next = nullptr;
    }
};

struct temp {
    node a[200005];
    int last = 0;

    void push(node x) {
        a[last++] = std::move(x);
    }

    node *back() {
        return &a[last - 1];
    };
} temp;


struct myMap {

    vector<vector<node *>> map;
    node *last = nullptr;

    myMap() {
        map.resize(mod);
    }

    static int hash(const string &x) {
        int hash = 0;
        for (char i: x) {
            hash *= 47;
            hash += i - 'a' + 1;
            hash = ((hash % mod) + mod) % mod;
        }
        hash %= mod;
        return hash;
    }

    void add(const string &x, const string &y) {
        int h = hash(x);
        for (auto p: map[h]) {
            if (p->x == x) {
                p->y = y;
                return;
            }
        }
        temp.push(node(x, y));
        map[h].push_back(temp.back());
        push(map[h].back());
    }

    void push(node *x) {
        if (last == nullptr) {
            last = x;
            return;
        }
        x->prev = last;
        last->next = x;
        last = x;
    }

    void del(const string &x) {
        int h = hash(x);
        for (int i = 0; i < map[h].size(); i++) {
            if (map[h][i]->x == x) {
                pop(map[h][i]);
                swap(map[h][i], map[h].back());
                map[h].pop_back();
                return;
            }
        }
    }

    void pop(node *x) {
        if (!x->next) {
            last = x->prev;
            if (last) {
                last->next = nullptr;
            }
        } else {
            x->next->prev = x->prev;
            if (x->prev) {
                x->prev->next = x->next;
            }
        }
        x->del();
    }

    string get(const string &x) {
        int h = hash(x);
        for (auto p: map[h]) {
            if (p->x == x) {
                return p->y;
            }
        }
        return "none";
    }

    string prev(const string &x) {
        int h = hash(x);
        for (auto p: map[h]) {
            if (p->x == x) {
                if (p->prev) {
                    return p->prev->y;
                } else {
                    return "none";
                }
            }
        }
        return "none";
    }

    string next(const string &x) {
        int h = hash(x);
        for (auto p: map[h]) {
            if (p->x == x) {
                if (p->next) {
                    return p->next->y;
                } else {
                    return "none";
                }
            }
        }
        return "none";
    }
};

int main() {

    ifstream basicIfstream("linkedmap.in");
    ofstream basicOfstream("linkedmap.out");

    ios_base::sync_with_stdio(false);
    basicIfstream.tie(nullptr);
    basicOfstream.tie(nullptr);

    myMap map;
    string s;

    while (basicIfstream >> s) {

        string x;
        basicIfstream >> x;

        if (s == "put") {
            string y;
            basicIfstream >> y;
            map.add(x, y);
        } else if (s == "delete") {
            map.del(x);
        } else if (s == "get") {
            basicOfstream << map.get(x) << endl;
        } else if (s == "prev") {
            basicOfstream << map.prev(x) << endl;
        } else if (s == "next") {
            basicOfstream << map.next(x) << endl;
        }

    }

}