#include <sodium.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>

long long int generate();
int sodium_loading();
long long int isPrime(long long int num);
int main();

int sodium_loading() {
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
modified to generate a new number and call itself if the return is false
*/

long long int isPrime(long long int num) {
	if (num <= 3) {
		return num > 1;
	}
	else if (num % 2 == 0 || num % 3 == 0) {
		num = generate();
		num = isPrime(num);
		return num;
	}
	else {
		for (int i = 5; i * i <= num; i += 6) {
			if (num % i == 0 || num % (i + 2) == 0) {
				num = generate();
				num = isPrime(num);
				return num;
			}
		}
		return num;
	}
}

long long int generate() {
	long long int number = randombytes_random();
	int randombytes_close(void);
	number = isPrime(number);
	return number;
}

int main() {
	sodium_loading();
	long long int nice_int = generate();
	std::cout << nice_int << std::endl;
	return 0;
}