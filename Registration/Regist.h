#pragma once
#include <iostream>
#include <cstring>
using namespace std;


const int MAX_USERS = 100;


class ExistLoginException {
public:
    const char* what() {
        return "This login already exists.";
    }
};

class WrongPasswordLengthException {
public:
    const char* what() {
        return "Password must be at least 8 characters long.";
    }
};

class FormatPasswordException {
public:
    const char* what() {
        return "Password must contain at least one digit, one uppercase letter, one lowercase letter, and one special character.";
    }
};

class InvalidLoginException {
public:
    const char* what() {
        return "Invalid login.";
    }
};

class InvalidPasswordException {
public:
    const char* what() {
        return "Invalid password.";
    }
};


class User_Account {
public:
    char login[50];
    char password[50];

    User_Account() {
        strcpy_s(login, "");
        strcpy_s(password, "");
    }

    User_Account(const char* login, const char* password) {
        strcpy_s(this->login, login);
        strcpy_s(this->password, password);
    }
};


class SocialNetwork {
private:
    User_Account accounts[MAX_USERS];
    int user_count;


    bool isValidPassword(const char* password) {
        bool hasDigit = false, hasUpper = false, hasLower = false, hasSpecial = false;
        for (int i = 0; password[i] != '\0'; i++) {
            if (isdigit(password[i])) hasDigit = true;
            else if (isupper(password[i])) hasUpper = true;
            else if (islower(password[i])) hasLower = true;
            else hasSpecial = true;
        }
        return hasDigit && hasUpper && hasLower && hasSpecial;
    }

public:
    SocialNetwork() : user_count(0) {}


    void registerUser(const char* login, const char* password) {

        for (int i = 0; i < user_count; i++) {
            if (strcmp(accounts[i].login, login) == 0) {
                throw ExistLoginException();
            }
        }

        if (strlen(password) < 8) {
            throw WrongPasswordLengthException();
        }


        if (!isValidPassword(password)) {
            throw FormatPasswordException();
        }

        accounts[user_count] = User_Account(login, password);
        user_count++;
        cout << "User registered successfully!" << endl;
    }

    void loginUser(const char* login, const char* password) {
        for (int i = 0; i < user_count; i++) {
            if (strcmp(accounts[i].login, login) == 0) {
                if (strcmp(accounts[i].password, password) == 0) {
                    cout << "Login successful!" << endl;
                    return;
                }
                else {
                    throw InvalidPasswordException();
                }
            }
        }
        throw InvalidLoginException();
    }
};
