/*
A modified version of this implementation:
https://github.com/mostafa-saad/ArabicCompetitiveProgramming/blob/master/09%20Graph_Theory/Algorithms_Graph_Theory_14_Strongly_Connected_Components_2.cpp
*/

vector<int> dn, lowLink, comp;
vector<bool> inStk;
stack<int> stk;
stack<pair<int,bool>> recStk;
int dnc;
vector<vector<int>> comps;
void tarjan(int node){
    recStk.push({node, 0});
    while(!recStk.empty()){
        pair<int, bool> p = recStk.top();
        recStk.pop();
        if(p.second){
            for(int i = 0; i < vec[p.first].size(); i++)
                if(inStk[vec[p.first][i]])
                    lowLink[p.first] = min(lowLink[p.first], lowLink[vec[p.first][i]]);
            if(dn[p.first] == lowLink[p.first]){
                comps.push_back({});
                int no = -1;
                while(no != p.first){
                    no = stk.top();
                    stk.pop();
                    inStk[no] = 0;
                    comps[comps.size()-1].push_back(no);
                    comp[no] = comps.size()-1;
                }
            }
        }
        else{
            if(dn[p.first] != -1)
                continue;
            dn[p.first] = lowLink[p.first] = dnc;
            dnc++;
            stk.push(p.first);
            inStk[p.first] = 1;
            recStk.push({p.first, 1});
            for(int i = 0; i < vec[p.first].size(); i++){
                int ch = vec[p.first][i];
                if(dn[ch] == -1)
                    recStk.push({ch, 0});
                else if(inStk[ch])
                    lowLink[p.first] = min(lowLink[p.first], dn[ch]);
            }
        }
    }
}
void SCC(){
    dn.resize(n, -1);
    lowLink.resize(n);
    inStk.resize(n);
    comp.resize(n);
    for(int i = 0; i < n; i++)
        if(dn[i] == -1)
            tarjan(i);
}
