/*Nhập vào một mảng ba chiều với kích thước n x m x p (số mặt, số dòng, số cột).
Kiểm tra từng phần tử của mảng để xác định xem phần tử đó có phải là số nguyên tố không.
In ra mảng, thay thế các phần tử không phải số nguyên tố bằng ký hiệu "X".
Liệt kê các số không phải số nguyên tố trên từng "mặt" của mảng.*/

#include <bits/stdc++.h>

using namespace std;

int kiem_tra(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return n > 1;
}

void nhap_mang(int mang[][50][50], int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                cout << "Nhap phan tu [" << i << "][" << j << "][" << k << "]: ";
                cin >> mang[i][j][k];
            }
        }
    }
}

void in_mang_nt(int mang[][50][50], int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        cout << "Mat " << i + 1 << ":\n";
        vector<int> mang_ko_nt;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                if (kiem_tra(mang[i][j][k])) {
                    cout << mang[i][j][k] << " ";
                } else {
                    cout << "X ";
                    mang_ko_nt.push_back(mang[i][j][k]);
                }
            }
            cout << endl;
        }
        cout << "Cac so khong phai so nguyen to: ";
        for (int num : mang_ko_nt) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Nhap so mat (n), so dong (m), so cot (p): ";
    int n, m, p;
    cin >> n >> m >> p;

    int mang[50][50][50];
    cout << "Nhap cac phan tu:\n";
    nhap_mang(mang, n, m, p);

    cout << "\nMang so nguyen to va thay X cho phan tu khong phai so nguyen to:\n";
    in_mang_nt(mang, n, m, p);

    return 0;
}
