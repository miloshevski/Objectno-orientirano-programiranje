#include <iostream>
using namespace std;

struct Student
{
    string ime;
    string prezime;
    int indeks;
    int poeni;
};

void read(Student &s)
{
    cin >> s.ime;
    cin >> s.prezime;
    cin >> s.indeks;
    cin >> s.poeni;
}

void print(Student s)
{
    cout << s.ime << " ";
    cout << s.prezime << " ";
    cout << s.indeks << " ";
    cout << s.poeni << endl;
}
void sort(Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (s[j].poeni < s[j + 1].poeni)
            {
                swap(s[j], s[j + 1]);
            }
        }
    }
}
int main()
{
    Student studenti[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        read(studenti[i]);
    }
    sort(studenti, n);
    for (int i = 0; i < n; i++)
    {
        print(studenti[i]);
    }
}