#include <iostream>
#include <fstream>

using namespace std;

bool is_prime(int n)
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

int main()
{
    int n = 0;
    ofstream outFile("prime_numbers.txt");
    outFile << 2 << endl;
    for (int i = 1; i < 1000000; i += 2)
    {
        if (is_prime(i))
        {
            n++;
            outFile << i << endl;
        }
    }
    cout << n << " Prime numbers found " << endl;
    outFile << n << " Prime numbers found";
    outFile.close();

    return 0;
}
