// dhke.cpp
#include <sodium.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "dhke.h"

int DHKE::sodium_loading() {
	if (sodium_init() == -1) {
		std::cout << "Failure to include sodium" << std::endl;
		return 1;
	}
	else {
		randombytes_seedbytes();
		return 0;
	}
}

/*
using https://codereview.stackexchange.com/a/84058
*/
bool DHKE::isPrime(long long int num) {
	if (num <= 3) {
		return num > 1;
	}
	else if (num % 2 == 0 || num % 3 == 0) {
		/*num = DHKE::generate();
		num = DHKE::isPrime(num);*/
		return false;
	}
	else {
		for (int i = 5; i * i <= num; i += 6) {
			if (num % i == 0 || num % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
}

long long int DHKE::generate() {
	long long int number = randombytes_random();
	number = isPrime(number);
	int randombytes_close(void);
	return number;
}

long long int DHKE::public_key(
	long long int base_g,
	long long int alex,
	long long int modulus) {

	return 0;
}

long long int DHKE::shared_secret(
	long long int public_key,
	long long int bailey,
	long long int modulus) {
	return 0;
}

long long int DHKE::base_gen() {
	long long int number = DHKE::generate();
	return number;
}

long long int DHKE::modulus_gen() {
	long long int modulus = DHKE::generate();
	modulus = DHKE::isPrime(modulus);
	return modulus;
}

long long int DHKE::secret_gen() {
	long long int secret = DHKE::generate();
	secret = DHKE::isPrime(secret);
	return secret;
}

long long int DHKE::get_input() {
	std::cout << "Please enter an integer\n";
	long long int number;
	std::cin >> number;
	if (!(DHKE::isPrime(number))) {
		std::cout << "Sorry, your input is not valid.\n";
		std::cout << "What would you like to do?\n";
		std::cout << "1) Generate an integer\n";
		std::cout << "2) Try another integer\n";
		std::cout << "3) Quit";
		int answer;
		std::cin >> answer;
		if (answer == 1) {
			while (!(DHKE::isPrime(number))) {
				number = DHKE::generate();
				DHKE::isPrime(number);
			}
			return number;
		}
		else if (answer == 2) {
			number = DHKE::get_input();
			return number;
		}
		else if (answer == 3) {
			return -1;
		}
		return 0;
	}
	else {
		return number;
	}
}