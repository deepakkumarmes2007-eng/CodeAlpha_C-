#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Input validation
    if (username.empty() || password.empty()) {
        cout << "Error: Username and Password cannot be empty.\n";
        return;
    }

    // Check if username already exists
    ifstream checkFile(username + ".txt");
    if (checkFile.is_open()) {
        cout << "Error: Username already exists.\n";
        checkFile.close();
        return;
    }

    // Store credentials in a file
    ofstream userFile(username + ".txt");
    userFile << username << endl;
    userFile << password << endl;
    userFile.close();

    cout << "Registration Successful!\n";
}

// Function to login
void loginUser() {
    string username, password;
    string storedUsername, storedPassword;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream userFile(username + ".txt");

    if (!userFile.is_open()) {
        cout << "Error: User not found.\n";
        return;
    }

    getline(userFile, storedUsername);
    getline(userFile, storedPassword);
    userFile.close();

    if (username == storedUsername && password == storedPassword) {
        cout << "Login Successful! Welcome, " << username << "!\n";
    } else {
        cout << "Error: Invalid Username or Password.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}