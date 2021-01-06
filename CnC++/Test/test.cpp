#include <iostream>
#include <stdlib.h>

using namespace std;

struct CLS {
  int m_i;
  CLS(int i) : m_i(i) {}
  CLS() { CLS(0); }
};
int main() {
  CLS obj;
  cout << obj.m_i << endl;

  system("PAUSE");
  return 0;
}