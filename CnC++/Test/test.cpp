#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct CLS {
  int m_i;
  CLS(int i) : m_i(i) {}
  CLS() { CLS(0); }
};
int main() {
  vector<int> v;
  CLS obj;
  cout << obj.m_i << endl;

  system("PAUSE");
  return 0;
}