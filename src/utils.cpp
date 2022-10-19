#include "utils.hpp"

int precedence(char c) {
  switch (c) {
  case '>':
	return 1;
  case '+':
	return 2;
  case '*':
	return 3;
  case '~':
	return 4;
  default:
	return -1;
	break;
  }
}

void reverse(std::string& s) {
  unsigned int n = s.length();
  for(unsigned int i = 0; i < n - i; ++i) {
	char tmp = s[i];
	s[i] = s[n - i - 1];
	s[n - i - 1] = tmp;
  }
}

int char_index(char c) {
  if (c >= 'a' && c <= 'z')
	return (int)(c - 'a');
  else if (c >= 'A' && c <= 'Z')
	return (int)(c - 'A');
  return -1;
}
