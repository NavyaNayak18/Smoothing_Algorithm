#include <stdlib.h>
float in[10][10], out[10][10], filter[3][3];
int i=0,j=0,n;

main() 
{
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			in[i][j] = rand()%255;
		}
	}	

	cout << " The Generated Image is: " << endl;
	cout.precision(5);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << in[i][j] << " ";		/* This displays the generated matrix*/
		}
		cout << endl;
	}
	cout << endl;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			filter[i][j] = 1;			/*This creates a filter matrix*/
		}
	}	
  
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			out[i][j] = in[i][j];	
		}
	}	
  
	for (i = 1; i < n-1; i++)
	{
		for (j = 1; j < n-1; j++)
		{
			out[i][j] = ( filter[0][0] * in[i-1][j-1] 
						+ filter[0][1] * in[i-1][j]
						+ filter[0][2] * in[i-1][j+1]
						+ filter[1][0] * in[i][j-1]
						+ filter[1][1] * in[i][j]
						+ filter[1][2] * in[i][j+1]
						+ filter[2][0] * in[i+1][j-1]
						+ filter[2][1] * in[i+1][j]
						+ filter[2][2] * in[i+1][j+1] ) / 9;
		}
	}
	cout << " The Smoothened Image is: " << endl;

	for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
		{
			cout << out[i][j] << " ";			/*This displays the final matrix*/
		}
		cout << endl;
	}  
	cout << endl;
}