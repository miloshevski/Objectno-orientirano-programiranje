#include <iostream>
using namespace std;

struct Course
{
    string name;
    int kod;
    int brojstudenti = 0;
};

struct Student
{
    string name;
    int indeks;
    int kursevi;
    int kodovi[10];
};

int get_most_popular_course(int kod[], int arr[], int n)
{
    int maks = arr[0];
    int naj;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maks)
        {
            maks = arr[i];
            naj = kod[i];
        }
    }
    return naj;
}

int main()
{
    int s, k;
    cin >> s >> k;
    int kod[k];
    int arr[k] = {0};
    Student student[s];
    Course kurs[k];
    for (int i = 0; i < k; i++)
    {
        cin >> kurs[i].name;
        cin >> kurs[i].kod;
        kod[i] = kurs[i].kod;
    }
    for (int i = 0; i < s; i++)
    {
        cin >> student[i].name;
        cin >> student[i].indeks;
        cin >> student[i].kursevi;
        for (int j = 0; j < student[i].kursevi; j++)
        {
            cin >> student[i].kodovi[j];
            for (int x = 0; x < k; x++)
            {
                if (kurs[x].kod == student[i].kodovi[j])
                {
                    arr[x]++;
                }
            }
        }
    }
    int naj = get_most_popular_course(kod, arr, k);
    for (int i = 0; i < k; i++)
    {
        if (kurs[i].kod == naj)
        {
            cout << "Najpopularen kurs e " << kurs[i].name;
            break;
        }
    }
}