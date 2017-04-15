// dhke.h
#pragma once
#ifndef DHKE_H
class DHKE {
public :
	static int sodium_loading();
	static long long int generate();
	static long long int isPrime(long long int num);
	static long long int public_key(
		long long int base_g, 
		long long int secret_a, 
		long long int modulus);
	static long long int shared_secret(
		long long int public_key,
		long long int secret_b,
		long long int modulus);

};
#endif // !DHKE_H
