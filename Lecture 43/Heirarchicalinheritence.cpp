#include <iostream>
using namespace std;
class Human
{
public:
    int Age;
    string Name;

private:
    int Password;

protected:
    int Aadhar_num;
};
class Male : public Human
{
public:
    int Height;
    void set_Aadhar_num(int aadhar_num)
    {
        Aadhar_num = aadhar_num;
    }
    void print()
    {
        cout << "Name: " << this->Name << ", " << "Age: " << Age << ", " << "Height: " << this->Height << ", " << "Aadhar Number: " << this->Aadhar_num << endl;
    }
};
class Female : protected Human
{
public:
    int Weight;
    void setAge(int Age)
    {
        this->Age = Age;
    }
    void print()
    {
        cout << "Name: " << this->Name << ", " << "Age: " << Age << ", " << "Weight: " << this->Weight << endl;
    }
};
int main()
{
    Male Prem;
    Prem.Age = 19;
    Prem.Name = "Prem Bhugra";
    Prem.Height = 178;
    Prem.set_Aadhar_num(123456);
    Prem.print();
    // cout<<Prem.Password<<endl; Cannot be accessed becaused Password is a private member and private members cannot be inherited
    Female Simran;
    // Simran.Age = 18; Cannot be accessed because Age is inherited protectedly by Female class
    Simran.Weight = 54;
    Simran.setAge(18);
    Simran.print();
}