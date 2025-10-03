#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int numbers[8] = {3, 2, 6, 1, 9, 4, 23, 0};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (numbers[i] == numbers[j] == numbers[k])
                {
                    continue;
                }
                if (numbers[i] + numbers[j] + numbers[k] == n)
                {
                    cout << "(" << numbers[i] << "," << numbers[j] << "," << numbers[k] << ")" << endl;
                    break;
                }
            }
        }
    }
}