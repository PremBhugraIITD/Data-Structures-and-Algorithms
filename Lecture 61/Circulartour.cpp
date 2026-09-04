#include <iostream>
#include <vector>
using namespace std;
int PetrolPump(vector<int> capacity, vector<int> separation)
{
    int petrol, distance, balance, start, deficit;
    // balance is the extra petrol left with us
    deficit = 0;
    balance = 0;
    start = 0;
    for (int i = 0; i < capacity.size(); i++)
    {
        petrol = capacity[i];
        distance = separation[i];
        balance += petrol - distance;
        if (balance < 0)
        {
            deficit += balance;
            balance = 0;
            start = i + 1;
        }
    }
    // deficit is a negative quantity
    if (deficit + balance >= 0)
    {
        return start;
    }
    return -1;
}
int main()
{
    vector<int> p;
    p.push_back(4);
    p.push_back(6);
    p.push_back(7);
    p.push_back(4);
    vector<int> d;
    d.push_back(6);
    d.push_back(5);
    d.push_back(3);
    d.push_back(5);
    cout << PetrolPump(p, d) << endl;
}