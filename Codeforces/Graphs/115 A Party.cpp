#include <bits/stdc++.h>
#define INF INT_MAX/2
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define mx 2005
using namespace std;

vector<vector<int>> adj(mx);  // adjacency list representation

vector<bool> used(mx);
vector<int> dist(mx), parent(mx);

int ans;

void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
                ans = max(ans, dist[u]);
                parent[u] = v;
            }
        }
    }
}

int main(){
    int nodeN;

    scanf("%d", &nodeN);

    int manager;

    vector <int> bfs_chalao;

    for(int i = 1; i <= nodeN; i++){
        scanf("%d",&manager);
        if(manager == -1)
            bfs_chalao.push_back(i);
        else
            adj[manager].push_back(i);
    }

    for(int chalao : bfs_chalao)
        bfs(chalao);

    printf("%d\n", ans + 1);

    return 0;
}
