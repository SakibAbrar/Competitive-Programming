#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#define INF 2147483647
//#define INF 9223372036854775807


using namespace std;


const int maxn = 105;
int T;
int N;
vector<int> adj[maxn];
vector<bool>vis(maxn, false);
vector<bool> visited(maxn, false);
int cases;

void dfs(int source, int restriction){
    vis[source] = 1;
    if(source==restriction) return;
    for(int v: adj[source]){
        if(!vis[v])
            dfs(v, restriction);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("output.txt", "w", stdout);

    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i<N; i++){
            adj[i].clear();
            vis[i] = 0;
            visited[i] = 0;
            for(int j = 0; j<N; j++){
                bool inp;
                cin >> inp;
                if(inp){
                    adj[i].push_back(j);
                }
            }
        }

        cout << "Case " << ++cases << ":" << endl;

        dfs(0, -1);

        ///visited = vis
        for(int j = 0; j<N; j++){
            visited[j] = vis[j];
        }


        ///
        cout << "+";
        for(int k = 0; k<2*N-1; k++)
            cout <<"-";
        cout << "+"  << endl;
        ///
        for(int i = 0; i<N; i++){
            if(visited[i]){
                for(int t = 0; t<N; t++)
                    vis[t] =0;
                dfs(0, i);
                cout << "|";
                for(int j = 0; j<N; j++){
                    if(i==j)
                        cout << "Y|";
                    else if(vis[j])
                        cout << "N|";
                    else if(!vis[j] && visited[j])
                        cout << "Y|";
                    else
                        cout << "N|";
                }
                cout << endl;

                dfs(0, -1);
            }
            else{
                cout << "|";
                for(int j = 0; j<N; j++ ){
                    cout << "N|";
                }
                cout << endl;
            }
            ///
            cout << "+";
            for(int k = 0; k<2*N-1; k++)
                cout <<"-";
            cout << "+" << endl;
        ///
        }

    }

}

