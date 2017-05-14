#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

void displayTokenList(vector<string> tokens) {
  for (int i = 0; i < tokens.size(); i++) {
    cout << tokens[i] << endl;
  }
}

vector<string> tokenizer(string input) {
  string myText(input);
  vector<string> vecToken;
  istringstream iss(myText);
  string token;
  while (std::getline(iss, token, ' ')) {
    // cout << token << endl;
    vecToken.push_back(token);
  }
  return vecToken;
}

//Replace (. , ; : ? ! ¿ ¡) to tokenizer the text
string replaceChar(string text) {
  text.erase(remove(text.begin(), text.end(), '.'), text.end());
  text.erase(remove(text.begin(), text.end(), ','), text.end());
  text.erase(remove(text.begin(), text.end(), ';'), text.end());
  text.erase(remove(text.begin(), text.end(), ':'), text.end());
  text.erase(remove(text.begin(), text.end(), '('), text.end());
  text.erase(remove(text.begin(), text.end(), ')'), text.end());
  return text;
}

string readFile(string name) {
  ifstream file(name);
  string str;
  string file_contents;
  while (getline(file, str)) {
    file_contents += str;
    file_contents.push_back('\n');
  } 
  return file_contents; 
} 

void displayHash(map<string, int> words) {
  for(auto const &word : words) {
    cout << word.first << " -> " << word.second << endl;
  }
}