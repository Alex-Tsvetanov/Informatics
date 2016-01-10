#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
    string firstLine, secondLine, ans;
    getline(cin, firstLine, '\n');
    getline(cin, secondLine, '\n');
    if(firstLine.size() < secondLine.size())
        swap(firstLine, secondLine);
    reverse(firstLine.begin(), firstLine.end());
    reverse(secondLine.begin(), secondLine.end());
    char carry = '0';
    for(int n = 0; n < secondLine.size(); n++) {
        // bez vaproscheta sluchai
        if(carry == '0' && firstLine[n] == '0' && secondLine[n] == '0')
            carry = '0', ans.push_back('0');
        else if(carry == '0' && firstLine[n] == '0' && secondLine[n] == '1')
            carry = '0', ans.push_back('1');
        else if(carry == '0' && firstLine[n] == '1' && secondLine[n] == '0')
            carry = '0', ans.push_back('1');
        else if(carry == '0' && firstLine[n] == '1' && secondLine[n] == '1')
            carry = '1', ans.push_back('0');
        else if(carry == '1' && firstLine[n] == '0' && secondLine[n] == '0')
            carry = '0', ans.push_back('1');
        else if(carry == '1' && firstLine[n] == '1' && secondLine[n] == '0')
            carry = '1', ans.push_back('0');
        else if(carry == '1' && firstLine[n] == '0' && secondLine[n] == '1')
            carry = '1', ans.push_back('0');
        else if(carry == '1' && firstLine[n] == '1' && secondLine[n] == '1')
            carry = '1', ans.push_back('1');
        // sas edno vaprosche vav carry sluchai
        else if(carry == '?' && firstLine[n] == '0' && secondLine[n] == '0')
            carry = '0', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '1' && secondLine[n] == '0')
            carry = '?', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '0' && secondLine[n] == '1')
            carry = '?', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '1' && secondLine[n] == '1')
            carry = '1', ans.push_back('?');

        // sas edno vaprosche iz firstLine i secondLine
        else if(carry == '0' && firstLine[n] == '?' && secondLine[n] == '0')
            carry = '0', ans.push_back('?');
        else if(carry == '0' && firstLine[n] == '0' && secondLine[n] == '?')
            carry = '0', ans.push_back('?');
        else if(carry == '0' && firstLine[n] == '?' && secondLine[n] == '1')
            carry = '?', ans.push_back('?');
        else if(carry == '0' && firstLine[n] == '1' && secondLine[n] == '?')
            carry = '?', ans.push_back('?');
        else if(carry == '1' && firstLine[n] == '?' && secondLine[n] == '0')
            carry = '?', ans.push_back('?');
        else if(carry == '1' && firstLine[n] == '0' && secondLine[n] == '?')
            carry = '?', ans.push_back('?');
        else if(carry == '1' && firstLine[n] == '?' && secondLine[n] == '1')
            carry = '1', ans.push_back('?');
        else if(carry == '1' && firstLine[n] == '1' && secondLine[n] == '?')
            carry = '1', ans.push_back('?');

        // sa dve vaproscheta(moze da se namalat ifchetata
        else if(carry == '?' && firstLine[n] == '?' && secondLine[n] == '0')
            carry = '?', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '0' && secondLine[n] == '?')
            carry = '?', ans.push_back('?');
        else if(carry == '0' && firstLine[n] == '?' && secondLine[n] == '?')
            carry = '?', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '?' && secondLine[n] == '1')
            carry = '?', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '1' && secondLine[n] == '?')
            carry = '?', ans.push_back('?');
        else if(carry == '1' && firstLine[n] == '?' && secondLine[n] == '?')
            carry = '?', ans.push_back('?');

        // sas tri vaproscheta
        else if(carry == '?' && firstLine[n] == '?' && secondLine[n] == '?')
            carry = '?', ans.push_back('?');

    }
    // za ostanalata chast ot masiva opredelane ot samoto carry cikul, da vida i za nakraia sled vtoria cikul ako oshte ima edno na um
    for(int n = secondLine.size(); n < firstLine.size(); n++) {
        if(carry == '0' && firstLine[n] == '0')
            carry = '0', ans.push_back('0');
        else if(carry == '0' && firstLine[n] == '1')
            carry = '0', ans.push_back('1');
        else if(carry == '1' && firstLine[n] == '0')
            carry = '0', ans.push_back('1');
        else if(carry == '1' && firstLine[n] == '1')
            carry = '1', ans.push_back('0');
        else if(carry == '?' && firstLine[n] == '0')
            carry = '0', ans.push_back('?');
        else if(carry == '0' && firstLine[n] == '?')
            carry = '0', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '1')
            carry = '?', ans.push_back('?');
        else if(carry == '1' && firstLine[n] == '?')
            carry = '?', ans.push_back('?');
        else if(carry == '?' && firstLine[n] == '?')
            carry = '?', ans.push_back('?');
    }
    if(carry == '1' || carry == '?')
        ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    //ans.push_back('\n');
    //cout << firstLine << endl << secondLine << endl << ans << endl;;
    cout << ans;
    cout << endl;
    return 0;
}
