#include <bits/stdc++.h>

void check_num(int* check, int num) {
    for (int i=0; i<3; ++i) {
        int tmp = num%10;
        num /= 10;
        check[tmp]++;
    }

}

int main() {
    for (int num1=192; num1<=333; num1++) {
        int check[10] = {0};
        int num2 = num1*2, num3 = num1*3;
        check_num(check, num1);
        check_num(check, num2);
        check_num(check, num3);

        if (check[0])
            continue;

        bool flag = false;
        for (int i=1; i<10; i++) {
            if (!check[i]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("%d %d %d\n", num1, num2, num3);
    }
    
}
