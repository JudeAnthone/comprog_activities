#include <iostream>
using namespace std;

void operations(int num_1, int num_2, char symbol);

int main()
{

    int num_1, num_2;
    char symbol;

    cout << "\n";
    cout << "************* CALCU DE CS-1A *************\n";
    cout << "\n";

    cout << "Select Operator: ( + - * /) ";
    cin >> symbol;

    cout << "Enter First Number: " << '\n';
    cin.ignore();
    cin >> num_1;

    cout << "Enter Second Number: " << '\n';
    cin.ignore();
    cin >> num_2;

    operations(num_1, num_2, symbol);

    return 0;
}

void operations(int num_1, int num_2, char symbol)
{

    double result;

    switch (symbol)
    {

    case '+':
        result = num_1 + num_2;
        cout << "Result: " << result;
        break;

    case '-':
        result = num_1 - num_2;
        cout << "Result: " << result;
        break;

    case '*':
        result = num_1 * num_2;
        cout << "Result: " << result;
        break;

    case '/':

        if (num_2 != 0)
        {
            result = static_cast<double>(num_1) / num_2;
            cout << "Result: " << result;
        }

        else
        {
            cout << "ERROR: 0 is not Divisible" << '\n';
        }
        break;

    default:

        cout << "ERROR: INVALID OPERATOR";
    }

    cout << "\n******************************************";
}
