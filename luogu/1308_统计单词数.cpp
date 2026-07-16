#include <bits/stdc++.h>
using namespace std;

void lower_format(string& s) {
  for (int i=0; i<(int)s.size(); i++) {
    if (s[i] <= 'Z' && s[i] >= 'A') {
      s[i] = s[i] - 'A' + 'a';
      // s[i] += 32;
    }
  }
  s = ' ' +s+ ' ';
  // Here is the most important
  // format the string, so that you can just use one pointer.
}

int solution() {
  string w, s;
  getline(cin, w);
  lower_format(w);
  getline(cin, s);
  lower_format(s);

  int count=0;
  // int position=s.size();
  int position=0;
  for (int i=0; i<(int)s.size(); i++) {
    if (w == s.substr(i, w.size())) {
      if (!count) {
        position = i;
      }
      count++;
      // position = min(i, position);
    }
  }

  if (count) {
    printf("%d %d", count, position);
  } else {
    printf("-1");
  }

  return 0;
}

// ===== my solution =====
#include <iostream>
#include <string>
using namespace std;

void lower_case (char &c) {
  if (c <= 'Z' &&c >= 'A') {
    c = c- 'A'+'a';
  }
}

int main() {
  // printf("%d", '\0');
  string w, s;
  getline(cin, w);
  getline(cin, s);

  // string test = "gooddfaf";
  // int count = sizeof(test)/8;
  // printf("%d", count);

  int l = w.size();
  for (int i=0; i<l; i++) {
    lower_case(w[i]);
  }
  
  char* left=&s[0];
  char* right = left;
  
  bool in_word = false;
  int count = 0;
  int position = 0;
  int first = position;
  while (*right) {
    bool flag = *right==' ';
    
    if (in_word && flag) {
      int tmp = right - left;
      // compare
      if (tmp==l) {
        bool eq = true;
        for (int i=0;left<right; left++,i++) {
          lower_case(*left);
          if (w[i]!=*left) {
            eq = false;
          }
        }
        
        if (eq) {
          if (!count) {
            first = position-l;
          }
          count++;
        }
      }
      in_word = false;
    } else if (!in_word && !flag) {
      left = right;
      in_word = true;
    }

    right++;
    position++;
  }

  int tmp = right - left;
  // compare
  if (tmp==l) {
    bool eq = true;
    for (int i=0;left<right; left++,i++) {
      lower_case(*left);
      if (w[i]!=*left) {
        eq = false;
      }
    }
    if (eq) {
      if (!count) {
        first = position-l;
      }
      count++;
    }
  }

  if (count) {
    printf("%d %d", count, first);
  } else {
    printf("-1");
  }

  return 0;
}
