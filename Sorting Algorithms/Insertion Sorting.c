#include <stdio.h>
 
int main()
{
int n, array[1000], c, d, swap;
printf("\n            Insertion Sorting          ");
printf("\n-------------------------------------\n");
printf("\nEnter number of elements: \n");
scanf("%d", &n);
 
printf("\nEnter %d integers\n", n);
 
for (c = 0; c < n; c++)
{
    scanf("%d", &array[c]);
}
for(c=1;c<=n-1;c++)
{
	d = c;
	while( d>0 && array[d-1]>array[d])
	{
		swap = array [d];
		array[d] = array[d-1];
		array[d-1] = swap;
		d--;
	}
}

printf("\nSorted list in ascending order:\n");
printf("\n");
for (c = 0; c <= n - 1; c++)
{
    printf("%d ", array[c]);
}
	return 0;
}
