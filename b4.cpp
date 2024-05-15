#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State
{
    int floor; // Tầng hiện tại
    int steps; // Số bước di chuyển

    State(int f, int s) : floor(f), steps(s) {}
};

int minSteps(int n, int k, int m, int s, int f)
{
    if (s > n || f > n)
        return -1; // Không hợp lệ

    // Khởi tạo hàng đợi và đánh dấu đã thăm tầng s
    queue<State> q;
    vector<bool> visited(n + 1, false);
    q.push(State(s, 0));
    visited[s] = true;

    while (!q.empty())
    {
        State curr = q.front();
        q.pop();

        // Kiểm tra điều kiện dừng (đến tầng f)
        if (curr.floor == f)
            return curr.steps;

        // Thử di chuyển lên k tầng
        int nextFloor = curr.floor + k;
        if (nextFloor <= n && !visited[nextFloor])
        {
            visited[nextFloor] = true;
            q.push(State(nextFloor, curr.steps + 1));
        }

        // Thử di chuyển xuống m tầng
        nextFloor = curr.floor - m;
        if (nextFloor > 0 && !visited[nextFloor])
        {
            visited[nextFloor] = true;
            q.push(State(nextFloor, curr.steps + 1));
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main()
{
    int n, k, m, s, f;

    cout << "Nhap so tang: ";
    cin >> n;

    cout << "Nhap so tang di chuyen len va xuong: ";
    cin >> k >> m;

    cout << "Nhap vi tri tang xuat phat va tang dich: ";
    cin >> s >> f;

    int minStepsRequired = minSteps(n, k, m, s, f);
    cout << "So buoc di chuyen it nhat: " << minStepsRequired << endl;

    return 0;
}