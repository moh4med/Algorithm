/*
 * gcd.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Mohamed
 */
int gcd(int a, int b) {
	int x=b;
	if(a<b){
		x=a;
	}
	for (int i = x; i > 0; --i) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}

}
int eucl_gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return eucl_gcd(b, a % b);
}



