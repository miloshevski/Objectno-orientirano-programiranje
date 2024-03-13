#include <iostream>
using namespace std;

struct Engine
{
    int hp;
    int torq;
};
struct Car
{
    char name[20];
    int year;
    Engine engine;
    void input()
    {
        cin >> name;
        cin >> year;
        cin >> engine.hp;
        cin >> engine.torq;
    }
};

void printCars(Car avto[], int n)
{
    if (avto[n - 1].engine.torq > avto[n - 2].engine.torq)
    {
        cout << "Manufacturer: " << avto[n - 1].name << endl;
        cout << "Horsepower: " << avto[n - 1].engine.hp << endl;
        cout << "Torque: " << avto[n - 1].engine.torq << endl;
    }
    else
    {
        cout << "Manufacturer: " << avto[n - 2].name << endl;
        cout << "Horsepower: " << avto[n - 2].engine.hp << endl;
        cout << "Torque: " << avto[n - 2].engine.torq << endl;
    }
}

void sort(Car avto[], int n)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (avto[j].engine.hp < avto[j + 1].engine.hp)
            {
                swap(avto[j], avto[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    Car koli[n];
    for (int i = 0; i < n; i++)
    {
        koli[i].input();
    }
    sort(koli, n);
    printCars(koli, n);
}