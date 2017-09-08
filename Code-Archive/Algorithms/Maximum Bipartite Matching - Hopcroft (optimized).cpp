#include <bits/stdc++.h>
using namespace std;
int n, m, p; // 1-indexed, n 1st set of nodes 1->n, m 2nd set of nodes n+1->n+m, p edges
const int mxv = 100001; // maximum number of nodes at all
vector<int> vec[mxv];
int mnode[mxv], vis[mxv], qvis[mxv], prv[mxv], it; // mnode->matched node, zero if not matched
queue<pair<int,int>> qu;
bool dfs(int nxt){
    if(vis[nxt] == it)
        return 0;
    vis[nxt] = it;
    if(nxt <= n && !mnode[nxt])
        return 1;
    if(nxt <= n)
        return dfs(prv[nxt]);
    bool ret = dfs(prv[nxt]);
    if(ret){
        mnode[nxt] = prv[nxt];
        mnode[prv[nxt]] = nxt;
    }
    return ret;
}
void hopcroft(){
    bool again = 1;
    while(again){
        it++;
        for(int i = 1; i <= n; i++)
            if(!mnode[i])
                qu.push({i, 0});
        vector<int> dfsv;
        int flvl = 1 << 30;
        while(!qu.empty()){
            pair<int, int> frnt = qu.front();
            qu.pop();
            if(frnt.second > flvl)
                continue;
            if(frnt.first > n && !mnode[frnt.first]){
                dfsv.push_back(frnt.first);
                flvl = frnt.second;
            }
            if(frnt.second == flvl)
                continue;
            if(frnt.first > n){
                qu.push({mnode[frnt.first], frnt.second + 1});
                prv[mnode[frnt.first]] = frnt.first;
            }
            else{
                for(int i = 0; i < vec[frnt.first].size(); i++)
                    if((!mnode[frnt.first] || mnode[frnt.first] != vec[frnt.first][i]) && qvis[vec[frnt.first][i]] != it){
                        qu.push({vec[frnt.first][i], frnt.second + 1});
                        prv[vec[frnt.first][i]] = frnt.first;
                        qvis[vec[frnt.first][i]] = it;
                    }
            }
        }
        for(int i = 0; i < dfsv.size(); i++)
            dfs(dfsv[i]);
        again = dfsv.size() > 0;
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> p;
    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        b += n; //important
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    hopcroft();
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += mnode[i] != 0;
    cout << ans << '\n';
    return 0;
}
