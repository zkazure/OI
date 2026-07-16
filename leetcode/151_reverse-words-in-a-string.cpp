#include <algorithm>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    void removeExtraSpace(string& s) {
        int slow=0;
        for (int fast=0; fast<s.size(); fast++) {
            if (s[fast]!=' ') {
                if (slow!=0)
                    s[slow++] = ' ';
                while (fast<s.size() && s[fast]!=' ')
                    s[slow++] = s[fast++];
            }
        }
        s.resize(slow);
    }
    void reverse(string& s, int start, int end) {
        while (start<end)
            swap(s[start++], s[end--]);
    }
    
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size()-1);
        int slow=0, fast=0;
        while (fast<s.size()) {
            if (s[fast]==' ') {
                reverse(s, slow, fast-1);
                slow = fast+1;
            }
            
            fast++;
        }
        reverse(s, slow, s.size()-1);
        
        return s;
    }
};


// code_end

