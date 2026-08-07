#include <iostream>
using namespace std;

int createAccount()
{
    string firstName;
    string lastName;
    string username;
    string email;
    string password;
    string confirmPassword;
    string phoneNumber;
    string dateOfBirth;
    string gender;
    string country;
    char acceptTerms;

    cout << "Create Your Account: \n\n";

    cout << "First Name: ";
    cin >> firstName;

    cout << "Last Name: ";
    cin >> lastName;

    cout << "Username: ";
    cin >> username;

    cout << "Email: ";
    cin >> email;

    cout << "Password: ";
    cin >> password;

    cout << "Confirm Password: ";
    cin >> confirmPassword;

    cout << "Phone Number: ";
    cin >> phoneNumber;

    cout << "Date of Birth (DD/MM/YYYY): ";
    cin >> dateOfBirth;

    cout << "Gender: ";
    cin >> gender;

    cout << "Country: ";
    cin >> country;

    cout << "Accept Terms (Y/N): ";
    cin >> acceptTerms;
}

int main()
{
    createAccount();
    return 0;
}