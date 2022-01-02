#include <bits/stdc++.h>

using namespace std;

vector<string> cmds;
unordered_map<string, int> Labels;
vector<int> Variables('z' - 'a' + 1);
deque<unsigned short> Q;


int  main(){

    ifstream cin ("quack.in");
    ofstream cout ("quack.out");

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string command;

    while (cin >> command) {
        if (command[0] == ':') {
            Labels[command.substr(1)] = cmds.size();
        }
        cmds.push_back(command);
    }

    for (int current = 0; current < cmds.size(); current++) {

        if (cmds[current][0] == '+') {
            int x = Q.front();
            Q.pop_front();
            int y = Q.front();
            Q.pop_front();
            Q.push_back(x + y);

        } else if (cmds[current][0] == '-') {
            int x = Q.front();
            Q.pop_front();
            int y = Q.front();
            Q.pop_front();
            Q.push_back(x - y);

        } else if (cmds[current][0] == '*') {
            int x = Q.front();
            Q.pop_front();
            int y = Q.front();
            Q.pop_front();
            Q.push_back(x * y);

        } else if (cmds[current][0] == '/') {
            int x = Q.front();
            Q.pop_front();
            int y = Q.front();
            Q.pop_front();
            if (y != 0) {
                Q.push_back(x / y);
            }
            else {
                Q.push_back(0);
            }

        } else if (cmds[current][0] == '%') {
            int x = Q.front();
            Q.pop_front();
            int y = Q.front();
            Q.pop_front();
            if (y != 0) {
                Q.push_back(x % y);
            }
            else{
                Q.push_back(0);
            }

        } else if (cmds[current][0] == '>') {
            int x = Q.front();
            Q.pop_front();
            Variables[cmds[current][1] - 'a'] = x;

        } else if (cmds[current][0] == '<') {
            int x = Variables[cmds[current][1] - 'a'];
            Q.push_back(x);

        } else if (cmds[current] == "P") {
            int x = Q.front();
            Q.pop_front();
            cout << x << "\n";

        } else if (cmds[current][0] == 'P') {
            cout << Variables[cmds[current][1] - 'a'] << "\n";

        } else if (cmds[current] == "C") {
            int x = Q.front();
            Q.pop_front();
            cout << (unsigned char)(x);

        } else if (cmds[current][0] == 'C') {
            cout << (unsigned char)(Variables[cmds[current][1] - 'a']);

        } else if (cmds[current][0] == ':') {
            continue;

        } else if (cmds[current][0] == 'J') {
            current = Labels[cmds[current].substr(1)] - 1;

        } else if (cmds[current][0] == 'Z') {
            if (Variables[cmds[current][1] - 'a']) {
                continue;
            }
            current = Labels[cmds[current].substr(2)] - 1;

        } else if (cmds[current][0] == 'E') {
            if (Variables[cmds[current][1] - 'a'] != Variables[cmds[current][2] - 'a']) {
                continue;
            }
            current = Labels[cmds[current].substr(3)] - 1;

        } else if (cmds[current][0] == 'G') {
            if (Variables[cmds[current][1] - 'a'] <= Variables[cmds[current][2] - 'a']) {
                continue;
            }
            current = Labels[cmds[current].substr(3)] - 1;

        } else if (cmds[current] == "Q") {
            return 0;

        } else {
            Q.push_back(stoi(cmds[current]));
        }
    }

}