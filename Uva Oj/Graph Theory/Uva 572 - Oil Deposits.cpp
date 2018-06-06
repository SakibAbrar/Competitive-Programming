#include <stack>
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

#define maxn 105

int m, n;

bool grid[maxn][maxn];

bool vis[maxn][maxn];

///direction array for adjacent cells
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};

int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};


void floodfil(int r, int c){

    if( r<0 || c<0 || r>m || c>n ) return;

    if(vis[r][c]) return;

    if(!grid[r][c]) return;

    vis[r][c] = 1;




    for(int i = 0; i<8; i++){

        floodfil(r+dr[i], c+dc[i]);

    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("output.txt", "w", stdout);

	while(cin >> m >> n, m){

        int cnt = 0;
        int ans = 0;

        memset(vis, 0, sizeof vis);
        memset(grid, 0, sizeof grid);

        for(int i = 0; i<m; i++){

            for(int j = 0; j<n; j++){

                char ch;
                cin >> ch;

                if(ch == '*')
                    grid[i][j] = 0, cnt++;

                else
                    grid[i][j] = 1;

            }

        }

        for(int i = 0; i<m; i++){

            for(int j = 0; j<n; j++){

                if(!vis[i][j]){

                    ans++;
                    floodfil(i, j);

                }

            }

        }
        
        /// cout << "ans : " << ans << endl;
        /// cout << "cnt : " << cnt << endl;
        
        cout << ans - cnt << endl;

    }

    return 0;

}
