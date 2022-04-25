#include <stdio.h>
#include <string.h>
#include<stdlib.h>


//Ayberk Türksoy 150119919

//Function to Convert Signed integer to Hexadecimal Number
void signedInteger(int value,char ByteOrdering,FILE *output_file){
	int number;
	int place=0;
	int binary[16]={0};
	
	number=atoi(value);
	
	int count=15;
	int i=0;
	
    fprintf(output_file,"This is a signed integer. Signed integers are 2 bytes:\n");
    fprintf(output_file,"%d = ",number);
	
	if(number>=0)
	{
		while(number)
		{
		place=number%2;
		number=number/2;
		binary[count]=place;
		count--;	
		}
	}

	else
	{
       	while(count>=0) 
		{
            binary[count] = number & 0x1;
            number  = number >> 1;
            count--;
        }
	}
	for(i=0;i<16;i++)
	{
		fprintf(output_file,"%d",binary[i]);
	}
	
	fprintf(output_file,"\n");

   	for(i=0;i<16;i++)
	{
		fprintf(output_file,"%d",binary[i]);
	}
	
	fprintf(output_file," is ");
	
	int power=0;
	char result[6];
	result[0]='0';
	result[1]='x';
	int cal[16];
	int hexArray[4];

	int hex=0;
	int a=15;
	int b=3;
	for(i=15;i>=0;i--)
	{
		cal[i]=binary[i]*pow(2,power);
		power+=1;
		if(i%4==0)
		{	
			a=i+3;
			for(;a>=i;a--)
			{
				hex+=cal[a];
			}
			hexArray[b]=hex;
			hex=0;
			b--;
			power=0;
		}
	}
	a=2;
	for(b=0;b<4;b++)
	{
		if(hexArray[b]>9)
		{
			if(hexArray[b]==10)
				result[a]='A';
			else if(hexArray[b]==11)
				result[a]='B';
			else if(hexArray[b]==12)
				result[a]='C';
			else if(hexArray[b]==13)
				result[a]='D';
			else if(hexArray[b]==14)
				result[a]='E';
			else if(hexArray[b]==15)
				result[a]='F';
		}
		else
		{
		result[a]=hexArray[b]+'0';
		}
		a++;
	}
	
	for(i=0;i<6;i++)
	{
		fprintf(output_file,"%c",result[i]);
	}
	fprintf(output_file," in hexadecimal.\n");
	
	if(ByteOrdering=='l')
	{
		fprintf(output_file,"The byte ordering is little endian, so the signed integer will be represented as ");
		fprintf(output_file," %c%c %c%c",result[4],result[5],result[2],result[3]);
	}
	else if(ByteOrdering=='b')
	{
		fprintf(output_file,"The byte ordering is big endian, so the signed integer will be represented as ");
		fprintf(output_file," %c%c %c%c",result[2],result[3],result[4],result[5]);
	}
	fprintf(output_file,"\n\n");
}

//Function to Convert Unsigned integer to Hexadecimal Number
void unsignedInteger(int value,char ByteOrdering,FILE *output_file){	
	int number;
	int place=0;
	int binary[16]={0};
	
	
	
	number=atoi(value);
	int count=15;
	int i=0;

    fprintf(output_file,"%s\n",value);
    fprintf(output_file,"This is an unsigned integer. Unsigned integers are 2 bytes:\n");
    fprintf(output_file,"%d = ",number);
    
    
		while(number)
		{
		place=number%2;
		number=number/2;
		binary[count]=place;
		count--;	
		}

    
	for(i=0;i<16;i++)
	{
		fprintf(output_file,"%d",binary[i]);
	}
	
    fprintf(output_file,"\n");

   	for(i=0;i<16;i++)
	{
		fprintf(output_file,"%d",binary[i]);
	}
	
	fprintf(output_file," is ");
	
	int power=0;
	char result[6];
	result[0]='0';
	result[1]='x';
	int cal[16];
	int hexArray[4];

	int hex=0;
	int a=15;
	int b=3;
	for(i=15;i>=0;i--)
	{
		cal[i]=binary[i]*pow(2,power);
		power+=1;
		if(i%4==0)
		{	
			a=i+3;
			for(;a>=i;a--)
			{
				hex+=cal[a];
			}
			hexArray[b]=hex;
			hex=0;
			b--;
			power=0;
		}
	}
	a=2;
	for(b=0;b<4;b++)
	{
		if(hexArray[b]>9)
		{
			if(hexArray[b]==10)
				result[a]='A';
			else if(hexArray[b]==11)
				result[a]='B';
			else if(hexArray[b]==12)
				result[a]='C';
			else if(hexArray[b]==13)
				result[a]='D';
			else if(hexArray[b]==14)
				result[a]='E';
			else if(hexArray[b]==15)
				result[a]='F';
		}
		else
		{
		result[a]=hexArray[b]+'0';
		}
		a++;
	}
		
	//Prints Hexadecimal result
	for(i=0;i<6;i++)
	{
		fprintf(output_file,"%c",result[i]);
	}
	fprintf(output_file," in hexadecimal.\n");
	if(ByteOrdering=='l')
	{
		fprintf(output_file,"The byte ordering is little endian, so the signed integer will be represented as ");
		fprintf(output_file," %c%c %c%c",result[4],result[5],result[2],result[3]);
	}
	else if(ByteOrdering=='b')
	{
		fprintf(output_file,"The byte ordering is big endian, so the signed integer will be represented as ");
		fprintf(output_file," %c%c %c%c",result[2],result[3],result[4],result[5]);
	}
	fprintf(output_file,"\n\n");
}

//Function to Convert Floating Point Number to Hexadecimal Number
void floatingPoint(int value,char byteOrdering,int floatingPointSize,FILE* output_file){

	int size=floatingPointSize;
	float number;
	float decimal;//ondalýk kýsmý
	int place=0;
	int binary[16]={0};
	int dizi[19]={0};//Decimal array
	int array[32]={0};
	int a=0;
 int exp=0;
int n=0;
 
 
 if(floatingPointSize==1)
 	exp=4;
 if(floatingPointSize==2)
 	exp=7;
 if(floatingPointSize==3)
 	exp=13;
 if(floatingPointSize==4)
 	exp=19;
	
	
	
	number=	atof(value);
	
	int number2=number;

	decimal=number-number2;
	if(number2<0)
		decimal = fabs(decimal);

	int count=15;
	int i=0;
	
    fprintf(output_file,"This is a floating point number.\n");
    fprintf(output_file,"%f = ",number);
	int pozneg=0;
	
	if(number2>=0)
	{
	
		pozneg=0;
		while(number2)
		{
		place=number2%2;
		number2=number2/2;
		binary[count]=place;
		count--;	
		}
	}

	else
	{
		
		pozneg=1;
       	while(count>=0) 
		{
            binary[count] = number2 & 0x1;
            number2  = number2 >> 1;
            count--;
        }
	}

	
	for(i=count+1;i<16;i++)
	{
		fprintf(output_file,"%d",binary[i]);
	}


	fprintf(output_file,".");
	while(decimal!=1)
{
	decimal=decimal*2;
	if(decimal>1)
	{
		decimal=decimal-1;
		dizi[a]=1;
	}
	else  if(decimal<1)
	{
		dizi[a]=0;
	}
	if(decimal==1)
	{
		dizi[a]=1;
		break;
	}
	
	if(a==exp-1)
		break;
	
	a++;
}
	
	 i=0;
for(i=0;i<a+1;i++)
{
	fprintf(output_file,"%d",dizi[i]);
}
 fprintf(output_file," = ");
 
fprintf(output_file,"%d.",binary[count+1]);
 for(i=count+2;i<16;i++)
	{
		fprintf(output_file,"%d",binary[i]);
	}
 for(i=0;i<a+1;i++)
{
	fprintf(output_file,"%d",dizi[i]);
}

int pow1=14-count;

	
  fprintf(output_file," * %d^%d",2,pow1);
 
 
	fprintf(output_file,"\n");
	fprintf(output_file,"Mantissa is ");

int e=0;
fprintf(output_file,"%d.",binary[count+1]);
array[e]=binary[count+1];
e++;
 for(i=count+2;i<16;i++)
	{
		array[e]=binary[i];
		fprintf(output_file,"%d",binary[i]);
		e++;
	}
 for(i=0;i<a+1;i++)
{
	array[e]=dizi[i];
	fprintf(output_file,"%d",dizi[i]);
	e++;
}


fprintf(output_file," However, for %d ",floatingPointSize );
fprintf(output_file,"bytes we ave %d ",exp);
fprintf(output_file,"bits of fraction part, so we need to round it.");
fprintf(output_file,"\n");
fprintf(output_file,"%d.",binary[count+1]);

 for(i=count+2;i<16;i++)
	{
		fprintf(output_file,"%d",binary[i]);
	}
 for(i=0;i<a+1;i++)
{
	fprintf(output_file,"%d",dizi[i]);
}
fprintf(output_file," = ");
int p;
int round=0;
if(array[e-1]==1)
	round=1;
e=exp+1;
array[e-1]=round;
fprintf(output_file,"%d.",binary[count+1]);
for(p=1;p<e;p++)
{
	fprintf(output_file,"%d",array[p]);
}



fprintf(output_file," The fraction part is ");
 p;
round=0;
if(array[e-1]==1)
	round=1;
e=exp+1;
array[e-1]=round;
for(p=1;p<e;p++)
{
	fprintf(output_file,"%d",array[p]);
}

	
fprintf(output_file,".");
fprintf(output_file,"\nE = %d",pow1);
fprintf(output_file,". Exponent is E = exp – Bias, were Bias =");
n=(8*floatingPointSize)-exp-1;
fprintf(output_file," 2^(%d",n);
	n=n-1;
	int bias=pow(2,n);
	bias-=1;

fprintf(output_file,"-1)-1 =%d ",bias);
fprintf(output_file,"Therefore the equation is %d =",pow1);
fprintf(output_file,"exp – %d.",bias);
bias+=pow1;
fprintf(output_file,"exp = %d",bias);
fprintf(output_file," which is ");
int array2[16]={0};
place=0;
count=15;

		while(bias)
		{
		place=bias%2;
		bias=bias/2;
		array2[count]=place;
		count--;	
		}
	i=0;
	for(i=count+1;i<16;i++)
	{
		fprintf(output_file,"%d",array2[i]);
	}
	fprintf(output_file,".\n");
	if(pozneg==1)
		fprintf(output_file,"The number is negative, so the sign bit is %d.",pozneg);
	if(pozneg==0)
		fprintf(output_file,"The number is positive, so the sign bit is %d.",pozneg);
	
	
	

	int allArray[32]={0};
	allArray[0]=pozneg;
	fprintf(output_file,"\nThe number at total is %d",allArray[0]);
	int count2=1;

	for(i=count+1;i<16;i++)
	{
		allArray[count2]=array2[i];
		count2++;
	}
	for(p=1;p<e;p++)
	{
		allArray[count2]=array[p];
		count2++;
	}

	for(i=1;i<count2;i++)
	{
		fprintf(output_file,"%d",allArray[i]);
	}
	fprintf(output_file," which is ");
	int power=0;
	char result[10]={};
	result[0]='0';
	result[1]='x';
	int cal[32]={0};
	int hexArray[8]={0};
	
	int hex=0;
	a=count2;
	int b=(floatingPointSize*2)-1;
	
	for(i=count2-1;i>=0;i--)
	{
		cal[i]=allArray[i]*pow(2,power);
		power+=1;
		if(i%4==0)
		{	
			a=i+3;
			for(;a>=i;a--)
			{
				hex+=cal[a];
			}
			hexArray[b]=hex;
			hex=0;
			b--;
			power=0;
		}
	}
	
	a=2;
	floatingPointSize*=2;

	for(b=0;b<floatingPointSize;b++)
	{
		if(hexArray[b]>9)
		{
			if(hexArray[b]==10)
				result[a]='A';
			else if(hexArray[b]==11)
				result[a]='B';
			else if(hexArray[b]==12)
				result[a]='C';
			else if(hexArray[b]==13)
				result[a]='D';
			else if(hexArray[b]==14)
				result[a]='E';
			else if(hexArray[b]==15)
				result[a]='F';
		}
		else
		{
		result[a]=hexArray[b]+'0';
		}
		a++;
	}

	for(i=0;i<floatingPointSize+2;i++)
	{
		fprintf(output_file,"%c",result[i]);
	}
	fprintf(output_file," in hexadecimal.");
	
	if(byteOrdering=='l')
	{
		fprintf(output_file,"Byte ordering is little endian, so the floatig point is represented as ");
		
		if(size==1)
		{
			fprintf(output_file," %c%c",result[2],result[3]);
		}
		else if(size==2)
		{
			fprintf(output_file," %c%c %c%c ",result[4],result[5],result[2],result[3]);
		}
		else if(size==3)
		{
			fprintf(output_file," %c%c %c%c %c%c ",result[6],result[7],result[4],result[5],result[2],result[3]);
		}
		else if(size==4)
		{
			fprintf(output_file," %c%c %c%c %c%c %c%c",result[8],result[9],result[6],result[7],result[4],result[5],result[2],result[3]);
		}
	}
	else if(byteOrdering=='b')
	{
		fprintf(output_file,"Byte ordering is big endian, so the floatig point is represented as ");
		if(size==1)
		{
			fprintf(output_file," %c%c",result[2],result[3]);
		}
		else if(size==2)
		{
			fprintf(output_file," %c%c %c%c",result[2],result[3],result[4],result[5]);
		}
		else if(size==3)
		{
			fprintf(output_file," %c%c %c%c %c%c",result[2],result[3],result[4],result[5],result[6],result[7]);
		}
		else if(size==4)
		{
			fprintf(output_file," %c%c %c%c %c%c %c%c",result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9]);
		}
		
	}
	fprintf(output_file,". \nSo the first line of the output line has to be ");
	if(byteOrdering=='l')
	{
		fprintf(output_file,"Byte ordering is little endian, so the floatig point is represented as ");
		
		if(size==1)
		{
			fprintf(output_file," %c%c",result[2],result[3]);
		}
		else if(size==2)
		{
			fprintf(output_file," %c%c %c%c ",result[4],result[5],result[2],result[3]);
		}
		else if(size==3)
		{
			fprintf(output_file," %c%c %c%c %c%c ",result[6],result[7],result[4],result[5],result[2],result[3]);
		}
		else if(size==4)
		{
			fprintf(output_file," %c%c %c%c %c%c %c%c",result[8],result[9],result[6],result[7],result[4],result[5],result[2],result[3]);
		}
	}
	else if(byteOrdering=='b')
	{
		fprintf(output_file,"Byte ordering is big endian, so the floatig point is represented as ");
		if(size==1)
		{
			fprintf(output_file," %c%c",result[2],result[3]);
		}
		else if(size==2)
		{
			fprintf(output_file," %c%c %c%c",result[2],result[3],result[4],result[5]);
		}
		else if(size==3)
		{
			fprintf(output_file," %c%c %c%c %c%c",result[2],result[3],result[4],result[5],result[6],result[7]);
		}
		else if(size==4)
		{
			fprintf(output_file," %c%c %c%c %c%c %c%c",result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9]);
		}
		
	}
fprintf(output_file,"\n\n");
}
int main(){	
	FILE *inputFile;
	char inputFileName[20];
	char value[10][10];	
	int i=0;
	int j=0;
	
	while(j==0){
			//Takes input file name
	printf("The name of the input file? (Example : input.txt)  ");
	scanf("%20s",inputFileName);
		// Opens input file and print the values inside it.
	inputFile = fopen(inputFileName,"r");	
	if(inputFile !=NULL){
	while(!feof(inputFile)){
		fscanf(inputFile,"%s",&value[i]);
		printf("%s\n",value[i]);
		i++;
		j++;
	}
	}}



    //Asks for byte ordering type
    char byteOrdering;
    printf("\nByte ordering :");
    scanf("%s",&byteOrdering);
    
    //Asks for floating point size
    int floatingPointSize;
    printf("Floating point size :");
    scanf("%d",&floatingPointSize);
    fclose(inputFile);
    
    //Reads all inputs again and calls the Signed/Unsigned/Floating Point Functions for them.
    inputFile = fopen(inputFileName,"r");
    
	FILE *output_file;
	output_file = fopen("output.txt","w");
	
	
    while(!feof(inputFile)){
		fscanf(inputFile,"%s",&value[i]);
		if(strchr(value[i], 'u') != NULL){
			unsignedInteger(value[i],byteOrdering,output_file);
		}
		else if(strchr(value[i], '.') != NULL){
			floatingPoint(value[i],byteOrdering,floatingPointSize,output_file);
		}else{
			signedInteger(value[i],byteOrdering,output_file);
		}
		i++;
	}
	
    fclose(output_file);
	fclose(inputFile);
}
