#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	getc(stdin);

	while (n--) {

		stack<char> stchar;

		char s[140];

		gets(s);

		for (int i = 0; s[i]; i++) {

			if (s[i] == '(' || s[i] == '[') {

				stchar.push(s[i]);

			} else if (s[i] == ')') {

				if (stchar.empty() || stchar.top() != '('){

					stchar.push('a');

					break;

				}

				stchar.pop();

			} else if (s[i] == ']') {

				if (stchar.empty() || stchar.top() != '['){

					stchar.push('a');

					break;

				}

				stchar.pop();

			}

		}

		if(stchar.empty())
            cout << "Yes" << endl;

		else
            cout << "No" << endl;

	}

	return 0;
}
