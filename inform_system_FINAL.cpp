// FINAL WORK
#include <iostream>

using namespace std;

int User_record = 0;
const int Record = 61;
string storage_data[Record][7];

void Show_Menu();
void View_Data(string ID);
void Add_Data();
void Edit_Data(string ID);
string Generate_ID();

int main()
{
  int choice;
  string ID = storage_data[User_record][6];

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
      View_Data(ID);
      break;

    case 3:
      Edit_Data(ID);
      break;

    case 4:

      int exit;

      cout << "Are you Sure you want to Exit?\n";
      cout << "  1.YES\n  ";
      cout << "  2.NO\n  ";
      cin >> exit;

      if (exit == 1)
      {
        cout << "Thank you! Rest assured that your information is well kept.\n";
        return 0;
      }
      else if (exit == 2)
      {
        choice = 1;
      }
      break;

    default:
      cout << "Error: INVALID CHOICE\n";
      break;
    }

  } while (choice != 4);

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
  cout << "3. Edit Data\n";
  cout << "4. Exit\n";
}

void View_Data(string ID)
{

  if (User_record == 0)
  {
    cout << '\n';
    cout << "ERROR: Input Data First\n";
  }

  else
  {

    string ID;
    cout << "Enter your ID: ";
    cin >> ID;

    bool ID_FOUND = true;

    for (int i = 0; i < User_record; i++)
    {

      if (storage_data[i][6] == ID)
      {
        ID_FOUND = false;
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

    if (ID_FOUND)
    {
      cout << "ERROR: User ID " << ID << " not Found. \n";
    }
  }
}

void Add_Data()
{
  string name, gender, contact, address, email;
  int age;

  cout << "Enter Full Name: ";
  cin.ignore();
  getline(std::cin, name);

  cout << "Enter Age: ";
  cin >> age;
  cin.ignore();

  cout << "Enter Gender: ";
  cin >> gender;

  cout << "Contact Number: ";
  cin.ignore();
  getline(cin, contact);

  cout << "Address: ";
  getline(cin, address);

  cout << "Email Address: ";
  cin >> email;

  string ID = Generate_ID();

  storage_data[User_record][0] = name;
  storage_data[User_record][1] = to_string(age);
  storage_data[User_record][2] = gender;
  storage_data[User_record][3] = contact;
  storage_data[User_record][4] = address;
  storage_data[User_record][5] = email;
  storage_data[User_record][6] = ID;
  User_record++;

  cout << '\n';
  cout << '\n';
  cout << "Data Added Successfully!" << '\n';
  cout << "Your ID is: " << ID << '\n';
  cout << "REMEMBER YOUR ID. THIS WILL SERVE AS YOUR KEY TO VIEW & EDIT YOUR DATA.\n";
  cout << '\n';
  cout << '\n';
}

string Generate_ID()
{
  return to_string(2401 + User_record);
}

void Edit_Data(string ID)
{
    if (User_record == 0)
    {
        cout << "ERROR: Data Points to Edit Cannot Be Found! Input Data First.\n";
    }
    else
    {
        cout << "Enter your ID: ";
        cin >> ID;

        for (int i = 0; i < User_record; i++)
        {

            if (storage_data [i][6] == ID)
            {
                string edit_name, edit_gender, edit_contact, edit_address, edit_email;
                int edit_age;
                int edit_choice;

                    cout << "Which Data Point Would You Want To Edit?\n";
                    cout << "1. Name\n";
                    cout << "2. Age\n";
                    cout << "3. Gender\n";
                    cout << "4. Contact Number\n";
                    cout << "5. Address\n";
                    cout << "6. Email Address\n";

                    cin >> edit_choice;

                    switch (edit_choice)
                        {
                            case 1: 
                                cout << "Enter a New Name: ";
                                cin >> edit_name;
                                cout << '\n';
                                
                                storage_data [i][0] = edit_name;
                                
                                cout << "Your New Name is: " << edit_name << '\n';
                                break;
    
                            case 2:
                                cout << "Enter a New Age: ";
                                cin >> edit_age;
                                cout << '\n';

                                storage_data [i][1] = to_string(edit_age);

                                cout << "Your New Age is: " << edit_age << '\n';
                                break;

                            case 3:
                                cout << "Enter a New Gender: ";
                                cin >> edit_gender;
                                cout << '\n';

                                storage_data [i][2] = edit_gender;

                                cout << "Your New Gender is: " << edit_gender << '\n';
                                break;

                            case 4:
                                cout << "Enter a New Contact Number: ";
                                cin >> edit_contact;
                                cout << '\n';

                                storage_data [i][3] = edit_contact;

                                cout << "Your New Contact Number is: " << edit_contact << '\n';
                                break;
        
                            case 5:
                                cout << "Enter a New Address: ";
                                cin >> edit_address;
                                cout << '\n';

                                storage_data [i][4] = edit_address;

                                cout << "Your New Address is: " << edit_address << '\n';
                                break;

                            case 6:
                                    cout << "Enter a New Email Address: ";
                                    cin >> edit_email;
                                    cout << '\n';

                                    storage_data [i][5] = edit_email;

                                    cout << "Your New Email Address is: " << edit_email << '\n';
                                    break;
    
                                default:
                                    cout << "Data Point Cannot Be Found!\n";
                                    break;
                        }
            }
            else if (storage_data [i][6] != ID)
            {
                cout << "ERROR: User ID " << ID << " not Found. \n";
            }
        }
    }

}
