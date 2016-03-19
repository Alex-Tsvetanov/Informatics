#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string input);

int main() {
    string input;
    int result = 0;
    cin>>input;
    int len = input.length();
    int longestPalLen = 0;
    if(isPalindrome(input)) {
       cout<<0<<endl; 
    } else {
        for(int i = 0; i < len; i++) { //for every dig
            for(int j = i; j < len; j++) {
                string l = "";
                for(int k = i; k <= j; k++) {
                    l+=(char)input[k];
                }
                //  cout<<l<<endl;
                bool isPal = isPalindrome(l);
                if(isPal) {
                    longestPalLen = j - i;
                }
            }
            result++;
            i+= longestPalLen;
            longestPalLen = 0;
        }
         cout<<result-1<<endl;
    }

    return 0;
}

bool isPalindrome(string input) {
    bool answer = true;
    int len = input.length();

    if(len > 1) {
        int i2 = 0;
        for(int i = 0; i < len/2; i++) {
            i2 = len - i - 1;
            if(input[i] != input[i2]) {
                answer = false;
                break;
            }
        }
    } else {
        answer = true;
    }
    return answer;
}
