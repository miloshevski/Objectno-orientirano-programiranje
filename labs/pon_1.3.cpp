#include <iostream>
using namespace std;

struct player
{
    string name;
    int number;
    int goals;
};
struct FootballTeam
{
    string name;
    player p[11];
    int total;
};

void bestTeam(FootballTeam tim)
{
    cout << "Team with the most goals is: " << tim.name << " with " << tim.total << " goals." << endl;
}
int main()
{
    int n;
    cin >> n;
    FootballTeam tim[n];
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        cin >> tim[i].name;
        for (int j = 0; j < 11; j++)
        {
            cin >> tim[i].p[j].name;
            cin >> tim[i].p[j].number;
            cin >> tim[i].p[j].goals;
            s += tim[i].p[j].goals;
        }
        tim[i].total = s;
    }
    int maks = tim[0].total;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (tim[i].total > maks)
        {
            maks = tim[i].total;
            index = i;
        }
    }
    bestTeam(tim[index]);
}