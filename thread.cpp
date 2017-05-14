#include <iostream>
#include <map>
#include <mutex>
#include <thread>

#include "lib/ffile.hpp"

using namespace std;

void WordCount(int tid, int threads, string text, int chunkSize) {
  // cout << "I'm the thread --> " << tid << endl;
  if (tid == threads - 1) {
    text =  text.substr(chunkSize * tid, text.size() - (chunkSize * tid));
  } else {
    text =  text.substr(chunkSize * tid, chunkSize);
  }
  vector<string> tokens = tokenizer(replaceChar(text));
  cout << text << endl;
  // displayTokenList(tokens);
  cout << "_________" << endl;

  // for (int i = 0; i < tokens.size(); i++) {
  //   mtx.lock();
  //   words[tokens[i]]++;
  //   mtx.unlock();
  // }
}

int main(int argc, char *argv[]) {
  cout << argv[1] << endl;
  string text = readFile(argv[1]);
  int num_threads = stoi(argv[2]);
  int chunk = text.size() / num_threads;
  vector<map<string, int>> words(num_threads); 


  // // threads
  // thread t[num_threads];

  // // Launch a group of threads
  // for (int i = 0; i < num_threads; ++i) { t[i] = thread(WordCount, i, num_threads, text, chunk); }

  // // Join the threads with the main thread
  // for (int i = 0; i < num_threads; ++i) { t[i].join(); }

  // displayHash(words);

  return 0;
}