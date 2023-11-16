// Jude Anthone R. Duarte     BSCS - 1A  
#include <iostream>
using namespace std;

int main()
{

    int s = 1;
    int e = 5;
    int power = 3;

    int mul = 0;
    int summation = 0;

    cout << '\n';
    cout << "Terms: ";
    for (int i = s; i <= e; i++)
    { 
         mul = s;

        for (int j = 1; j <= power; j++)
        {
            mul *= i;
        }

        summation += mul;
        cout << mul;

        if (i < e)
        {
            cout << " + ";
        }

        if (summation > 225) // 225 is the last term kaya naka-set po is 225
        {
            break; // program will break if the value reaches 225
        }
    }
        cout << '\n' << summation << '\n';
         cout << '\n';
    cout << '\n';

    return 0;
}


