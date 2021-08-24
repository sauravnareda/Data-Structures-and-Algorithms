#include<stdio.h>

int array[50];
int main()
{
	int i, n;
	printf("\n              Merge Sorting              ");
	printf("\n-----------------------------------------\n");
	printf("\nEnter The Number of Elements in Array: \n");
	scanf("%d",&n);
	printf("\nEnter The %d Elements in The Array: \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}

	merge_sort(array,0,n-1);
	printf("\nThe Sorted Array is :\n");
	for( i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	return 0;
}

int merge_sort( int array[], int low, int high )
{
	int middle;
	if( low < high)
	{
		middle = (low + high) / 2;
		merge_sort( array, low, middle );
		merge_sort( array, middle+1, high );
		merge( array, low, middle, high );
	}
	return 0;
}

int merge( int array[], int l, int m, int h )
{
	int x[10], y[10];
	int n1, n2, i, j, k;
	n1 = m-l+1;
	n2 = h-m;
	for( i=0;i<n1;i++ )
	{
		x[i] = array[l+i];
	}
	for( j=0;j<n2;j++ )
	{
		y[j] = array[m+1+j];
	}
	
	x[i] = 9999;
	y[j] = 9999;
	i = 0;
	j = 0;
	
	for( k=l;k<=h;k++ )
	{
		if( x[i] < y[j])
		{
			array[k] = x[i++];
		}
		else
		{
			array[k] = y[j++];
		}
	}
	return 0;
}
