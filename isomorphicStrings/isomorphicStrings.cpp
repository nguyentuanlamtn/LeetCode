#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//bool isIsomorphic(string s, string t) {
//    if (s.length() != t.length()) return false;
//
//    unordered_map<char, char> mapS2T;
//    unordered_map<char, char> mapT2S;
//
//    for (int i = 0; i < s.length(); i++) {
//        char c1 = s[i], c2 = t[i];
//
//        // Kiểm tra ánh xạ từ s -> t
//        if (mapS2T.count(c1) && mapS2T[c1] != c2) {
//            return false;
//        }
//
//        // Kiểm tra ánh xạ từ t -> s
//        if (mapT2S.count(c2) && mapT2S[c2] != c1) {
//            return false;
//        }
//
//        // Tạo ánh xạ
//        mapS2T[c1] = c2;
//        mapT2S[c2] = c1;
//    }
//
//    return true;
//}

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> map_s(256, 0), map_t(256, 0);

    for (int i = 0; i < s.length(); ++i) {
        if (map_s[s[i]] != map_t[t[i]]) {
            return false;
        }
        map_s[s[i]] = i + 1;
        map_t[t[i]] = i + 1;
    }

    return true;
}

int main() {
    string s = "egg", t = "add";
    cout << "Are \"" << s << "\" and \"" << t << "\" isomorphic? "
        << (isIsomorphic(s, t) ? "Yes" : "No") << endl;

    s = "foo", t = "bar";
    cout << "Are \"" << s << "\" and \"" << t << "\" isomorphic? "
        << (isIsomorphic(s, t) ? "Yes" : "No") << endl;

    s = "paper", t = "title";
    cout << "Are \"" << s << "\" and \"" << t << "\" isomorphic? "
        << (isIsomorphic(s, t) ? "Yes" : "No") << endl;

    return 0;
}
