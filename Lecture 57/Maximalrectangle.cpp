#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> PreviousSmallerElement(vector<int> arr)
{ // Gives a vector containing indices of the previous smaller element for each element of nums
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> NextSmallerElement(vector<int> arr)
{                  // Gives a vector containing indices of the next smaller element for each element of nums
    stack<int> st; // This stack contains indices
    st.push(-1);
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop(); // We are popping out the indices of those elements which
        } // are greater than or equal to curr to reach to an index
        ans[i] = st.top(); // corresponding to which the element is smaller than curr
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    vector<int> next = NextSmallerElement(heights);
    vector<int> previous = PreviousSmallerElement(heights);
    int area = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int length = heights[i];
        if (next[i] == -1)
        {
            next[i] = heights.size();
        }
        int width = next[i] - previous[i] - 1;
        int newArea = length * width;
        area = max(area, newArea);
    }
    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> matrix2;
    // Connverting 'char' vector into 'int' vector
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            int number = matrix[i][j] - '0';
            row.push_back(number);
        }
        matrix2.push_back(row);
    }
    int rows = matrix2.size();
    int columns = matrix2[0].size();
    // Calculate area of largest rectangle for 1st row in matrix
    int area = largestRectangleArea(matrix2[0]);
    // Update the next rows
    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix2[i][j] != 0)
            {
                matrix2[i][j] = matrix2[i][j] + matrix2[i - 1][j];
            }
        }
        int newArea = largestRectangleArea(matrix2[i]);
        area = max(area, newArea);
    }
    return area;
}
// TC=O(mn)
// SC=O(m)
int main()
{
    vector<vector<char>> matrix;
    vector<char> row1;
    vector<char> row2;
    vector<char> row3;
    vector<char> row4;
    row1.push_back('1');
    row1.push_back('0');
    row1.push_back('1');
    row1.push_back('0');
    row1.push_back('0');
    row2.push_back('1');
    row2.push_back('0');
    row2.push_back('1');
    row2.push_back('1');
    row2.push_back('1');
    row3.push_back('1');
    row3.push_back('1');
    row3.push_back('1');
    row3.push_back('1');
    row3.push_back('1');
    row4.push_back('1');
    row4.push_back('0');
    row4.push_back('0');
    row4.push_back('1');
    row4.push_back('0');
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << maximalRectangle(matrix) << endl;
}