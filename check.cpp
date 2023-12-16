#include <stdio.h>

int main(){
	int x, y;
	
	printf("Enter values of x and y: ");
	scanf("%d %d", &x, &y);
	
	int temp = x;
	x = y;
	y = temp;
	
	printf("x=%d y=%d", x, y);
	
	return 0;
}
