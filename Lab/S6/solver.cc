#include <iostream>
using namespace std;

int main() {
  unsigned int num;
  while (cin >> hex >> num) {
    cout << "byte: " << hex << num%32 << " bloc: " << hex << num/32 << " linia: " << hex << (num/32)%128 << " TAG: " << hex << (num/32)/128 <<endl;
  }
}
