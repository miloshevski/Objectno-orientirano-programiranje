#include <iostream>
#include <cstring>
using namespace std;

class SpaceObject
{
private:
    char name[100];
    char type[100];
    int distanceFromEarth;

public:
    SpaceObject() {}
    SpaceObject(char n[], char t[], int d)
    {
        strcpy(name, n);
        strcpy(type, t);
        distanceFromEarth = d;
    }
    void print()
    {
        cout << name << " " << type << "-" << distanceFromEarth << " light years away from Earth" << endl;
    }
    int getDistance()
    {
        return distanceFromEarth;
    }
    string getName()
    {
        return name;
    }
};

class Alien
{
private:
    char name[100];
    int age;
    char homePlanet[100];
    int numObj;
    SpaceObject spaceObject[100];

public:
    Alien() {}
    Alien(char n[], int a, char h[], int nb, SpaceObject object[])
    {
        strcpy(name, n);
        age = a;
        strcpy(homePlanet, h);
        numObj = nb;
        for (int i = 0; i < nb; ++i)
        {
            spaceObject[i] = object[i];
        }
    }

    SpaceObject getObjectClosestToEarth()
    {
        int index = 0;
        for (int i = 1; i < numObj; i++)
        {
            if (spaceObject[i].getDistance() < spaceObject[index].getDistance())
            {
                index = i;
            }
        }
        return spaceObject[index];
    }

    void print()
    {
        cout << "Alien name: " << name << endl;
        cout << "Alien age: " << age << endl;
        cout << "Alien home planet: " << homePlanet << endl;
        cout << "Favourite space object closest to earth: ";
        getObjectClosestToEarth().print();
    }
};

int main()
{
    char name[100], homePlanet[100];
    int age, numObj;
    cin >> name >> age >> homePlanet >> numObj;
    // Testing default constructor for SpaceObject
    SpaceObject spaceObjects[numObj];
    for (int i = 0; i < numObj; i++)
    {
        char spaceObjectName[100], spaceObjectType[100];
        int distanceFromEarth;
        cin >> spaceObjectName >> spaceObjectType >> distanceFromEarth;
        // Testing constructor with arguments for SpaceObject
        spaceObjects[i] = SpaceObject(spaceObjectName, spaceObjectType, distanceFromEarth);
    }
    // Testing default constructor for Alien
    Alien alien;
    // Testing constructor with arguments for Alien and copy constructor for Alien
    alien = Alien(name, age, homePlanet, numObj, spaceObjects);
    Alien alien2 = Alien(alien);

    alien2.print();
    return 0;
}