// dhke.h
#pragma once
#ifndef DHKE_H
class DHKE {
public :
	static int sodium_loading();
	static long long int generate();
	static bool isPrime(long long int num);
	static long long int public_key(
		long long int base_g, 
		long long int alex, 
		long long int modulus);
	static long long int shared_secret(
		long long int public_key,
		long long int bailey,
		long long int modulus);
	static long long int base_gen();
	static long long int modulus_gen();
	static long long int secret_gen();
	static long long int get_input();
};
#endif // !DHKE_H
