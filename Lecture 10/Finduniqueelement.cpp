#include <iostream>
using namespace std;
int main()
{
    int numbers[7] = {2, 3, 1, 6, 3, 6, 2};
    for (int i = 0; i < 7; i++)
    {
        int count = 0;
        for (int j = 0; j < 7; j++)
        {
            if (numbers[i] == numbers[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << numbers[i];
        }
    }
}