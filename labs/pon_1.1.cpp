#include <iostream>
using namespace std;

struct Transaction
{
    int id;
    int sum;
    int provizija;
    int payment;
    void input()
    {
        cin >> id >> sum >> provizija >> payment;
    }
    float summ()
    {
        return sum + provizija;
    }
};

int main()
{
    int n;
    cin >> n;
    Transaction t[n];
    for (int i = 0; i < n; i++)
    {
        t[i].input();
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i].payment == 1)
        {
            cout << t[i].id << " " << t[i].summ() << endl;
        }
    }
}