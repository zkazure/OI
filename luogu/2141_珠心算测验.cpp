// 有序数组可以使用双指针
// 标志变量需要记得初始化
// 有时候需要手动演算就要手动演算

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[101];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      if (a[i]>a[j]) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }

  int count = 0;
  int left = 0, right = 0;
  for (int i=2; i<n; i++) {
    left = 0, right = i-1;
    int sum;
    while (left<right) {
      sum = a[left] + a[right];
      if (sum==a[i]) {
        count ++;
        break;
      } else if (sum < a[i]) {
        left++;
      } else {
        right--;
      }
    }
  }

  printf("%d", count);

  return 0;
}
