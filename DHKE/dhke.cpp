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
	int randombytes_close(void);
	return number;
}

long long int DHKE::public_key(
	long long int base_g,
	long long int alex,
	long long int modulus) {

	long long int public_key = std::pow(base_g, alex);
	public_key = public_key % modulus;
	public_key = std::abs(public_key);
	return public_key;
}

long long int DHKE::shared_secret(
	long long int public_key,
	long long int bailey,
	long long int modulus) {

	long long int shared_secret = std::pow(public_key, bailey);
	shared_secret = shared_secret % modulus;
	shared_secret = std::abs(shared_secret);
	return shared_secret;
}

long long int DHKE::base_gen() {
	long long int number = DHKE::generate();
	if (!(DHKE::isPrime(number))) {
		while (!(DHKE::isPrime(number))) {
			number = DHKE::generate();
			DHKE::isPrime(number);
		}
		return number;
	}
	else {
		return number;
	}
}

long long int DHKE::modulus_gen() {
	long long int modulus = DHKE::generate();
	if (!(DHKE::isPrime(modulus))) {
		while (!(DHKE::isPrime(modulus))) {
			modulus = DHKE::generate();
			DHKE::isPrime(modulus);
		}
		return modulus;
	}
	else {
		return modulus;
	}
}

long long int DHKE::secret_gen() {
	long long int secret = DHKE::generate();
	if (!(DHKE::isPrime(secret))) {
		while (!(DHKE::isPrime(secret))) {
			secret = DHKE::generate();
			DHKE::isPrime(secret);
		}
		return secret;
	}
	else {
		return secret;
	}
}

long long int DHKE::get_input() {
	std::cout << "Please enter an integer:\n";
	long long int number;
	std::cin >> number;
	if (!(DHKE::isPrime(number))) {
		std::cout << "Sorry, your input is not valid.\n"
			<< "What would you like to do?\n"
			<< "1) Generate an integer\n"
			<< "2) Try another integer\n"
			<< "3) Quit\n"
			<< std::endl;
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
			std::cin >> number;
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