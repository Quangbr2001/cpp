
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
        int n;
     cout << "Nhap so luong phan tu cua mang: ";
     cin >> n;
     if (n < 2 || n > 100) {
         cout << "So luong phan tu cua mang phai nam trong khoang tu 2 den 100." << endl;
         return 0;
     }

     vector<int> arr(n);
     cout << "Nhap cac phan tu cua mang: ";
     for (int i = 0; i < n; i++) {
         cin >> arr[i];
     }

     // Sap xep mang theo thu tu giam dan
     sort(arr.begin(), arr.end(), greater<int>());

     // In ra so lon nhat va so lon thu hai
     cout << "So lon nhat: " << arr[0] << endl;
     cout << "So lon thu hai: " << arr[1] << endl;

     return 0;
 }