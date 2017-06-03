#include<stdio.h>
long long int c;
void merge(long long int L[],long long int R[],long long int arr[],long long int nL,long long int nR)
{
	long long int i,j,k,sum;
	i=j=k=0;
	sum=0;
	while(i<nL && j<nR)
	{
		if(L[i]<R[j])
		{
			sum+=L[i];
			arr[k++]=L[i++];
		}	
		else
		{
			arr[k++]=R[j++];
			c=c+sum;
		}
	}
	while(i<nL)
	arr[k++]=L[i++];
	while(j<nR)
	{
		arr[k++]=R[j++];
		c=c+sum;
	}
}
void mergeSort(long long int arr[],long long int n)
{
	long long int i;
	if(n<2)
	return;
	long long int mid=n/2;
	long long int left[mid];
	long long int right[n-mid];
	for(i=0;i<mid;i++)
	left[i]=arr[i];
	for(;i<n;i++)
	right[i-mid]=arr[i];
	mergeSort(left,mid);
	mergeSort(right,(n-mid));
	merge(left,right,arr,mid,(n-mid));
}
int main()
{
	long long int t,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		c=0;
		scanf("%lld",&n);
		long long int A[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
		}
		mergeSort(A,n);
		printf("%lld\n",c);
	}
	return 0;
}
