#!/bin/bash

sed -e 's/std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >\&/string/g' \
	-e 's/std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const\&/string/g' \
	-e 's/std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >/string/g' $1
