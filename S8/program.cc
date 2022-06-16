#include <iostream>
#include <string>
#include <cstdarg>
#include <fstream>
#include <memory>
#include <cstdio>
#include <vector>
using namespace std;

std::string exec(const char* cmd) {
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}

float average(vector<double>& v) {
  float min = v[0];
  float max = min;
  float total = 0;

  for (int i = 0; i < 5; ++i) {
    total += v[i];
    if (v[i] > max) max = v[i];
    if (v[i] < min) min = v[i];
  }

  return (total - min - max)/3;
}

double toFloat(string s) {
  string l = s.substr(s.find("=") + 1, s.size());
  return stod(l);
}

int main() {
  vector<string> par = {"ijk", "jki", "kij", "ijk2", "jki2", "kij2"};

  for (int n = 0; n < par.size(); ++n) {
    for (int i = 256; i <= 1024; i *= 2) {
      string c = "gcc mm-" + par[n] + ".c tiempo.c -DN=" + to_string(i) + " -o "+ par[n] + to_string(i);
      char* c2 = &c[0];
      exec(c2);
      vector<double> v(5);
      string k = "./" + par[n] + to_string(i);
      for (int j = 0; j < 5; ++j) {
        char* k2 = &k[0];
        string r = exec(k2);
        v[j] = toFloat(r);
      }
      cout << par[n] << " " << to_string(i) << " "<< average(v) << endl;
    }
    cout << endl;
  }
}
