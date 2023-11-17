#include <iostream>
#include <iomanip>

void show_balance(double balance);
double deposit_money();
double withdraw_money(double balance);

int main()
{

    double balance = 0;
    int choice = 0;

    do
    {

        std::cout << "************************************\n";
        std::cout << "           Pick Choice: \n";
        std::cout << "************************************\n";

        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            show_balance(balance);
            break;

        case 2:
            balance += deposit_money();
            show_balance(balance);
            break;

        case 3:
            balance -= withdraw_money(balance);
            show_balance(balance);
            break;

        case 4:
            std::cout << "Thank you for visiting\n";
            break;
        default:
            std::cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;

}


void show_balance(double balance)
{
    std::cout << "Your Balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}


double deposit_money()
{
    double amount = 0;

    std::cout << "\nEnter Amount you want to deposit: ";
    std::cin >> amount;

    if (amount > 0)
    {
        return amount;
    }
    else
    {
        std::cout << "Not Valid Amount\n";
        return 0;
    }
}


double withdraw_money(double balance)
{

    double amount = 0;

    std::cout << "Enter Amount: ";
    std::cin >> amount;

    if (amount > balance)
    {
        std::cout << "Not Enough Money!!\n";
        return 0;
    }

    return amount;
}

