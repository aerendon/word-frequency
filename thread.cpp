#include <iostream>
#include <thread>

#include "lib/ffile.hpp"

using namespace std;

static const int num_threads = 3;
static const int words = 0;

void WordCount(int tid) {
  cout << "Launched by thread " << tid << endl;
}

int main(int argc, char *argv[]) {
  cout << argv[1] << endl;

  string text = read(argv[1]);
  vector<string> tokens = tokenizer(text);
  displayTokenList(tokens);
  // thread t[num_threads];

  // // Launch a group of threads
  // for (int i = 0; i < num_threads; ++i) {
  //   t[i] = thread(WordCount, i);
  // }

  // cout << "Launched from the main\n";

  // // Join the threads with the main thread
  // for (int i = 0; i < num_threads; ++i) {
  //   t[i].join();
  // }

  return 0;
}