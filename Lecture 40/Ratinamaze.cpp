#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> maze)
{
    if ((x < n && y < n) && (x >= 0 && y >= 0) && (maze[x][y] == 1))
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> maze, int n, vector<string> &ans, int x, int y, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    else
    {
        maze[x][y] = 0;
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, maze))
        {
            path.push_back('D');
            solve(maze, n, ans, newx, newy, path);
            path.pop_back();
        }
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, maze))
        {
            path.push_back('L');
            solve(maze, n, ans, newx, newy, path);
            path.pop_back();
        }
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, maze))
        {
            path.push_back('R');
            solve(maze, n, ans, newx, newy, path);
            path.pop_back();
        }
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, maze))
        {
            path.push_back('U');
            solve(maze, n, ans, newx, newy, path);
            path.pop_back();
        }
    }
}
vector<string> findPath(vector<vector<int>> maze, int n)
{
    vector<string> ans;
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
    {
        return ans;
    }
    string path = "";
    solve(maze, n, ans, 0, 0, path);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(maze, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
// TC = 4^(n^2)
// SC = n^2