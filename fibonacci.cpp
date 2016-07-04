int fibo(int n) {
	if (n <= 1)
		return n;
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}
int eff_fibo(int n) {
	if (n <= 1)
		return n;
	else {
		int now = 1, pre = 0, next;
		for (int i = 1; i < n; ++i) {
			next = now + pre;
			pre = now;
			now = next;
		}
		return next;
	}
}
