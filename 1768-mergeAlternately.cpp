#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i = 0, j = 0;
        
        while (i < word1.length() && j < word2.length()) {
            s += word1[i++];
            s += word2[j++];
        }
        
       
        while (i < word1.length()) {
            s += word1[i++];
        }
        
        
        while (j < word2.length()) {
            s += word2[j++];
        }
        
        return s;
    }
};

/*original approach*/
/*#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = word1;  // Start with word1
        int minLen = min(word1.length(), word2.length());
        
        // Insert characters from word2 at odd positions
        for (int i = 0; i < minLen; i++) {
            s.insert(2 * i + 1, 1, word2[i]);
        }
        
        // Append remaining characters from word2 if it's longer
        if (word2.length() > word1.length()) {
            s += word2.substr(minLen);
        }
        
        return s;
    }
};*/