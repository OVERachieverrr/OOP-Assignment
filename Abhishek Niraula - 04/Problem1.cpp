/* Assignment
    
    Create a class person with name and date of birth as data members. 
    Ask the user to enter a date of birth and print all persons name with a matched date of birth.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char *name;
    int dob;
    public:
        Person()
        {}
        Person(char *a, int date) 
        {
            name = new char[strlen(a) + 1];
            strcpy(name, a);
            dob = date;
        }
        bool operator == (int date)
        {
            if (dob == date)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void output()
        {
            cout << "Name: " << name << endl << "Date of Birth: " << dob << endl;
        }
        ~Person()
        {
            delete[] name;
        }
};

int main()
{
    int n;
    cout << "Enter the number of person's you want to record: " << endl;
    cin >> n;
    Person *p = new Person[n];
    char name[100];
    int date;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ") Enter name: ";
        cin.ignore();
        cin.getline(name, 100);
        cout << "   Enter " << name << "'s date of birth: ";
        cin >> date;
        p[i] = Person(name, date);
        cout << endl;
    }
    cout << endl << endl;
    cout << "Enter the date of birth you want to filter: ";
    cin >> date;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == date)
        {
            cout << endl << endl;
            p[i].output();
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No matching date.";
    }
    else 
    {
        cout << "Total filter: " << count;
    }
    delete [] p;
    return 0;
}