#include <string>
#include <iostream>
using namespace std;

bool is_alternating_binary( string& s) {
    char alternate = '0';
    string temp = s;
	string temp1;
    for (char& c : s) {
        // Replace occurrences of current character with '0'
        temp1=temp;
        for (char& ch : temp) {
            if (ch == c) ch = '0';
        }

        // Check for consecutive zeros or ones
        for (int i = 0; i < temp.length(); i++) {
            if ((temp[i] == temp[i + 1]||temp[i] == temp[i - 1])&&temp[i]=='0') {
                // If consecutive ones found, return false
                temp=temp1;
		        for (char& hh : temp) {
		            if (hh == c) hh = '1';
		        }
            }
            if ((temp[i] == temp[i + 1]||temp[i] == temp[i - 1])&&temp[i]=='1') {
                // If consecutive ones found, return false
		        return false;
            }
        }
    }

    // If the length of the string is 1, return true
    if (temp.length() == 1) return true;    
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (is_alternating_binary(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}