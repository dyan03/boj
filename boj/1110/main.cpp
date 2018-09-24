#include <stdio.h>

int solver(int num) {

	return (num % 10) * 10 + (num / 10 + num % 10) % 10;
}


int main() {
	int num,num_;
	int count = 1;
	scanf("%d", &num_);

	num = num_;
	

	while (1) {
		num = solver(num);
		if (num == num_)break;
		else count++;
	}
	printf("%d", count);
}
