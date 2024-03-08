#include <iostream>
using namespace std;

enum position
{
    employee,
    manager,
    owner
};

class Person
{
private:
    string name;
    int salary;
    position pos;

public:
    Person(){

    };
    Person(string n, int s, position p)
    {
        name = n;
        salary = s;
        pos = p;
    }
    ~Person()
    {
    }
    void setName(string n)
    {
        name = n;
    }
    void setSalary(int s)
    {
        salary = s;
    }
    void setPos(position p)
    {
        pos = p;
    }
    string getName()
    {
        return name;
    }
    int getSalary()
    {
        return salary;
    }
    position getPos()
    {
        return pos;
    }
};

void sort(Person a[], int n)
{
    Person p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j].getSalary() < a[j + 1].getSalary())
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Person employees[n];
    string name;
    int salary;
    int pos;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> salary;
        cin >> pos;
        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setPos((position)pos);
    }
    sort(employees, n);
    for (int i = 0; i < n; i++)
    {
        cout << employees[i].getName() << " " << employees[i].getPos() << endl;
    }
}