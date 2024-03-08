#include <iostream>
using namespace std;

struct Person
{
    string ime;
    string prezime;
};

struct President
{
    Person person;
    string title;
};

struct City
{
    string name;
    int population;
};

struct Country
{
    string name;
    President president;
    City capital;
    int population;
};

void readCountry(Country &country)
{
    cin >> country.name;
    cin >> country.president.person.ime;
    cin >> country.president.person.prezime;
    cin >> country.capital.name;
    cin >> country.capital.population;
    cin >> country.population;
};

int max(Country d[], int n)
{
    int max = d[0].population;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (d[i].population > max)
        {
            max = d[i].population;
            index = i;
        }
    }
    return index;
}
int main()
{
    int n;
    cin >> n;
    Country drzava[n];
    for (int i = 0; i < n; i++)
    {
        readCountry(drzava[i]);
    }
    int index = max(drzava, n);
    cout << drzava[index].president.person.ime << endl;
    cout << drzava[index].president.person.prezime;
}