/*
GFG approach:

Following are few observations about the next greater number. 
1) If all digits sorted in descending order, then output is always �Not Possible�. For example, 4321. 
2) If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234. 
3) For other cases, we need to process the number from rightmost side (why? because we need to find the 
smallest of all greater numbers)

You can now try developing an algorithm yourself. 
Following is the algorithm for finding the next greater number. 
I) Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than 
the previously traversed digit. For example, if the input number is �534976�, we stop at 4 because 4 is smaller 
than next digit 9. If we do not find such a digit, then output is �Not Possible�.

II) Now search the right side of above found digit �d� for the smallest digit greater than �d�. For �534976?, 
the right side of 4 contains �976�. The smallest digit greater than 4 is 6.

III) Swap the above found two digits, we get 536974 in above example.

IV) Now sort all digits from position next to �d� to the end of number. The number that we get after sorting 
is the output. For above example, we sort digits in bold 536974. 
We get �536479� which is the next greater number for input 534976

TC ==> O(NlogN)
SC ==> O(1)

EFFICIENT APPROACH:

The above implementation can be optimized in following ways. 
1) We can use binary search in step II instead of linear search. 
2) In step IV, instead of doing simple sort, we can apply some clever technique to do it in linear time. 
Hint: We know that all digits are linearly sorted in reverse order except one digit which was swapped.
With above optimizations, we can say that the time complexity of this method is O(n). 

Optimised Approach : 

1. Here instead of sorting the digits after (i-1) index, we are reversing the digits as mentioned in the 
above optimisation point.

2. As they will be in decreasing order so to find the smallest element possible from the right part we 
just reverse them thus reducing time complexity.

use reverse() STL to get next smallest number greater than d

reverese() It reverses the order of the elements in the range [first, last) of any container. 
The time complexity is O(n). Note: The range used is [first, last), which contains all the elements between 
first and last,including the element pointed by first but not the element pointed by last.

*/


#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


// Given a number as a char array number[], this function finds the
// next greater number.  It modifies the same array to store the result
vector<int> nextPermutation(int n, vector<int> number)
{
	//TEST
	cout<<"\ninput array\n";
	for(int i=0;i<n;i++)
	{
		cout<<number[i]<<" ";
	}
	
	int d,pos_of_d;
	//find the number that is smaller than previous number from last ((STEP I))
	for(int i=n-1;i>=0;i--)
	{
		if (i==0)
    	{
        	cout << "\nNext number is not possible";
    	}
    	else if(i>0 && (number[i] > number[i-1]))
		{
			d=number[i-1];
			cout<<"\n d => "<<d;
			pos_of_d=i-1;
			break;
		}	
	}
	int min=INT_MAX;
	//II) Now search the right side of above found digit �d� for the smallest digit greater than �d�.
	//GFG se dekha approach
	int i=pos_of_d;
	int j=i+1;
	int smallest=i+1;
	
	
	for(j=i+1;j<n;j++)
	{
		if(number[j]>d && number[j]<number[smallest])
		{
			smallest=j;
		}	
	}
	//swap d and smallest
	swap(&number[smallest], &number[pos_of_d]);
	
	//TEST
	cout<<"\nAfter swapped d and smallest\n";
	for(int i=0;i<n;i++)
	{
		cout<<number[i]<<" ";
	}
	
	//sort using reverse to reduce TC
	reverse(number.begin()+j,number.begin()+n);   //range [first, last) hai isiliye n liya nhi to n-1 lete
	
	//TEST
	cout<<"\nAfter REVERSE\n";
	for(int i=0;i<n;i++)
	{
		cout<<number[i]<<" ";
	}
	
	
	cout << "\n\nFINAL: Next number with same set of digits is \n";
	for(int i=0;i<n;i++)
	{
		cout<<number[i]<<" ";
	}
 
    
	
}


// Driver program to test above function
int main()
{
    vector<int> arr{ 5,3,4,9,7,6 };
    nextPermutation(arr.size(),arr);
    return 0;
}
