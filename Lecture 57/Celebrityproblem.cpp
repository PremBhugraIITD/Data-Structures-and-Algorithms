#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Approach 1
int celebrity(vector<vector<int>> M, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool celeb_row = true;
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                celeb_row = false;
                break;
            }
        }
        if (celeb_row == false)
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (i != j && M[j][i] == 0)
            {
                celeb_row = false;
                break;
            }
        }
        if (celeb_row == false)
        {
            continue;
        }
        return i;
    }
    return -1;
}
// TC=O(n^2)
// SC=O(1)
// Approach 2
bool knows(vector<vector<int>> nums, int a, int b)
{
    if (nums[a][b] == 1)
    {
        return true;
    }
    return false;
}
int celebrity2(vector<vector<int>> M, int n)
{
    stack<int> st;
    // Storing each person's number in stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    // Find out the number for potential rows and columns
    while (st.size() > 1)
    {
        int top1 = st.top();
        st.pop();
        int top2 = st.top();
        st.pop();
        if (knows(M, top1, top2))
        {
            st.push(top2);
        }
        else
        {
            st.push(top1);
        }
    }
    int potential_celeb = st.top();
    // Checking whether the potential celebrity (or column) is the celebrity or not
    for (int i = 0; i < n; i++)
    {
        if (M[potential_celeb][i] == 1)
        {
            return -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != potential_celeb && M[i][potential_celeb] == 0)
        {
            return -1;
        }
    }
    return potential_celeb;
}
// TC=O(n)
// SC=O(n)
int main()
{
    vector<vector<int>> people;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    row1.push_back(0);
    row1.push_back(1);
    row1.push_back(0);
    row2.push_back(0);
    row2.push_back(0);
    row2.push_back(0);
    row3.push_back(0);
    row3.push_back(1);
    row3.push_back(0);
    people.push_back(row1);
    people.push_back(row2);
    people.push_back(row3);
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < people[0].size(); j++)
        {
            cout << people[i][j] << " ";
        }
        cout << endl;
    }
    cout << celebrity(people, 3) << endl;
    cout << celebrity2(people, 3) << endl;
}