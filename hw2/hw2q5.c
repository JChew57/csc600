#include <stdio.h>
#include <string.h>
#include <time.h>

double sec(void);
int bs(int a[], int n, int x);
int rbs(int a[], int x, int min, int max);

int main()
{
	double t;
	t = sec();

	//run program
	int j, i, K = 100000, n = 1000;
	int a[n];
	//fill array with numbers
	for(i = 0; i < n; i++){a[i] = i;}

	//run bs
	for(j = 0; j < K; j++)
	{
		for(i = 0; i < n; i++)
		{
			if(bs(a,n,i) != i){printf("ERROR\n");}
		}
	}

	t = sec() - t;
	printf("Runtime = %f\n", t);
	return 0;
}

double sec(void){return (double)clock()/CLOCKS_PER_SEC;}

/**/
//iterative version
int bs(int a[], int n, int x)
{
	int min = 0, max = n - 1;
	while (max >= min)
    {
	    int mid = min + ((max - min)/2);
	    if(a[mid] == x){return mid;}
	    else if (a[mid] < x){min = mid + 1;}
	    else{max = mid - 1;}
    }
    //x not found
	return -1;
}
/**/

/**/
//recursive version
int bs(int a[], int n, int x)
{
	return rbs(a, x, 0, n);
}

int rbs(int a[], int x, int min, int max)
{
	if (max < min){return -1;}//x not found
	else
	{
		int mid = min + ((max - min)/2);
		if (a[mid] > x){return rbs(a, x, min, mid - 1);}
		else if (a[mid] < x){return rbs(a, x, mid + 1, max);}
		else{return mid;}
	}
}
/**/