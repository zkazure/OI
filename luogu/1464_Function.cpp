// ========= crazy solution ==============

#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL w_memory[25][25][25]={0};

LL w_function(LL a, LL b, LL c) {
  if (a<=0 || b<=0 || c<=0)
    return 1;

  if (a>20 || b>20 || c>20)
    return w_function(20, 20, 20);

  if (a<b && b<c) {
    if (!w_memory[a][b][c-1]) {
      w_memory[a][b][c-1] = w_function(a, b, c-1);
    }
    if (!w_memory[a][b-1][c-1]) {
      w_memory[a][b-1][c-1] = w_function(a, b-1, c-1);
    }
    if (!w_memory[a][b-1][c]) {
      w_memory[a][b-1][c] = w_function(a, b-1, c);
    }
    w_memory[a][b][c] = w_memory[a][b][c-1] + w_memory[a][b-1][c-1] - w_memory[a][b-1][c];
  } else {
    if (!w_memory[a-1][b][c]) {
      w_memory[a-1][b][c] = w_function(a-1, b, c);
    }
    if (!w_memory[a-1][b-1][c]) {
      w_memory[a-1][b-1][c] = w_function(a-1, b-1, c);
    }
    if (!w_memory[a-1][b][c-1]) {
      w_memory[a-1][b][c-1] = w_function(a-1, b, c-1);
    }
    if (!w_memory[a-1][b-1][c-1]) {
      w_memory[a-1][b-1][c-1] = w_function(a-1, b-1, c-1);
    }
    w_memory[a][b][c] = w_memory[a-1][b][c] + w_memory[a-1][b-1][c] + w_memory[a-1][b][c-1] - w_memory[a-1][b-1][c-1];
  }

  return w_memory[a][b][c];
}

int main() {
  LL a, b, c;
  do {
    cin >> a >> b >> c;
    if (a==-1 && b==-1 && c==-1)
      break;

    printf("w(%lld, %lld, %lld) ", a, b, c);
    printf("= %lld\n", w_function(a, b, c));
  } while(1);

  return 0;
}


// ============ my solution ===============
// too long and not efficient.

#include <bits/stdc++.h>
using namespace std;

int power2(int& n) {
  int tmp = 1;

  while (n) {
    tmp*=2;
    n--;
  }

  return tmp;
}
int w_function(int a, int b, int c) {

  if (!a || !b || !c)
    return 1;

  if (a<=b || a<=c)
    return power2(a);

  if (b==1 && c==1)
    return a+1;

  return w_function(a-1, b, c) + w_function(a-1, b, c-1) + w_function(a-1, b-1, c) - w_function(a-1, b-1, c-1);  
  // if (!a)
  //   return 1;

  // if (a<b && b<c)
  //   return w_function(a, b, c-1) + w_function(a, b-1, c-1) - w_function(a, b-1, c);

  // return w_function(a-1, b, c) + w_function(a-1, b, c-1) + w_function(a-1, b-1, c) - w_function(a-1, b-1, c-1);
}

int w_initial(int a, int b, int c) {
  if (a<=0 || b<=0 || c<=0)
    return 1;
  if (a>20 || b>20 || c>20) 
    return w_function(20, 20, 20);
  
  return w_function(a, b, c);
}

int main() {
  int a, b, c;
  
  do {
    cin >> a >> b >> c;
    if (a==-1 && b==-1 && c==-1)
      break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, w_initial(a, b, c));
  } while(1);

  return 0;
}
