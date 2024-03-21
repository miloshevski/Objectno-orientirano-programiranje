#include <iostream>
#include <cstring>
using namespace std;

class Country
{
private:
    char name[100];
    char capital[100];
    float area;
    float population;

public:
    Country() {}
    Country(char n[], char c[], float a, float p)
    {
        strcpy(name, n);
        strcpy(capital, c);
        area = a;
        population = p;
    }
    ~Country() {}
    void setName(char n[])
    {
        strcpy(name, n);
    }
    void setCapital(char c[])
    {
        strcpy(capital, c);
    }
    void setArea(float a)
    {
        area = a;
    }
    void setPopulation(float p)
    {
        population = p;
    }
    string getName()
    {
        return name;
    }
    string getCapital()
    {
        return capital;
    }
    float getArea()
    {
        return area;
    }
    float getPopulation()
    {
        return population;
    }
    void display()
    {
        cout << "Country: " << name << endl;
        cout << "Capital: " << capital << endl;
        cout << "Area: " << area << endl;
        cout << "Population: " << population << endl;
    }
};

void sortCountries(Country *countries, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (countries[j].getArea() > countries[j + 1].getArea())
            {
                Country tmp = countries[j];
                countries[j] = countries[j + 1];
                countries[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Country countries[100];

    char name[100];
    char capital[100];
    double area;
    double population;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> name;
        cin >> capital;
        cin >> area;
        cin >> population;

        // testing constructor with arguments
        countries[i] = Country(name, capital, area, population);
    }

    // testing set methods and display for last element
    cin >> name;
    cin >> capital;
    cin >> area;
    cin >> population;
    countries[n - 1].setName(name);
    countries[n - 1].setCapital(capital);
    countries[n - 1].setArea(area);
    countries[n - 1].setPopulation(population);

    cout << "-->Testing set methods and display()" << endl;
    countries[n - 1].display();
    cout << endl;

    cout << "-->Testing sortCountries()" << endl;
    sortCountries(countries, n);
    for (int i = 0; i < n; i++)
    {
        countries[i].display();
    }
    return 0;
}