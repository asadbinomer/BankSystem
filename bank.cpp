#include <iostream>
#include <fstream>
using namespace std;

struct User
{
    string username;
    int password;
    double balance;
};

User users[100];

int totalUser = 0;
int logedInUser = -1;

void saveUsers()
{
    ofstream file("users.txt");

    if (!file)
    {
        cout << "\nError: Could not open users.txt\n";
        return;
    }

    for (int i = 0; i < totalUser; i++)
    {
        file << users[i].username << " "
             << users[i].password << " "
             << users[i].balance << endl;
    }

    file.close();
}

void loadUsers()
{
    ifstream file("users.txt");

    if (!file)
    {
        totalUser = 0;
        return;
    }

    totalUser = 0;

    while (totalUser < 100 &&
           file >> users[totalUser].username
                >> users[totalUser].password
                >> users[totalUser].balance)
    {
        totalUser++;
    }

    file.close();
}

int createAccount()
{
    if (totalUser >= 100)
    {
        cout << "\nUser limit reached.\n";
        return 0;
    }

    cout << "\nCreate Your Account:\n\n";

    cout << "Username: ";
    cin >> users[totalUser].username;

    cout << "Password: ";
    cin >> users[totalUser].password;

    users[totalUser].balance = 0;

    totalUser++;

    saveUsers();

    cout << "\nAccount Created Successfully!\n";

    return 0;
}

int login()
{
    string username;
    int password;

    if (logedInUser != -1)
    {
        cout << "\nYou are already logged in.\n";
        return 0;
    }

    cout << "\nLogin\n\n";

    cout << "Enter your Username: ";
    cin >> username;

    cout << "Enter your Password: ";
    cin >> password;

    for (int i = 0; i < totalUser; i++)
    {
        if (username == users[i].username)
        {
            if (password == users[i].password)
            {
                logedInUser = i;

                cout << "\nLogin Successful!\n";
                return 0;
            }
            else
            {
                cout << "\nPassword is incorrect.\n";
                return 0;
            }
        }
    }

    cout << "\nUsername is not found.\n";

    return 0;
}

int deposit()
{
    if (logedInUser == -1)
    {
        cout << "\nPlease login to deposit your amount.\n";
        return 0;
    }

    double amount;

    cout << "\nEnter your amount to deposit\n";
    cout << "$";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\nInvalid amount.\n";
        return 0;
    }

    users[logedInUser].balance += amount;

    saveUsers();

    cout << "\nDeposit Successful!\n";
    cout << "New Balance: $" << users[logedInUser].balance << endl;

    return 0;
}

int withdraw()
{
    if (logedInUser == -1)
    {
        cout << "\nPlease login to withdraw your amount.\n";
        return 0;
    }

    double amount;

    cout << "\nEnter your amount to withdraw\n";
    cout << "$";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\nInvalid amount.\n";
        return 0;
    }

    if (amount > users[logedInUser].balance)
    {
        cout << "\nBalance kam hai.\n";
        return 0;
    }

    users[logedInUser].balance -= amount;

    saveUsers();

    cout << "\nWithdraw Successful!\n";
    cout << "New Balance: $" << users[logedInUser].balance << endl;

    return 0;
}

int transfer()
{
    if (logedInUser == -1)
    {
        cout << "\nPlease login first.\n";
        return 0;
    }

    string sendTo;
    double amount;

    cout << "\nEnter username to send money: ";
    cin >> sendTo;

    int receiverUser = -1;

    for (int i = 0; i < totalUser; i++)
    {
        if (users[i].username == sendTo)
        {
            receiverUser = i;
            break;
        }
    }

    if (receiverUser == -1)
    {
        cout << "\nUser not found.\n";
        return 0;
    }

    if (receiverUser == logedInUser)
    {
        cout << "\nYou cannot send money to yourself.\n";
        return 0;
    }

    cout << "Enter amount: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\nInvalid amount.\n";
        return 0;
    }

    if (amount > users[logedInUser].balance)
    {
        cout << "\nBalance kam hai.\n";
        return 0;
    }

    users[logedInUser].balance -= amount;
    users[receiverUser].balance += amount;

    saveUsers();

    cout << "\nTransfer Successful!\n";
    cout << "Sent to: " << users[receiverUser].username << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Remaining Balance: $"
         << users[logedInUser].balance << endl;

    return 0;
}

int changePin()
{
    if (logedInUser == -1)
    {
        cout << "\nPlease login first.\n";
        return 0;
    }

    int currentPassword;

    cout << "Enter your current password: ";
    cin >> currentPassword;

    if (currentPassword == users[logedInUser].password)
    {
        cout << "Enter your new password: ";
        cin >> users[logedInUser].password;

        saveUsers();

        cout << "\nPassword changed successfully.\n";
    }
    else
    {
        cout << "\nPassword is incorrect.\n";
    }

    return 0;
}

int displayAccount()
{
    if (logedInUser == -1)
    {
        cout << "\nPlease login first.\n";
        return 0;
    }

    cout << "\nAccount Details:\n";

    cout << "Username: "
         << users[logedInUser].username << endl;

    cout << "Balance: $"
         << users[logedInUser].balance << endl;

    return 0;
}

int logout()
{
    if (logedInUser == -1)
    {
        cout << "\nYou are not logged in.\n";
        return 0;
    }

    cout << "\nLogout Successful!\n";

    logedInUser = -1;

    return 0;
}

int main()
{
    loadUsers();

    int choice;

    do
    {
        cout << "\nBank System\n\n";

        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. Change PIN\n";
        cout << "7. Display Account\n";
        cout << "8. Logout\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;

        case 2:
            login();
            break;

        case 3:
            deposit();
            break;

        case 4:
            withdraw();
            break;

        case 5:
            transfer();
            break;

        case 6:
            changePin();
            break;

        case 7:
            displayAccount();
            break;

        case 8:
            logout();
            break;

        case 9:
            cout << "\nProgram Exited.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
            break;
        }

    } while (choice != 9);

    return 0;
}