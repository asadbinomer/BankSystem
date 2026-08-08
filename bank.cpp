#include <iostream>
using namespace std;

struct User
{
    string username;
    int password;
    string email;
    double balance;
};

User users[100];

int totalUser;
int logedInUser = -1;

int createAccount()
{
    cout << "\nCreate Your Account: \n\n";

    cout << "Username: " << endl;
    cin >> users[totalUser].username;

    cout << "Password: " << endl;
    cin >> users[totalUser].password;

    cout << "Email: " << endl;
    cin >> users[totalUser].email;

    totalUser++;
}

int login()
{
    string username;
    int password;

    cout << "\nLogin \n\n";

    cout << "Enter your Username: ";
    cin >> username;

    cout << "Enter your Password: ";
    cin >> password;

    if (logedInUser != -1)
    {
        cout << "You are already login.\n";
        return 0;
    }

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
        else
        {
            cout << "\nUsernmae and Password is not found.\n";
        }
    }
}

int deposit()
{
    if (logedInUser == -1)
    {
        cout << "\nPlease login to deopsit you amount . \n";
        return 0;
    }

    double amount;

    cout << "\nEnter your amount to deposit" << endl;
    cout << "\n$";
    cin >> amount;

    users[logedInUser].balance += amount;
    cout << "\nDeposit Successful!\n";
    cout << "New Balance: $" << users[logedInUser].balance << endl;
}

int withdraw()
{
    if (logedInUser == -1)
    {
        cout << "\nPlease login to withdraw you amount . \n";
        return 0;
    }

    double amount;

    cout << "\nEnter your amount to withdraw" << endl;
    cout << "\n$";
    cin >> amount;

    if (amount > users[logedInUser].balance)
    {
        cout << "\nBalance kam hai.\n";
        return 0;
    }

    users[logedInUser].balance -= amount;
    cout << "\nWithdraw Successful!\n";
    cout << "New Balance: $" << users[logedInUser].balance << endl;
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
        cout << "\nBallance kam hai.\n";
        return 0;
    }

    users[logedInUser].balance -= amount;
    users[receiverUser].balance += amount;

    cout << "\nTransfer Successful!\n";
    cout << "Sent to: " << users[receiverUser].username << endl;
    cout << "Amount: " << amount << endl;
    cout << "Remaining Balance: "
         << users[logedInUser].balance << endl;

    return 0;
}

int changePin()
{
    int currentPassword;
    if (logedInUser == -1)
    {
        cout << "\nPlease login first.\n";
        return 0;
    }

    cout << "Enter yoour current password: ";
    cin >> currentPassword;
    if (currentPassword == users[logedInUser].password)
    {
        cout << "Enter your new password: ";
        cin >> users[logedInUser].password;
    }
    else
    {
        cout << "Password is incorrect";
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

    cout << "\nAccount Details: \n";

    cout << "Username: " << users[logedInUser].username << endl;
    cout << "Email: " << users[logedInUser].email << endl;
    cout << "Balance: " << "$" << users[logedInUser].balance << endl;

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
    int choice;

    do
    {
        cout << "\n Bank System\n  \n";

        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. Change PIN\n";
        cout << "7. Display Account\n";
        cout << "8. Logout\n";
        cout << "9. Exit\n";

        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            logedInUser = totalUser - 1;
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
            cout << "\ninvalid choice";
            break;
        }
    } while (choice != 9);

    return 0;
}