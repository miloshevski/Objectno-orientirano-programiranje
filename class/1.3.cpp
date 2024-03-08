#include <iostream>
#include <cstring>
using namespace std;

class Email
{
private:
    string to, from, subject, body;

public:
    Email(string t, string f, string s, string b)
    {
        to = t, from = f, subject = s, body = b;
    }
    ~Email()
    {
    }
    void setTo(string t)
    {
        to = t;
    }
    void setFrom(string f)
    {
        from = f;
    }
    void setSubject(string s)
    {
        subject = s;
    }
    void setBody(string b)
    {
        body = b;
    }
    string getTo()
    {
        return to;
    }
    string getFrom()
    {
        return from;
    }
    string getSubject()
    {
        return subject;
    }
    string getBody()
    {
        return body;
    }
    void print()
    {
        cout << "To: " << to << endl;
        cout << "From: " << from << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }
};

bool checkTo(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '@')
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int main()
{
    string to, from, subject, body;
    cout << "To: ";
    cin >> to;
    if (checkTo(to))
    {
        cout << "From: ";
        cin >> from;
        cout << "Subject: ";
        cin >> subject;
        cout << "Body:" << endl;
        cin.ignore();
        getline(cin, body);
        Email poraka(to, from, subject, body);
        poraka.print();
    }
    else
    {
        cout << "Invalid email adress";
    }
}