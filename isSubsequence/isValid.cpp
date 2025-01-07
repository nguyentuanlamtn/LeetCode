#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            t.push(s[i]);
        }
        else if (s[i] == ')') {
            if (i == 0 || t.empty() || t.top() != '(') {
                return false;
            }
            t.pop();
        }
        else if (s[i] == ']') {
            if (i == 0 || t.empty() || t.top() != '[') {
                return false;
            }
            t.pop();
        }
        else if (s[i] == '}') {
            if (i == 0 || t.empty() || t.top() != '{') {
                return false;
            }
            t.pop();
        }
    }
    return t.empty();
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        if (isValid(s))
        {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;

        }
    }

    return 0;
}
