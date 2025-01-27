#include "Regist.h"
#include <iostream>
using namespace std;
int main()
{
    SocialNetwork network;

    try {
        network.registerUser("testUser", "Passw0rd!");
        network.registerUser("anotherUser", "Password123@");
        network.loginUser("testUser", "Passw0rd!");
        network.loginUser("unknownUser", "12345678");
    }
    catch (ExistLoginException& e) {
        cout << e.what() << endl;
    }
    catch (WrongPasswordLengthException& e) {
        cout << e.what() << endl;
    }
    catch (FormatPasswordException& e) {
        cout << e.what() << endl;
    }
    catch (InvalidLoginException& e) {
        cout << e.what() << endl;
    }
    catch (InvalidPasswordException& e) {
        cout << e.what() << endl;
    }
}

