#include <bits/stdc++.h>
#define PI (acos(-1.0))
#define INF INT_MAX/2
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define mp make_pair
using namespace std;
 
///cout << fixed << setprecision(12) << p << endl;
 
#define mx 100005


vector< vector< int > > adj(mx); 
vector< bool > bilai(mx);

int maximum_bilai;
int ans;

void dfs(int curr,int par, int current_bilai){
    
    if(current_bilai > maximum_bilai)
        return;

    int okay = 1;

    for(int child : adj[curr]){
        // if not leaf node okay gets the value of zero
        if(child != par)
            okay = 0, dfs(child, curr, current_bilai * bilai[child] + bilai[child]);
    }

    /// okay gets added only if curr is a leaf node and current bilai is <= maximum_bilai
    ans += okay;

}


int main(){
    int nodeN;

    scanf("%d %d", &nodeN, &maximum_bilai);

    int bilaiache;
    for(int i = 1; i <= nodeN; i++){
        scanf("%d",&bilaiache);
        bilai[i] = bilaiache;
    }

    for(int i = 1; i <= nodeN - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // passing bilai[1] as the current bilai as we can have bilai in the first node.
    dfs(1, -1, bilai[1]);

    printf("%d\n", ans);

    return 0;
}
