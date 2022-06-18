#include <iostream>
using namespace std;

int main() {
  double dx = 665857.0;
  double dy = 470832.0;
  long long ix = 665857.0;
  long long iy = 470832.0;
  float fx = 665857.0;
  float fy = 470832.0;

  cout << "Enter precisio: " << fixed << ix*ix*ix*ix << " " << 4*iy*iy*iy*iy << " " << 4*iy*iy << endl;
  cout << "Double precisio: " << fixed << dx*dx*dx*dx << " " << 4*dy*dy*dy*dy << " " << 4*dy*dy << endl;
/*
  cout << "Doble precisio: " << fixed << dx*dx*dx*dx - 4*dy*dy*dy*dy - 4*dy*dy << endl;
  cout << "Simple precisio: " << fixed << fx*fx*fx*fx - 4*fy*fy*fy*fy - 4*fy*fy << endl;
  cout << "Enter precisio: " << fixed << ix*ix*ix*ix - 4*iy*iy*iy*iy - 4*iy*iy << endl;*/
}
