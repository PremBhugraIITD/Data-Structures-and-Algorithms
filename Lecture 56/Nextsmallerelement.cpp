#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> NextSmallerElement(int arr[], int size)
{
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);
    for (int i = size - 1; i >= 0; i--)
    {
        int element = arr[i];
        while (st.top() >= element)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(element);
    }
    return ans;
}
// TC=O(n)
// SC=O(n)
int main()
{
    int nums[6] = {4, 1, 9, 2, 1, 6};
    vector<int> ans = NextSmallerElement(nums, 6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}