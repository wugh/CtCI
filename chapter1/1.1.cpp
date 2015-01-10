#include <cstring>
#include <iostream>
#include "../require.h"

using namespace std;

bool unique_str(const char* str) {
  const int array_size = 128; // only check ASCII char
  bool container[array_size] = {0};
  for (int i = 0; i < strlen(str); ++i) {
    int code = str[i];
    if (container[code] == 0)
      container[code] = 1;
    else 
      return false;
  }
  return true;
}


int main(int argc, char *argv[])
{
  requireArgs(argc, 1);
  cout << unique_str(argv[1]) << endl;
  return 0;
}
