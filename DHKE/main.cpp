// main.cpp
#include <sodium.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "dhke.h"

int main() {
	DHKE::sodium_loading();
	std::cout << "What would you like to do?\n"
		<< "1) Generate a public key\n"
		<< "2) Generate a shared secret\n"
		<< "3) Quit\n" 
		<< std::endl;
	int answer;
	std::cin >> answer;
	if (answer == 1) {
		long long int base_g = DHKE::base_gen();
		long long int alex = DHKE::secret_gen();
		long long int modulus = DHKE::modulus_gen();
		long long int pub_key = DHKE::public_key(base_g, alex, modulus);
		std::cout << "Base: " << base_g
			<< "\nSecret: " << alex
			<< "\nModulus: " << modulus
			<< "\nPublic Key: " << pub_key;
		return 0;
	}
	else if (answer == 2) {
		std::cout << "Public Key:\n";
		long long int public_key = DHKE::get_input();
		std::cout << "Secret Number:\n";
		long long int bailey = DHKE::get_input();
		std::cout << "Prime Modulus:\n";
		long long int modulus = DHKE::get_input();
		
		long long int shared_secret = DHKE::shared_secret(public_key, bailey, modulus);
		std::cout << "Shared Secret: " << shared_secret;
		return 0;
	}
	else if (answer == 3) {
		std::cout << "Goodbye.";
		return -1;
	}
}