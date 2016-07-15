/*
 * changing_money.cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: Mohamed
 */
int change_money(int m) {
	int c[] = { 10, 5, 1 };
	int i = 0;
	int tot = 0;
	while (m > 0) {
		tot+=m/c[i];
		m=m%c[i];
		i++;
	}
	return tot;
}



