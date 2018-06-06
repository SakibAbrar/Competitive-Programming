#include <stack>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;


pii matrix[26];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	while(n--){

        char ch;
        cin >> ch;
        int r, c;
        cin >> r >> c;
        matrix[ch-'A'] = make_pair(r, c);

	}

    cin.clear();
    cin.ignore();

    string str;
    
    while(cin >> str){
    
        stack<pii> stk;
        int ans = 0;
        bool ok = true;

        for(int i = 0; i<str.size(); i++){

            pii B;

            if(str[i] == '('){
                ///putting a dummy pair(-1, -1) in the stack to indicate starting parenthesis
                stk.push(make_pair(-1, -1));
                continue;
            }

            else if(str[i] == ')'){
                B = stk.top();
                stk.pop();
                stk.pop();/// removes the dummy starting parenthesis
            }


            ///ei else ta ultimately parenthesis er vetorer 2nd matrix ke rakhbe.
            ///1st one thakbe A te. A na thakle ei notun B push hobe onno checking er pore giye.
            ///thakle notun maan push hobe.
            else
                B = matrix[str[i]-'A'];

            ///eta A ke rakhbe jodi thake. na thakle move on korbe
            if( !stk.empty() && stk.top() != make_pair(-1, -1) ){
                pii A = stk.top();
                stk.pop();

                /// matrix multiplication condition must satisfy
                if ( A.second != B.first ){
                    ok = false;
                    break;
                }

                ans += A.first * A.second * B.second;

                ///adding the matrix after multiplication
                B = make_pair( A.first, B.second );
            }

            ///pushing the B (can be older B or the multiplication result stored in B)
            stk.push(B);
        }

        if(ok)
            cout << ans << endl;

        else
            cout << "error" << endl;

    }

    return 0;

}
