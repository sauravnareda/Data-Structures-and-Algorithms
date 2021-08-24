#include<stdio.h>


int main()
{
	printf("                    Bubble Sorting                  ");
    printf("\n----------------------------------------------------\n");
	
	int array[100], n, i, c, d, swap;
	
	printf("\nEnter the size of the array: \n");
	scanf("%d",&n);
	
	printf("\nEnter the data in the array: \n");
	
	for( i=0; i<n; i++ )
	{
		scanf("%d",&array[i]);
	}

for(i=0;i<n;i++)
{
	for(c=0;c<n-1;c++)
	{
		for(d=0;d<n-c-1;d++)
		{
			if( array[d]>array[d+1])
			{
				swap = array[d];
				array[d] = array[d+1];
				array[d+1] = swap;
			}
		}
	}
}

printf("\nThe Numbers after sorting are: \n");
	
	for( i=0; i<n ; i++)
	{
		printf("%d\n",array[i]);
	}
	
}
