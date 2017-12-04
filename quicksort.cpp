#include <iostream>
using namespace std;
#define	swap(a,b)	a^=b;	b^=a;	a^=b;

void quicksort(int array[],int left,int right){
	int moveleft=left,moveright=right;
	int center=array[(left+right)/2];
	while(1){
		while(array[moveleft]<array[center])	moveleft++;
		while(array[moveright]>array[center])	moveright++;
		if(moveleft>=moveright)	break;
		swap(array[moveleft],array[moveright]);
		moveleft++;	moveright--;
	}
	if(moveleft-left>=2)	quicksort(array,left,moveleft-1);
	if(right-moveright>=2)	quicksort(array,moveright+1,right);
}
