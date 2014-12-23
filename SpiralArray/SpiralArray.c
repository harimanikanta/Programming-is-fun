#include<stdio.h>
#include<stdlib.h>
#define row 10
#define col 10
int main()
{
	int a[row][col],i,j,T=0,B=row-1,L=0,R=col-1,dir=0;
	unsigned int k=1;
	char ch[100];
	FILE *fp;
	while(T<=B&&L<=R)
	{
		if(dir==0)                         // left to right 
		{
			for(i=L;i<=R;i++)
				a[T][i]=k++;
			T++;      					   //increase top means moving to below row
		    dir=1;							//change direction:top to bottom
		}
		else if(dir==1)  					// top to bottom
		{
			for(i=T;i<=B;i++)
				a[i][R]=k++;
			R--;							//reduce the right value 
		    dir=2;
		}
		else if(dir==2)  					//right to left
		{
			for(i=R;i>=L;i--)
				a[B][i]=k++;
			B--;                            //move upward
			dir=3;							//change direction
        }
        else							   //bottom to top
		{
			for(i=B;i>=T;i--)
				a[i][L]=k++;
			L++;                            //move leftward
			dir=0;							//change direction
		}
	}
	fp=fopen("Newfile.txt","w");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
             k=a[i][j];
			 itoa(k,ch,10);  //converts integer to character array, i dont know how to write integer to file
			 fprintf(fp,ch);  //writes a string to file 
			 fputc(' ',fp);   //writes a blank character to file
		}	//printf("%d ",a[i][j]);
		
		//printf("\n");
		fputc('\n',fp);     //new line character 
	}
	fclose(fp);
	return 0;
}