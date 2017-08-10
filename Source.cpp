#include <iostream>
#include <string>
//#include <random>
#include <ctime>
#include <fstream>
#include <bitset>
#include <vector>
#include "sha256.h"
#include <sstream>
#include <algorithm>
#define ll long long

using namespace std;

string convertToASCII(string str) {
	int temp;
	string am = "";

	for (int i = 0; i < str.length(); i++) 
	{
		temp = str[i];
		am = am + to_string(temp);
	}
	return am;
}

ll int oddrand(ll int max)
{
	ll int temp = 0;
	while (temp % 2 == 0 || temp == 0) {
		temp = rand() % max;
	}
	return temp;
}

/*
* calculates (a * b) % c taking into account that a * b might overflow
*/
ll mulmod(ll a, ll b, ll mod)
{
	ll x = 0, y = a % mod;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			x = (x + y) % mod;
		}
		y = (y * 2) % mod;
		b /= 2;
	}
	return x % mod;
}

/*
* modular exponentiation
*/
ll modulo(ll base, ll exponent, ll mod)
{
	ll x = 1;
	ll y = base;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			x = (x * y) % mod;
		y = (y * y) % mod;
		exponent = exponent / 2;
	}
	return x % mod;
}

/*
* Fermat's test for checking primality
*/
bool Fermat(ll p, int iterations)
{
	if (p == 1)
	{
		return false;
	}
	for (int i = 0; i < iterations; i++)
	{
		ll a = rand() % (p - 1) + 1;
		if (modulo(a, p - 1, p) != 1)
		{
			return false;
		}
	}
	return true;
}

/*
* Miller-Rabin primality test, iteration signifies the accuracy
*/
bool Miller(ll p, int iteration)
{
	if (p < 2)
	{
		return false;
	}
	if (p != 2 && p % 2 == 0)
	{
		return false;
	}
	ll s = p - 1;
	while (s % 2 == 0)
	{
		s /= 2;
	}
	for (int i = 0; i < iteration; i++)
	{
		ll a = rand() % (p - 1) + 1, temp = s;
		ll mod = modulo(a, temp, p);
		while (temp != p - 1 && mod != 1 && mod != p - 1)
		{
			mod = mulmod(mod, mod, p);
			temp *= 2;
		}
		if (mod != p - 1 && temp % 2 == 0)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	srand(time(NULL));
	bool p1prime = false;
	bool p2prime = false;

	//random_device rd;

	
	
	string initialization = "Initializing encryption...";

	unsigned long long int r1 = oddrand(99);

	unsigned long long int r2 = oddrand(99);

	cout << r1 << endl;

	int iteration = 50;
	cout << "Testing Primality..." << endl;
	while ( !(Fermat(r1, iteration)) && !(Miller(r1, iteration)));
	{
			unsigned long long int r1 = oddrand(99);
	}

	while (!(Fermat(r2, iteration)) && !(Miller(r2, iteration)));
	{
		unsigned long long int r2 = oddrand(99);
	}

	string p1 = "P1 = ";
	string p2 = "P2 = ";
	p1 += to_string(r1);
	p2 += to_string(r2);
	cout << p1 << endl;
	cout << p2 << endl;

	unsigned long long int n = r1 * r2;

	string np = "N = ";
	np += to_string(n);

	cout << np << endl;
	

	unsigned long long int phn = (r1 - 1)*(r2 - 1);

	string phnp = "Phn = ";
	phnp += to_string(phn);

	cout << phnp << endl;

	unsigned long long int e = oddrand(10);

	while (e == 1 || );
	{
		unsigned long long int r1 = oddrand(99);
	}

	string ep = "e = ";
	ep += to_string(e);

	cout << ep << endl;
	
	unsigned long int d = (((2 * phn) + 1) / e);

	string dp = "d = ";
	dp += to_string(d);

	cout << dp << endl;

	string input = "Input Message:";

	cout << input << endl;

	string m;

	getline(cin, m);

	string am;

	am = convertToASCII(m);

	string ascii = "Ascii value: ";
	
	cout << ascii << am << endl;

	unsigned long long c = stoull(am, 0, 10);

	c = (pow (c, e));

	c = c % n;

	cout << c << endl;

	unsigned long long derp;

	derp = (pow(c, d));

	derp = derp % n;

	cout << derp << endl;



	string ver = "Success";

	cout << ver << endl;

	

	
	
	string hash = "Hash = ";

	string output1 = sha256(m);

	cout << hash << "sha256('" << m << "'): " << output1 << endl;


	return 0;

}