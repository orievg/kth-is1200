//
// Created by Orievg on 2020-02-17.
//
int main() {


	int n = 4;
	int sum = 0;
	int prev = 1;
	for (int i = 1; i <= n; i++) {
		prev = i - 1;
		for (int j = 0; j <= prev; j++) {
			sum = sum + i
		}
	}

	printf("%d", sum );
	return 0;
}