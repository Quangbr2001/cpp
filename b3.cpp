#include <iostream>
#include <stack>
#include <string>

 using namespace std;

 string removeConsecutiveDuplicates(string str) {
     stack<char> st;
     string result = "";

     // Duyệt qua từng ký tự trong chuỗi
     for (char ch : str) {
         // Nếu stack rỗng hoặc ký tự hiện tại khác với ký tự ở đỉnh stack
         if (st.empty() || ch != st.top()) {
             // Đẩy ký tự vào stack
             st.push(ch);
         } else {
             // Nếu ký tự hiện tại trùng với ký tự ở đỉnh stack
             // Loại bỏ ký tự ở đỉnh stack
             st.pop();
         }
     }

     // Xây dựng chuỗi kết quả từ các ký tự còn lại trong stack
     while (!st.empty()) {
         result = st.top() + result;
         st.pop();
     }

     return result;
 }

 int main() {
     string str;
     cout << "Nhap chuoi: ";
    getline(cin, str);

     string result = removeConsecutiveDuplicates(str);
     cout << "Chuoi sau khi loai bo ky tu lap: " << result << endl;

     return 0;
 }