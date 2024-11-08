#include<iostream>
using namespace std;
int a = 20;
int pp()
{
    return a;
}
int main()
{
    // enum color {red, green, blue} c;
    enum color {red, green=5, blue} c;
    c = blue;
    // cout << c << endl;
    int a = 10;
    cout << a << endl;
    cout << pp() << endl;
    return 0;
}