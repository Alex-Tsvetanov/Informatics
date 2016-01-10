#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>

using namespace std;

int main()
{
    string a;
    cin >> a;
    string b;
    cin >> b;

    int a_i;
    cout << "as number: " << atoi(a.c_str()) << endl;
    //bitset <16> bin(number);

    return 0;
}

/*
    #include <string>
    #include <bitset>
    #include <iostream>
    using namespace std;
    int main(){
      string myString = "Hello World";
      for (std::size_t i = 0; i < myString.size(); ++i)
      {
          cout << bitset<8>(myString.c_str()[i]) << endl;
      }
    }
*/
