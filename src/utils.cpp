#include "utils.hpp"

/*!
 * @brief Precedence order of all the logical expressions:
 *
 * ~ > * > + > (>)
 *
 * @param c the character for which the precedence needs to be determined
 * @returns the precedence of the logical expression
 */
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

/// @brief Reverse a string in-place
/// @param s the string to be reversed
void reverse(std::string& s) {
  unsigned int n = s.length();
  for(unsigned int i = 0; i < n - i; ++i) {
	char tmp = s[i];
	s[i] = s[n - i - 1];
	s[n - i - 1] = tmp;
  }
}

/*!
 * @brief Get the index of an alphabet (case insensitive) between 0 to 25
 * @param c the character for which the index is to be determined
 * @return the index of the respective character
 */
int char_index(char c) {
  if (c >= 'a' && c <= 'z')
	return (int)(c - 'a');
  else if (c >= 'A' && c <= 'Z')
	return (int)(c - 'A');
  return -1;
}
