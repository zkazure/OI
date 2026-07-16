// ===== crazy solution =====
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;


int main() {
  int m[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int l, r;
  cin >> l >> r;

  int count = 0;

  for (int i=1; i<=12; i++) {
    for (int j=1; j<=m[i]; j++) {
      int now = (j%10*1000 + j/10*100 + i%10*10 + i/10)*10000 + i*100+j;
      if (now <= r && now >= l) {
        count ++;
      }
    }
  }

  printf("%d", count);

  return 0;
}


// ===== my solution ====
#include <bits/stdc++.h>
using namespace std;

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_lunar(int& y) {
  return ( (y%4==0 && y%100!=0) || y%400==0) ? 1: 0;
}

void date_step (int& y, int& m, int& d) {
  int max_day = 0;
  if (m == 2) {
    if (is_lunar(y)) {
      max_day = 29;
    } else {
      max_day = 28;
    }
  } else {
    max_day = md[m];
  }

  d++;
  if(d>max_day) {
    d = 1;
    m++;
  }

  if (m>12) {
    m=1;
    y++;
  }
}

int reverse(int y) {
  int tmp = 0;
  while(y) {
    tmp = tmp*10 + y%10;
    y/=10;
  }

  return tmp;
}

int main() {
  int y1, m1, d1;
  int y2, m2, d2;
  scanf("%4d%2d%2d", &y1, &m1, &d1);
  scanf("%4d%2d%2d", &y2, &m2, &d2);

  int count = 0;

  while (1) {
    int date = m1*100+d1;
    if(reverse(y1) == date)
      count++;
    
    if (  d1 == d2 && m1==m2 && y1==y2 )  
      break;
    
    date_step(y1, m1, d1);
  }

  printf("%d", count);
}
