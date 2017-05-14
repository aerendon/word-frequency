#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  string myText("some text-to tokenize");
  istringstream iss(myText);
  string token;
  while (std::getline(iss, token, ' ')) {
    cout << token << endl;
  }
  return 0;
}
