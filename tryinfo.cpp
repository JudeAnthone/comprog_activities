//main work

#include <iostream>
using namespace std;

int User_record = 0;
const int Record = 61;
string storage_data[Record][7];

void Show_Menu();
void Add_Data();
void View_Data();
string Generate_ID();

int main()
{

    int choice;

    do
    {
        Show_Menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            Add_Data();
            break;

        case 2:
            View_Data();
            break;

        case 3:
            int exit;
            cout << "Are You sure you want to Exit?\n";
            cout << "1.YES\n";
            cout << "2.NO\n";
            cin >> exit;

            if (exit == 1)
            {
                cout << "Thank you! Rest assured that your information is well kept" << '\n';
                return 0;
            }
            else if (exit == 2)
            {
                choice = 1;
            }
            break;

        default:
            cout << "ERROR: INVALID CHOICE\n";
            break;
        }
    } while (choice != 3);

    return 0;
}

void Show_Menu()
{

    cout << '\n';
    cout << "        INFORMATION SYSTEM" << '\n';
    cout << '\n';

    cout << "************************************\n";
    cout << "            SELECT MENU \n";
    cout << "************************************\n";

    cout << "1. Add Data\n";
    cout << "2. View Data\n";
    cout << "3. Exit\n";
}

void Add_Data()
{

    string name, gender, contact, address, email;
    int age;

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Gender: ";
    cin.ignore();
    cin >> gender;

    cout << "Enter Contact Number: ";
    cin.ignore();
    getline(cin, contact);

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Email Address: ";
    getline(cin, email);

    string ID = Generate_ID(); // dito nag gegenerate ID ni user
    storage_data[User_record][0] = name;
    storage_data[User_record][1] = to_string(age);
    storage_data[User_record][2] = gender;
    storage_data[User_record][3] = contact;
    storage_data[User_record][4] = address;
    storage_data[User_record][5] = email;
    storage_data[User_record][6] = ID;
    User_record++;

    cout << "DATA ADDED! Your ID is: " << ID << '\n';
}

string Generate_ID()
{

    return to_string(2301 + User_record);
}

void View_Data()
{

    if (User_record == 0)
    {
        cout << '\n';
        cout << "ERROR: Input your Data first!";
        cout << '\n';
    }
    else
    {

        string ID;
        cout << "Enter your ID: ";
        cin >> ID;

        bool user_ID = false;
        for (int i = 0; i < User_record; i++)
        {

            if (storage_data[i][6] == ID)
            {
                user_ID = true;
                //         0     1       2        3        4         5     6
                cout << "Name / Age / Gender / Number / Address / Email / ID\n";
                for (int j = 0; j < 7; j++)
                {
                    cout << storage_data[i][j] << " / ";
                }
                cout << '\n';
                break;
            }
        }

        if (!user_ID)
        {
            cout << "ERROR: User ID " << ID << " not Found. \n";
        }
    }
}