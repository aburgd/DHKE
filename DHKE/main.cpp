// main.cpp
#include <sodium.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "dhke.h"

int main() {
	DHKE::sodium_loading();
	long long int nice_number = DHKE::generate();
	std::cout << nice_number << std::endl;
	return 0;
}