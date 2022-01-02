#include <bits/stdc++.h>


using namespace std;

const int mod1 = 1000027;
const int mod2 = 1000000411;

struct node {
    pair<int, int> x;           // первый и второй хеш
    string s;                   // значение
    node *l = nullptr, *r = nullptr;        // указатели на левую и правую часть

    node(pair<int, int> x1, string s1) {
        x = x1;
        s = std::move(s1);
    }
};

struct BST {                // бст фром 6 лаба =)

    node *head = nullptr;

    vector<string> Ans;

    BST(pair<int, int> x, string s) {
        head = new node(x, std::move(s));
    }

    void add(pair<int, int> x, const string& s) {

        if (!head) {
            head = new node(x, s);
            return;
        }

        node *cur = head;

        while (true) {
            if (x < cur->x) {           // при сравнении пар, сначала сравнивается первый, потом второй
                if (cur->l) {
                    cur = cur->l;
                } else {
                    cur->l = new node(x, s);
                    return;
                }
            } else if (x > cur->x) {
                if (cur->r) {
                    cur = cur->r;
                } else {
                    cur->r = new node(x, s);
                    return;
                }
            } else {
                return;
            }
        }

    }

    void pop(pair<int, int> x) {

        if (!head) {
            return;
        }

        node *prev = nullptr;
        node *cur = head;
        node *l, *r;
        bool right = false;

        while (true) {
            if (x < cur->x) {
                if (cur->l) {
                    prev = cur;
                    right = false;
                    cur = cur->l;
                } else {
                    return;
                }
            } else if (x > cur->x) {
                if (cur->r) {
                    prev = cur;
                    right = true;
                    cur = cur->r;
                } else {
                    return;
                }
            } else {
                l = cur->l;
                r = cur->r;
                delete cur;
                break;
            }
        }

        if (!prev) {
            head = l;
        } else if (right) {
            prev->r = l;
        } else {
            prev->l = l;
        }

        cur = l;

        if (!cur && !prev) {
            head = r;
        } else if (!cur && right) {
            prev->r = r;
        } else if (!cur) {
            prev->l = r;
        }

        if (!cur) {
            return;
        }

        while (cur->r) {
            cur = cur->r;
        }

        cur->r = r;
    }

    void inOrder(node *x) {     // сохраняем дерево на стеке

        if (!x) {
            return;
        }

        Ans.push_back(x->s);
        inOrder(x->l);
        inOrder(x->r);
    }

    vector<string> &get() {
        Ans.clear();
        inOrder(head);
        return Ans;
    }

};

struct myMap {
    vector<vector<pair<string, BST>>> map;  // мапа представляет из себя пары ключ и бинарное дерево значений

    myMap() {
        map.resize(mod1);
    }

    static int hash(const string& x) {
        long long hash = 0;
        for (char i : x) {
            hash *= 47;
            hash += i - 'a' + 1;
            hash = ((hash % mod1) + mod1) % mod1; // ищем хеш, исключая отрицательные индексы
        }
        return (int)hash;
    }

    static int hash2(const string& x) {
        long long hash = 0;
        for (char i : x) {
            hash *= 47;
            hash += i - 'a' + 1;
            hash = ((hash % mod2) + mod2) % mod2;
        }
        return (int)hash;
    }

    void add(const string& x, const string& y) {
        int d = hash(x);
        for (auto &h: map[d]) {
            if (x == h.first) {
                h.second.add({hash(y), hash2(y)}, y);
                return;
            }
        }
        map[d].push_back(make_pair(x, BST({hash(y), hash2(y)}, y)));
    }

    void delAll(const string& x) {
        int d = hash(x);
        for (int i = 0; i < map[d].size(); i++) {
            if (map[d][i].first == x) {
                swap(map[d][i], map[d][map[d].size() - 1]);
                map[d].pop_back();
                return;
            }
        }
    }

    vector<string> get(const string& x) {
        int d = hash(x);
        for (auto &y: map[d]) {
            if (y.first == x) {
                return y.second.get();
            }
        }
        return {};
    }

    void del(const string& x, const string& y) {
        int d = hash(x);
        for (auto &h: map[d]) {
            if (x == h.first) {
                h.second.pop({hash(y), hash2(y)});
                return;
            }
        }
    }
};


int main() {

    ifstream basicIfstream("multimap.in");
    ofstream basicOfstream("multimap.out");

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
        }
        else if (s == "get") {
            vector<string> ans = map.get(x);        // получаем вектор значений, выводим размер и сами элементы
            basicOfstream << ans.size();
            for (auto &y: ans) {
                basicOfstream << " " << y;
            }
            basicOfstream << endl;
        }
        else if (s == "deleteall") {
            map.delAll(x);
        }
        else if (s == "delete") {
            string y;
            basicIfstream >> y;
            map.del(x, y);
        }

    }
}