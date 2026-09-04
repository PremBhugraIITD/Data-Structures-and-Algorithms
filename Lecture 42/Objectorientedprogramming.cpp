#include <iostream>
#include <cstring>
using namespace std;
class Hero
{
public:
    Hero()
    {
        cout << "Constructor called" << endl;
        Name = new char[100];
    }
    // Parameterised Constructor
    Hero(int Health)
    {
        cout << "Parameterised Constructor called" << endl;
        cout << "this: " << this << endl;
        this->Health = Health;
    }
    Hero(int level, string user)
    {
        if (user == "Prem" || user == "Simran" || user == "Gaurav")
        {
            cout << "Parameterised Constructor called" << endl;
            cout << "this: " << this << endl;
            Level = level;
        }
    }
    // User-Defined Copy Constructor
    Hero(Hero &temp)
    {
        cout << "Copy Constructor Called" << endl;
        this->Level = temp.Level;
        this->Health = temp.Health;
        char *ch = new char[strlen(temp.Name) + 1]; // If these two lines are not written then shallow copying occurs.
        strcpy(ch, temp.Name);                      // With these two deep copying occurs.
        this->Name = ch;
    }
    // Data Members or Properties
    char *Name;
    int Health;
    static int timeTocomplete;
    int getLevel()
    { // Getter
        return Level;
    }
    void setLevel(int l, string user)
    { // Setter
        if (user == "Prem" || user == "Gaurav" || user == "Mayur")
        {
            Level = l;
        }
    }
    static void Random(int n)
    {
        timeTocomplete = n;
    }
    void print()
    {
        cout << "Health: " << this->Health << ", " << "Level: " << this->Level << endl;
    }
    ~Hero()
    {
        cout << "Destructor called" << endl;
    }

private:
    int Level;
};
int Hero ::timeTocomplete = 5;
int main()
{
    // Static Allocation
    Hero Prem;
    Prem.Health = 100;
    Prem.Name = "Prem Bhugra";
    cout << sizeof(Prem) << endl;
    cout << Prem.Name << " " << Prem.Health << endl;
    Prem.setLevel(21, "Prem");
    cout << Prem.getLevel() << endl;
    Prem.setLevel(15, "Kunal");
    cout << Prem.getLevel() << endl;
    // Dynamic Allocation
    Hero *Mayur = new Hero;
    Mayur->Health = 90;
    Mayur->setLevel(19, "Mayur");
    cout << (*Mayur).Health << " " << (*Mayur).getLevel() << endl;

    Hero Gaurav(95);
    cout << &Gaurav << endl;
    Gaurav.print();
    Hero Simran(36, "Simran");
    cout << &Simran << endl;
    Simran.print();

    Hero Ritesh(Prem);
    Prem.print();
    Ritesh.print();
    Ritesh.setLevel(25, "Prem");
    Prem.print();
    Ritesh.print();

    Hero Babbar;
    char name[7] = "Babbar";
    Babbar.Name = name;
    Hero Gabbar(Babbar);
    cout << Babbar.Name << " " << Gabbar.Name << endl;
    Babbar.Name[0] = 'G';
    cout << Babbar.Name << " " << Gabbar.Name << endl;
    Babbar = Gabbar; // Use of Copy Assignment Operator
    cout << Babbar.Name << " " << Gabbar.Name << endl;

    cout << Hero::timeTocomplete << endl;
    cout << Prem.timeTocomplete << endl;
    Prem.timeTocomplete = 7;
    cout << Prem.timeTocomplete << " " << Hero::timeTocomplete << endl;
    Hero *Sagar = new Hero;
    cout << Sagar->timeTocomplete << endl;
    Sagar->Random(10);
    cout << Sagar->timeTocomplete << " " << Prem.timeTocomplete << " " << Hero::timeTocomplete << endl;
    // Destructor automatically called for Prem, Gaurav, Simran, Ritesh, Gabbar and Babbar because they are Statically Allocated.
    delete Mayur;
    delete Sagar;
}