#include <iostream>
using namespace std;

bool check_for_dots(string str){

    bool check = true;
    bool findDot = false;
    int dotCount = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.'){
            if((i == 0 || i == str.length() - 1) || findDot){
                check = false;
                break;
            }
            findDot = true;
            dotCount++;
        }else findDot = false;
    }

    if(dotCount != 3) check = false;

    return check;
}


bool check_for_zero(string str) {
    bool check = true;
    int countNumbers = 0;
    if (str[0] == '0') check = false;
    else {
        for (int i = str.length() - 1; i >= 1; i--) {
            if(str[i] == '.') countNumbers = 0;
            if(str[i-1] == '.' && str[i] == '0' && countNumbers > 1) check = false;
            countNumbers++;
        }
    }
    return check;
}

bool check_for_correct_symbols(string str){
    bool check = true;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.' || (str[i] >= '0' && str[i] <= '9')) {
            check = true;
        }else {
            check = false;
            break;
        }
    }
    return check;
}




int main() {
    int octet = 0;
    int multiplier = 1;
    int countDigits = 0;
    bool mainFlag = true;
    string ipAddress;
    cout << "Enter ip address: ";
    cin >> ipAddress;
    if(!check_for_correct_symbols(ipAddress) || !check_for_dots(ipAddress) ||
            !check_for_zero(ipAddress)) mainFlag = false;
    else {
        for (int i = ipAddress.length() - 1; i >= 0; i--) {
            if (ipAddress[i] == '.') {
                countDigits = 0;
                multiplier = 1;
                octet = 0;
            } else {
                octet += (ipAddress[i] - '0') * multiplier;
                countDigits++;
                multiplier *= 10;
            }
            if(octet > 255 || countDigits > 3){
                mainFlag = false;
                break;
            }
        }

    }

    mainFlag ? cout << "Yes\n" : cout << "No\n";
    //cout << mainFlag ? "Yes\n" : "No\n"; Выводит 1 вместо Yes.
    return 0;
}
