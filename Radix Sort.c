/*Radix sort*/
#include<stdio.h>
int iarr[200]={0};
int iarr2[200]={0};
int iarrsize;
/*Following function finds maximum value in list*/
int findmax()
{
	int iloop,temp=iarr[0];
	for(iloop=0;iloop<iarrsize;iloop++)
	{
		if(temp<iarr[iloop])
		temp=iarr[iloop];
	}
	return temp;
}
/*Function to take input list of numbers*/
void input()
{
	int iloop;
	printf("Enter number of values:\n");
	scanf("%d",&iarrsize);//Entering number of elements to be inserted
	printf("Enter %d elements:\t",iarrsize);
	for(iloop=0;iloop<iarrsize;iloop++)
	{
		scanf("%d",&iarr[iloop]);
	}
	
}
/*This function returns 10 raised to the power 'pow'*/
int power(int pow)
{
	int iloop=0,product=1;
	for(iloop=1;iloop<=pow;iloop++)
	product=10*product;
	return product;
}
/*This function sorts the numbers according to ones place, tens place and so on*/
void sort()
{
	int iloop,jloop,temp;
	for(iloop=0;iloop<iarrsize-1;iloop++)
	{
		for(jloop=iloop+1;jloop<iarrsize;jloop++)
		{
			if(iarr2[jloop]<iarr[iloop])
			{
				temp=iarr2[jloop];
				iarr2[jloop]=iarr2[iloop];
				iarr2[iloop]=temp;
				temp=iarr[jloop];
				iarr[jloop]=iarr[iloop];
				iarr[iloop]=temp;
			}
		}
	}
}
/*Function to display array*/
void display()
{
	int iloop=0;
	for(iloop=0;iloop<iarrsize;iloop++)
	printf("%d\t",iarr[iloop]);
}
int main()
{
	int maxval,digit=0,jloop,iloop,tenvalue;
	input();
	printf("\nOriginal array:\n");
	display();
	maxval=findmax();
	while(maxval>0)
	{
		digit++;//Counting number of digits in greatest element
		maxval=maxval/10;
	}
	for(jloop=1;jloop<=digit;jloop++)
	{
		tenvalue=power(jloop);//Raising 10 to 10^1,10^1,10^2 and so on
		for(iloop=0;iloop<10;iloop++)
		iarr2[iloop]=iarr[iloop]%tenvalue;//Extracting digits of every number
		sort();
	}
	printf("\nSorted array:\n");//Displaying sorted array
	display();
}
