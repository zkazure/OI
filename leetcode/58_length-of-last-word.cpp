#include <iostream>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length() -1;
        int count = 0;
        
        while (index >= 0 && s[index] == ' ') {
            index --;
        }
        
        while (index >= 0 && s[index] != ' ') {
            count++;
            index--;
        }
        
        return count;
    }
};

// code_end

