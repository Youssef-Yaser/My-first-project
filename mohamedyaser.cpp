#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void binary_youssef(int a) {
  string s = "";
  if ( a == 0 )
    s += '0';
  else {
    while ( 1 ) {
      if ( a % 2 == 0 )
        s += '0';
      else
        s += '1';
      if ( a == 1 )
        break;
      a /= 2;
    }
  }
  reverse(s.begin(), s.end());
  cout << "The Binary number is : "<<s<< endl;
}
void octal_youssef(int a) {
  string s = "";
  if ( a == 0 )
    s += '0';
  else {
    while ( 1 ) {
      if ( a % 8 != 0 )
        s += to_string(a%8);
      else
        s += '0';
      if(a<8)
        break;
      a /= 8;
    }
  }
  reverse(s.begin(), s.end());
  cout << "The Octal number is : "<<s<< endl;
}
void Hex_decimal_youssef(int a) {
  string s = "";
  if ( a == 0 )
    s += '0';
  else {
    while ( 1 ) {
      if ( true) {
        if(a%16<10)
        s += to_string(a%16);
        else {
          s+=char(a%16+55);
        }
      }
      if(a<16)
        break;
      a /= 16;
    }
  }
  reverse(s.begin(), s.end());
  cout << "The Hex Decimal number is : "<<s<< endl;
}
int main() {
  int a;
  cin >> a;
  binary_youssef(a);
  octal_youssef(a);
  Hex_decimal_youssef(a);
  return 0;
}
