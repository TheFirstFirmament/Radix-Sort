/*Binary sort - From an array of elements, takes smallest element and sends it to the beginning, takes maximum element and sends it to the last. Continues this excluding those two values until array is sorted.*/
#include<stdio.h>
int iarr[10]={0};
int iarr2[10]={0};
int findmax(int low,int up)//Method to find maximum element
{
	int iloop,temp=iarr[low];
	for(iloop=low;iloop<=up;iloop++)
	{
		if(iarr[iloop]<temp)
		temp=iarr[iloop];
	}
	return temp;
}
int findmin(int low,int up)//Method to find minimum element
{
	int iloop,temp=iarr[low];
	for(iloop=low;iloop<=up;iloop++)
	{
		if(iarr[iloop]>temp)
		temp=iarr[iloop];
	}
	return temp;
}
int findpos(int idata,int ilow,int iup)//Method to find position of given value
{
	int iloop=0;
	for(iloop=ilow;iloop<=iup;iloop++)
	{
		if(iarr[iloop]==idata)
		return iloop;
	}
	return 0;
}
void swap(int maxpos,int ipos)//Method to swap two values
{
	int temp=0;
	temp=iarr[maxpos];
	iarr[maxpos]=iarr[ipos];
	iarr[ipos]=iarr[maxpos];
}
void displayoriginal()
{
	int iloop=0;
	for(iloop=0;iloop<10;iloop++)
	printf("%d\t",iarr[iloop]);
}
void displaysorted()//Displaying sorted data
{
	int iloop=0;
	for(iloop=0;iloop<10;iloop++)
	printf("%d\t",iarr2[iloop]);
}
void input()//Taking input
{
	int iloop=1;
	printf("Enter 10 values:\n");
	for(iloop=1;iloop<=10;iloop++)
	scanf("%d",&iarr[iloop-1]);
}
void reverse()//Reversing the array
{
	int iloop=0;
	for(iloop=0;iloop<10;iloop++)
	iarr[iloop]=iarr2[9-iloop];
}
int main()
{
	int ilower=0,iupper=9,imax,imin,maxpos,minpos,ichoice;
	input();
	printf("Original array:\n");
	displayoriginal();
	while(ilower<iupper)
	{
		imax=findmax(ilower,iupper);
		imin=findmin(ilower,iupper);
		iarr2[ilower]=imin;
		iarr2[iupper]=imax;
		maxpos=findpos(imax,ilower,iupper);
		minpos=findpos(imin,ilower,iupper);
		swap(maxpos,iupper);
		swap(minpos,ilower);
		ilower++;
		iupper--;
	}
	reverse();
	printf("\n\nEnter: 1 for sort in ascending order, anything else for sort in descending order\n");
	scanf("%d",&ichoice);
	if(ichoice==1)
	{
		printf("\n\nSorted array:\n");
		displayoriginal();
	}
	else
	{
		printf("\n\nSorted array:\n");
		displaysorted();
	}
}
