#include <bits/stdc++.h>
using namespace std;
int t, src, des, idx[10000], tonm[10000];
bool nprm[10000];
vector<vector<int>> vec;
int main() {
    //freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "wt", stdout);
    int c = 1;
    for (int i = 2; i < 10000; i++)
        if (!nprm[i]) {
            if (i > 999) {
                idx[i] = c;
                tonm[c] = i;
                c++;
            }
            for (int e = i + i; e < 10000; e += i)
                nprm[e] = 1;
        }
    vec.resize(c + 1);
    for (int i = 1; i < c; i++) {
        stringstream ss;
        ss << tonm[i];
        string s;
        ss >> s;
        for (int e = i + 1; e < c; e++) {
            string s2;
            ss.clear();
            ss << tonm[e];
            ss >> s2;
            int co = 0;
            for (int d = 0; d < s.size(); d++)
                co += (s[d] != s2[d]);
            if (co == 1) {
                vec[i].push_back(e);
                vec[e].push_back(i);
            }
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &src, &des);
        bool vis[10000];
        memset(vis, 0, sizeof(vis));
        src = idx[src];
        des = idx[des];
        queue<pair<int, int>> qu;
        qu.push({ src, 0 });
        bool ok = 0;
        while (!qu.empty()) {
            pair<int, int> p = qu.front();
            qu.pop();
            if (p.first == des) {
                printf("%d\n", p.second);
                ok = 1;
                break;
            }
            if (vis[p.first])
                continue;
            vis[p.first] = 1;
            for (int i = 0; i < vec[p.first].size(); i++)
                qu.push({ vec[p.first][i], p.second + 1 });
        }
        if(!ok)
            printf("Impossible\n");
    }
    return 0;
} 
