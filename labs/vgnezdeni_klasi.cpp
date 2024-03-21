#include <iostream>
#include <cstring>
using namespace std;

class BasketballPlayer
{
private:
    char name[20];
    char surname[20];
    int number;
    int p[3];

public:
    BasketballPlayer() {}
    BasketballPlayer(char n[], char s[], int nn, int pp[])
    {
        strcpy(name, n);
        strcpy(surname, s);
        number = nn;
        for (int i = 0; i < 3; i++)
        {
            p[i] = pp[i];
        }
    }
    float get_avg()
    {
        float avg;
        for (int i = 0; i < 3; i++)
        {
            avg += p[i];
        }
        avg /= 3;
        return avg;
    }
    void print()
    {
        cout << "Player: " << name << " " << surname << " with number: " << number << " has " << get_avg() << " points on average";
    }
};

int main()
{
    char name[20];
    char surname[20];
    int number;
    int p[3];
    cin >> name;
    cin >> surname;
    cin >> number;
    for (int i = 0; i < 3; i++)
    {
        cin >> p[i];
    }
    BasketballPlayer player(name, surname, number, p);
    player.print();
}