#include <iostream>
using namespace std;

class Number
{
private:
    int num;
    bool prime;

public:
    Number(int n, bool p)
    {
        num = n;
        prime = p;
    }
    ~Number()
    {
    }
    void setNum(int n)
    {
        num = n;
    }
    void setPrime(bool p)
    {
        prime = p;
    }
    int getNum()
    {
        return num;
    }
    bool getPrime()
    {
        return prime;
    }
    void printNum()
    {
        cout << num << endl;
    }
    void printPrime()
    {
        if (prime)
        {
            cout << num << " is prime " << endl;
        }
        else
        {
            cout << num << " is not prime " << endl;
        }
    }
};

bool is_prime(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int n;
    cin >> n;
    Number broj(n, is_prime(n));
    broj.printPrime();
}