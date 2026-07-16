#include <string>
using namespace std;

// code_start

class Solution {
public:
  
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        
        // how to add two binary strings and return a binary, do not give me the answer, give some indications.
        // for char 1 byte but 4 bits
        // char[i] + char[i] = 0 1 2
        // if 0 1 assign to, if 2 make the next +1
        // now question is where to start: left or right
        // why is important because carry
        // but more important is the length of new string
        // you need to start from right because the string is different length
        // so la and lb both >= 0 or ask ==0

        // what not try to convert to number 
        int sum = str_to_num(la, a) + str_to_num(lb, b);
        
        // now the most important question is I don't know the length of new string. 

    }
    
    int str_to_num (int& len, string str) {
        int sum = 0;
        int step = 0;        
        while (len >= 0) {
            int tmp = str[len];
            
            for (int i=0; i<step; i++) {
                tmp *= 2;
            }
            
            sum += tmp;
            
            step++;
            len--;
        }
        return sum;
    }
    
};

// code_end


