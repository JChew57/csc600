#include <stdio.h>
#include <string.h>

int maxlen(int arr[], int size);

int main()
{
	//create demo array for testing
	int demo[10] = {1,2,3,4,4,5,5,5,6,6};

	printf("The longest sequence contains %d numbers.\n", maxlen(demo,10));
	return 0;
}

int maxlen(int arr[], int size)
{
	int largest = 0, count = 1, i;
	int prev = arr[0];

	//iterate through the array from the second element
	for(i = 1; i < size; i++)
	{
		int cur = arr[i];
		if(prev == cur)
		{
			count++;
			if(count > largest){largest = count;}

		}else{count = 1;}
		
		prev = cur;
	}
	return largest;
}