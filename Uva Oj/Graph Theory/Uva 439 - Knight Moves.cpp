#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;

bool ifValid(int r, int c){

	((r<8 && r>=0) && (c<8 && c>=0)) ? true: false;
  
}

int drR[8] = {-2,-1,1,2,2,1,-1,-2};
int drC[8] = {1,2,2,1,-1,-2,-2,-1};

int dist[8][8];

string conv = "abcdefgh";


int bfs(int r, int c, int desR, int desC){

	dist[r][c] = 1;

	queue<pii> q;

	q.push({r, c});

	while(!q.empty()){

		pii top = q.front();
		q.pop();

		if(top == make_pair(desR, desC))
			return dist[desR][desC];
	
		for(int i = 0; i<8; i++){
			int rr, cc;

			rr = top.first + drR[i];
			cc = top.second + drC[i];

			if(ifValid(rr, cc)){
      
				if(!dist[rr][cc]){
        
					dist[rr][cc] = dist[top.first][top.second] + 1;
					q.push({rr, cc});
          
				}
        
			}
      
		}
    
	}
  
}


 
int main()
{
   string node1, node2;

   //freopen("output.txt", "w", stdout);

   while(cin >> node1 >> node2){

   	   memset(dist, 0, sizeof dist);

       int r1, c1, r2, c2;

       r1 = node1[1] - '0';
       r2 = node2[1] - '0';

       c1 = conv.find(node1[0]);
       c2 = conv.find(node2[0]);

       int ans = bfs(r1, c1, r2, c2) - 1; /// as I am keeping dist[source] = 1 instead of 1;

       ans =(ans==-1)?0:ans;

       cout<< "To get from " << node1 << " to " << node2 << " takes " << ans << " knight moves." << endl;


   }


   return 0;

}


