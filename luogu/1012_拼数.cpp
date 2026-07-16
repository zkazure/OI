// ===== crazy solution =====
#include <bits/stdc++.h>
using namespace std;

bool compare (string& a, string& b) {
  return (a+b < b+a);
}

int main() {
  int n;
  cin >> n;
  string a[n];  
  for (int i=0; i<n; i++)
    cin >> a[i];

  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      bool test = compare(a[i], a[j]);
      if (test) {
        string tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }

  for (int i=0; i<n; i++) {
    cout << a[i];
  }

  return 0;
}




// // ==== my solution ======
// #include <bits/stdc++.h>
// using namespace std;

// void compare_str(string& a, string& b) {
//   if (a < b) {
//     string tmp = a;
//     a = b;
//     b = tmp;
//   }
// }

// int main() {
//   int n;
//   cin >> n;

//   string a[n];
//   for (int i=0; i<n; i++) {
//     cin >> a[i];
//   }

//   int size_min, size_max;
//   for (int i=0; i<n-1; i++) {
//     for (int j=i+1; j<n; j++) {
//       size_min = a[i].size();
//       size_max = a[j].size();
//       if (size_min==size_max) {
//         compare_str(a[i], a[j]);
//       } else {
//         if(size_min>size_max) {
//           int tmp = size_min;
//           size_min = size_max;
//           size_max = tmp; // i is longer
 
//           if (a[i].substr(0, size_min) == a[j]) {
//             // compare
//             if (a[i].substr(size_min, size_max-size_min) < a[j]) {
//               string tmp = a[i];
//               a[i] = a[j];
//               a[j] = tmp;          
//             }
//           } else {
//             compare_str(a[i], a[j]);
//           }
//         } else {
//           if (a[i] == a[j].substr(0, size_min)) {
//             // compare
//             if (a[i] < a[j].substr(size_min, size_max-size_min)) {
//               string tmp = a[i];
//               a[i] = a[j];
//               a[j] = tmp;          
//             } 
//           } else {
//             compare_str(a[i], a[j]);
//           }
//         }          
//       }
        
//     }
//   }
  
  
//   for (int i=0; i<n; i++) {
//     cout << a[i];
//   }
  
//   return 0;
// }
