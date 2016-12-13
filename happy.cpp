// Finding Happy Numbers by Greg McFarlin
// MATH 308
// Fall 2016
#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
	double sum = 1;
	double frac = 0;
	double sumfrac = 0;
	
    for (int i=0; i<n; i++)
    {
	  	sum = sum * arr[i];
	  	frac = arr[i];
	  	sumfrac += 1/frac;
	}
	  	
	if (sumfrac == 1)
	{
	  	for (int i=0; i<n; i++)
		{
			cout << arr[i] << " ";
		}
	  	cout << "= " << sum;      
      	cout << endl;      					 	
	}
}
 
void findHappy(int x, int arr[], int curr_sum, int curr_idx)
{
   	if (curr_sum == x)
   	{
      	printArr(arr, curr_idx);
      	return;
   	}
   
   	int num = 1;
 
   	while (num<=x-curr_sum && (curr_idx==0 || num<=arr[curr_idx-1]))
   	{
       	arr[curr_idx] = num; 
       	findHappy(x, arr, curr_sum+num, curr_idx+1);
       	num++;
   	}
}
 
void feelHappy(int x)
{
    int arr[x];
    findHappy(x, arr, 0, 0);
}
 
int main()
{
	for (int x=1; x<=50; x++)
	{
		feelHappy(x);
	}
	return 0;
}
