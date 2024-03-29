// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

// Below is one possible representation of s1 = "great":

//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".

// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".

// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(s2.size() != n) return false;
        if(n == 0) return true;
        vector<vector<vector<bool> > > table(n, vector<vector<bool> >(n, vector<bool>(n, false)));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(s1[i] == s2[j]) table[i][j][0] = true;
        
        for(int k = 1; k < n; ++k) {
            for(int i = 0; i < n-k; ++i) {
                for(int j = 0; j < n-k; ++j) {
                    for(int l = 0; l < k; ++l) {
                        if((table[i][j][l] && table[i+1+l][j+1+l][k-l-1]) ||
                           (table[i][j+k-l][l] && table[i+1+l][j][k-l-1])) {
                               table[i][j][k] = true;
                               break;
                           }
                    }
                }
            }
        }
        return table[0][0][n-1];
    }
};
