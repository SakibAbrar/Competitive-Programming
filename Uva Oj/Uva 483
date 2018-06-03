#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

stack<char> word;

int main(){

    //freopen("output.txt", "w", stdout);

    string str;
    while(!getline(cin, str).eof()){
        for(int i = 0; i<str.size(); i++){
            if(str[i]!=' ')
                word.push(str[i]);

            else if( str[i]==' ' && !word.empty()){
                while(!word.empty()){
                    cout << word.top();
                    word.pop();
                }

                cout << " ";
            }

            else
                cout << " ";


        }
        while(!word.empty()){
            cout << word.top();
            word.pop();
        }

        cout << endl;
        str.clear();
    }
}
