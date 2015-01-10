#include <cstring>
#include <iostream>

using namespace std;

void encode_white_space(char *str) {
  int len = strlen(str);
  char * origin_str = new char[len];
  memcpy(origin_str, str, len);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (origin_str[i] == ' ') {
      str[j++] = '%';
      str[j++] = '2';
      str[j++] = '0';
    } else {
      str[j++] = origin_str[i];
    }
  }
  str[j] = '\0';

  delete [] origin_str;
}


int main()
{
  char str[200] = "Mr John Smith";
  cout << str << endl;
  encode_white_space(str);
  cout << str << endl;
  return 0;
}
