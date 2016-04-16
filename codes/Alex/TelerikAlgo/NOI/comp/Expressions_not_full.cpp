#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
 
using namespace std;
 
typedef long long int llint;
typedef pair <int,string> token;
#define Type first
#define Value second
#define mp make_pair
 
const int NUMBER = 0, OPERATION = 1, OTHER = 2;
const char sentinel = '#';
 
int get_type(char c) {
    if  (c == '~' || (c >= '0' && c <= '9')) return NUMBER;
    if (c == '^' || c == '-' || c == '*' || c == '+' || c == '/' || c == '%' || c == '>' || c == '<' ) return OPERATION;
    if (c == sentinel) return OPERATION; // sentinel
    return OTHER;    
}
map <string, int> x = {{"^",3},{"-",1},{"*",2},{"+",1},{"/",2},{"%",2},{">",4},{"<",4}};
 
// when operator a has greater priority than b
bool greater_priority(token a, token b) {
	if (a.Value == "^" && b.Value == "^")
		return true;
	return x [a.Value] < x [b.Value];
}
 
// integer to string conversion
string To_string(llint x) {
	bool negative = false;
	if (x < 0) negative = true;
	if (negative) x = -x;
    string s;
    while (x > 0) {
        s = (char)((x%10)+'0') + s;
        x/=10;
    }
    return (negative)?("-"+s):s;
}
 
// string to integer conversion
llint To_int(string s) {
	bool invert = (s [0] == '~');
	if (invert) s.erase (0, 1);
	bool negative = false;
	if (s [0] == '-')
		negative = true;
    llint x = 0;
    for (int i = negative ; i < (int)s.size() ; i++ ) {
         x = x*10 + ((llint)(s[i]-'0'));
    }
    int ans = x;
	if (negative) ans = -ans;
	if (invert) ans = ~ans;
	return ans;
}
 
int main(void) {
 
    string s;
    getline(cin,s);
 
 
    s += sentinel;    
   
    bool found_numbers = false;
    vector < token > tokens;
    string buffer;
    for (int i = 0; i  < (int)s.size(); i++) {
        char c = s[i];
        int type = get_type(c);
        switch(type) {
            case NUMBER:
                buffer += c;
                found_numbers = true;
            break;
            case OPERATION:
                if (!found_numbers) {
					if (c == '-') 
					{
						buffer = "0";
						found_numbers = true;
					}
					else
						exit (128);
                }
				if ((int)buffer.size() > 0) {
                    tokens.push_back(mp(NUMBER,buffer));
                    buffer = "";
                }
                tokens.push_back(mp(OPERATION,s.substr(i,1)));
                   
            break;  
        }
        int ts = (int)tokens.size();
        if (ts > 1 && tokens[ts-1].Type == tokens[ts-2].Type) {
            cout << "Invalid expression!" << endl;
            exit(-2);    
        }
    }
     
     tokens.pop_back();
 
 
    deque <token> calc,ops;
    string last_op;
    for (int i = 0; i < (int)tokens.size(); i++) {
            calc.push_back(tokens[i]);
            int cs = (int)calc.size();
           
            switch (tokens[i].Type) {
                case NUMBER:
                    if (last_op != "") {
                        swap(calc[cs-1],calc[cs-2]);
                        last_op = "";
                    }
                break;
                case OPERATION:
                    last_op = tokens[i].Value;
                    ops.push_back(tokens[i]);
                break;    
            }
           
            int os = (int)ops.size();
           
            if ( os > 1 && tokens[i].Type == NUMBER ) {
                if (greater_priority( ops[os-1], ops[os-2] ) ) {
                    swap( calc[cs-3] , calc[cs-2]);                        
                    swap( calc[cs-2] , calc[cs-1]);
                    swap( ops[os-1], ops[os-2] );
                }    
            }
    }
 
 
    token a, b, op, result = mp(NUMBER,"0");
    int atback = 0;
    while ((int)calc.size() > 1) {
         
        a = calc[0]; // first operand
        b = calc[1]; // second operand
        op = calc[2]; // operation
       
        if (op.Type != OPERATION) {
            calc.push_back(a);
            calc.pop_front();
           
            atback++;
           
        } else {
            calc.pop_front(); calc.pop_front(); calc.pop_front();
 
            if (op.Value == "*") {
                result.Value = To_string( To_int(a.Value) * To_int(b.Value) );
            } else if (op.Value == "+") {
                result.Value = To_string( To_int(a.Value) + To_int(b.Value) );
            } else if (op.Value == "-") {
                result.Value = To_string( To_int(a.Value) - To_int(b.Value) );
            } else if (op.Value == "^") {
                result.Value = To_string( (int)(pow (To_int(a.Value), To_int(b.Value)))%30011 );
            } else if (op.Value == "<") {
                result.Value = To_string( To_int(a.Value) << To_int(b.Value) );
            } else if (op.Value == ">") {
                result.Value = To_string( To_int(a.Value) >> To_int(b.Value) );
            } else {
                if (To_int(b.Value) == 0) {
                    cout << "Division by zero!" << endl;
                    exit(-3);
                }
                if (op.Value == "/") {
                    result.Value = To_string( To_int(a.Value) / To_int(b.Value) );
                } else if (op.Value == "%") {
                    result.Value = To_string( To_int(a.Value) % To_int(b.Value) );      
                }
        }
           
            calc.push_front(result);
           
            while (atback-- > 0) {
                    calc.push_front(calc.back());
                    calc.pop_back();
            }
            atback = 0;
       
        }
       
    }
   
    cout << To_string (To_int (calc.front().Value)) << endl;
 
    return 0;
}
