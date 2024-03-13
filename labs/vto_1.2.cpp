#include <iostream>
using namespace std;

struct InvoiceItem
{
    char id[10];
    int kolicina;
    int cena;
};

struct Invoice
{
    char id[10];
    int br_stavki;
    InvoiceItem stavka[20];
};

struct Client
{
    char name[100];
    int br_fakturi;
    Invoice faktura[20];
};

void bestClient(Client klienti[], int n)
{
    float sum[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < klienti[i].br_fakturi; j++)
        {
            float tmp = 0;
            for (int k = 0; k < klienti[i].faktura[j].br_stavki; k++)
            {
                tmp += klienti[i].faktura[j].stavka[k].cena;
            }
            tmp *= 1.18;
            sum[i] = tmp;
        }
    }
    int maks = sum[0];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum[i] > maks)
        {
            maks = sum[i];
            index = i;
        }
    }
    cout << klienti[index].name;
}

int main()
{
    int n;
    cin >> n;
    Client klient[n];
    for (int i = 0; i < n; i++)
    {
        cin >> klient[i].name;
        cin >> klient[i].br_fakturi;
        for (int j = 0; j < klient[i].br_fakturi; j++)
        {
            cin >> klient[i].faktura[j].id;
            cin >> klient[i].faktura[j].br_stavki;
            for (int k = 0; k < klient[i].faktura[j].br_stavki; k++)
            {
                cin >> klient[i].faktura[j].stavka[k].id;
                cin >> klient[i].faktura[j].stavka[k].cena;
            }
        }
    }
    bestClient(klient, n);
}