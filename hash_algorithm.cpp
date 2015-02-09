#include "hash_algorithm.h"

long int RSHash(string& s)
{
	int b = 378551;
	int a= 63689;
	long int hash = 0;
	for (int i = 0; i < s.length(); ++i) {
		hash = hash * a + s[i];
		a *= b;
	}
	return hash;
}

long int JSHash(string& s)
{
	long int hash = 0x4e67c6a7;	
	for (int i = 0; i < s.length(); ++i) {
		hash ^= ((hash << 5) + s[i] + (hash >> 2));
	}
	return hash;
}

#define BitsInUnsignedInt	(4*8)
#define ThreeQuarters		(BitsInUnsignedInt * 3 / 4)
#define OneEighth		(BitsInUnsignedInt / 8)
#define HighBits		(0xffffffff) << (BitsInUnsignedInt - OneEighth)
long int PJWHash(string& s)
{
	long int hash = 0;
	long int test = 0;
	for (int i = 0; i < s.length(); ++i) {
		hash = (hash << OneEighth) + s[i];
		if ((test = hash & HighBits) != 0) {
			hash = ((hash & (test >> ThreeQuarters)) & (~HighBits));
		}
	}
	return hash;
}

long int ELFHash(string& s)
{
	long int hash = 0;
	long int x = 0;
	for (int i = 0; i < s.length(); ++i) {
		hash = (hash << 4) + s[i];
		if (x = hash & 0xf0000000) {
			hash ^= (x >> 24);
		}
		hash &= ~x;
	}
	return hash;
}

long int BKDRHash(string& s)
{
	long int seed = 131; // 31 131 1313 13131 131313 etc...
	long int hash = 0;
	for (int i = 0; i < s.length(); ++i) {
		hash = (hash * seed) + s[i];
	}
	return hash;
}

long int SDBMHash(string& s)
{
	long int hash = 0;
	for (int i = 0; i < s.length(); ++i) {
		hash = s[i] + (hash << 6) + (hash << 16) - hash;
	}
	return hash;
}

long int DJBHash(string& s)
{
	long int hash = 5381;
	for (int i = 0; i < s.length(); ++i) {
		hash = (hash << 5) + hash + s[i];
	}
	return hash;
}

long int DEKHash(string& s)
{
	long int hash = s.length();
	for (int i = 0; i < s.length(); ++i) {
		hash = (hash << 5) ^ (hash >> 27) ^ s[i];
	}
	return hash;
}

long int APHash(string& s)
{
	long int hash = 0xaaaaaaaa;
	for (int i = 0; i < s.length(); ++i) {
		if (0 == (i & 1)) {
			hash ^= ((hash << 7) ^ s[i] * (hash >> 3));
		} else {
			hash ^= (~((hash << 11) + s[i] ^ (hash >> 5)));
		}
	}
	return hash;
}
