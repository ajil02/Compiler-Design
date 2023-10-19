#include<stdio.h>
#include<ctype.h>

void main()
{
	FILE *file;
	char ch,arr[100];
	int c=1;
	file=fopen("file.txt","r");
	int i=0;
	do 
	{
        	ch = fgetc(file);
        	arr[i]=ch;
        	printf("%c", ch);
        	i++;
   	
   	}while (ch != EOF);
 
	fclose(file);
	printf("\n");
	printf("Lexime\tToken\t\tLine_number");
	for(int i=0;arr[i]!=EOF;i++)
	{
		if (arr[i]=='+' ||arr[i]=='-' ||arr[i]=='*' ||arr[i]=='/' ||arr[i]=='%' ||arr[i]=='=')
		{
			printf("\n%c\toperator\t%d",arr[i],c);
		}
		else if(isalpha(arr[i]))
		{
			printf("\n%c\tidentifier\t%d",arr[i],c);
		}
		else if(isdigit(arr[i]))
		{
			printf("\n%c\tconstant\t%d",arr[i],c);
		}
		else if(arr[i]==';')
		{
			printf("\n%c\tpunctuation\t%d",arr[i],c);
		}
		else if(arr[i]=='\n')
		{
			c++;
		}
	}
}
