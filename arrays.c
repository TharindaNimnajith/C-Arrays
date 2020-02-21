


// *************************************************************************************************************
// *************************************************************************************************************


/*

   Author         : Tharinda Nimnajith Rajapakshe

   ID number	  : IT18149654

   University	  : Sri Lanka Institute of Information Technology (SLIIT) - Malabe 
		    (Faculty of Computing) 

   Course Details : BSc. (Honours) in Information Technology specialized in Software Engineering (SLIIT) 
		    Intake - 2018 Regular Late (05.02.2018)
   	            1st Year - 1st Semester - Group 5.2 (2018)
		    1st Year - 2nd Semester - Group 4.2 (2018)
 
   Module         : Introduction to Programming (IP) - IT1010	
 

   Written        : 12.05.2018
   Last Updated   : 10.07.2018 


   Helped by      : Ms.Disni Sriyarathne, Ayesh Lakshan, Tharindu Wickramanayake, Viraj Aiya,
		    Google, Quora & Stack Overflow 

		    (Thank you very much!)
			
*/


// *************************************************************************************************************
// *************************************************************************************************************



// *************************************************************************************************************
// *************************************************************************************************************


//Using arrays in C programming

//A program to enter marks, calculate average & display the output in a table


//Question:

/*

   Write a C program to enter name, ID number, marks of each student for each subject from the keyboard. 
   The number of students in the class and the number of subjects should also be given from the keyboard. 

   In case of an invalid input, the program should display an error message & ask the user to enter the 
   same input again and again until a valid input is entered.   

   1. Valid student ID number should contain 4 digits and should not begin with 0.
   2. Every student ID number should be unique.
   3. Valid mark should be an integer from 0 to 100.
   4. Number of students and the number of subjects should be positive integers.
   5. The name of a student should be less than 25 characters. 

   The program should display the name, ID number, marks for each subject, total marks & average of the 
   students in a table. The table should contain above details of all students. 

   Calculate the average mark of the class in the program and display it after the table.

   The ID numbers and names of the students who got the highest & lowest should be calculated and printed.

   The students whose average is equal or higher than the average of the class are considered to be passed 
   the exam, while others are considered to be failed and should sit for the exam again. Display the number
   of students who passed the exam and the number of students who failed the exam. Further display the id 
   numbers and names of the students who passed and failed the exam in two different lists. 	

   Hints: 
     1. Use arrays to store the data.
     2. Use for loops for inputting, reading, calculating & outputting the data in the program. 
     3. You can also use structures in your program (not compulsory). 

*/


// *************************************************************************************************************
// *************************************************************************************************************



// *************************************************************************************************************
// *************************************************************************************************************


//Answer:


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define SIZE 25
#define SIZE1 42
#define SIZE2 2


//function main begins the program execution

int main (void)

{	
	//printing 2 * lines

	int no, num;

	puts( "" );

	//Note: SIZE1 indicates the number of *s in one row.
	//Note: SIZE2 indicates the number of * rows.

	for ( num = 1; num <= SIZE2; num++ ) 
	{
		for ( no = 1; no <= SIZE1; no++ )
		{
			printf( " *" );
		}

		puts( "" );
	}

	
// *************************************************************************************************************


	//inputs

	int students, subjects;

	printf( "\n  Enter the number of students: " );
	scanf( "%d", &students );	

	while ( students <= 0 ) 
	{
		printf( "\n\t ***ERROR - Invalid number of students! Please try again..*** \n\n" );

		printf( "\n  Enter the number of students: " );
		scanf( "%d", &students );
	}

	printf( "\n  Enter the number of subjects: " );
	scanf( "%d", &subjects );

	while ( subjects <= 0 ) 
	{
		printf( "\n\t ***ERROR - Invalid number of subjects! Please try again..*** \n\n" );

		printf( "\n  Enter the number of subjects: " );
		scanf( "%d", &subjects );
	}

	//Note: The program gives optimal output format only if the above input is 3.

	printf( "\n\n  Enter name, id number & the marks of each student down below: \n\n" );

	int count, counter, length, number;
	int marks[students][subjects];
	int id[students];
	char name[students][SIZE]; 

	//Note: The strings (names of each student) are taken as an char array that is a 
	//Note: SIZE is defined as 25. Therefore limit the name to 25 or less characters.
	//Note: The program gives the optimal output if the user inputs a name with 24 or less characters.
	//Note: A name can't include spaces.

	for ( count = 0; count < students; count++ ) 
	{
		printf( "\n  Index no: %2d \n\n", count + 1 );

		printf( "\t Student Name      : " );
		scanf( "%s", name[count] );

		length = strlen ( name[count] );

		while ( length >= SIZE ) 
		{
			printf( "\n\t ***ERROR - Student name is too long! Please try again..*** \n\n\n" );

			printf( "\t Student Name      : " );
			scanf( "%s", name[count] );

			length = strlen ( name[count] );
		}

		printf( "\t Student ID number : " );
		scanf( "%d", &id[count] );		

		while ( id[count] < 1000 || id[count] > 9999 ) 
		{
			printf( "\n\t ***ERROR - Invalid ID number! Please try again..*** \n\n\n" );

			printf( "\t Student ID number : " );
			scanf( "%d", &id[count] );		
		}
	
		for ( number = 0; number < count; number++ ) 
		{
			while ( id[count] == id[number] ) 
			{
				printf( "\n\t ***ERROR - This ID number has been used once already!*** \n" );
				printf( "\t ***Please try again..*** \n\n\n" );

				printf( "\t Student ID number : " );
				scanf( "%d", &id[count] );
			}
		}

		puts( "" ); 
		
		for ( counter = 0; counter < subjects; counter++ ) 
		{ 
			printf( "\t Subject %2d : ", counter + 1 );
			scanf( "%d", &marks[count][counter] );

			while ( marks[count][counter] < 0 || marks[count][counter] > 100 ) 
			{
				printf( "\n\t ***ERROR - Invalid mark! Please try again..*** \n\n\n" );

				printf( "\t Subject %2d : ", counter + 1 );
				scanf( "%d", &marks[count][counter] );
			}
		}
	}

	printf( "\n\n" );


// *************************************************************************************************************


	//calculations


	//calculating & assigning total & average of each student into an array

	int tot, i, j;
	float avg;
	int total[students];
	float average[students];

	for ( i = 0; i < students; i++ ) 
	{
		tot = 0;

		for ( j = 0; j < subjects; j++ ) 
		{
			tot = tot + marks[i][j];
		}

		total[i] = tot;

		avg = (float) tot / subjects;

		average[i] = avg;
	} 
	

	//finding the student who got highest marks
	
	int highest, best, n;
	char bestName[SIZE];

	highest = total[0];
	best = id[0];
	strcpy ( bestName, name[0] );
	
	for ( n = 0; n < students; n++ )
	{
		if ( highest < total[n] ) 
		{
			highest = total[n];
			best = id[n];

			strcpy ( bestName, name[n] );
		}
	}


	//finding the student who got lowest marks

	int lowest, last, k;
	char lastName[SIZE];

	lowest = total[0];
	last = id[0];
	strcpy ( lastName, name[0] );

	for ( k = 0; k < students; k++ ) 
	{
		if ( lowest > total[k] ) 
		{
			lowest = total[k];
			last = id[k];

			strcpy ( lastName, name[k] );
		}
	}

	//Note: In case two students tie for first / last place, the program won't give the optimal output


	//calculating the average of the class

	int x;
	int classTotal = 0; 
	float classAverage;

	for ( x = 0; x < students; x++ ) 
	{
		classTotal = classTotal + total[x];
	}
		
	classAverage = (float) classTotal / ( students * subjects );


	//calculating the number of students who passed / failed the exam

	int y;
	int a = 0;
	int b = 0;

	for ( y = 0; y < students; y++ ) 
	{
		if ( average[y] >= classAverage ) 
		{
			a++;
		}
	
		else 
		{
			b++;
		}
	}


	//storing the ID numbers & names of passed / failed students into different arrays

	int z;
	int c = 0;
	int d = 0;
	int passed[a];
	int failed[b];
	char passedNames[a][SIZE];
	char failedNames[b][SIZE];

	for ( z = 0; z < students; z++ ) 
	{
		if ( average[z] >= classAverage )
		{
			passed[c] = id[z];

			strcpy ( passedNames[c], name[z] );

			c++;
		}	
	
		else 
		{
			failed[d] = id[z];

			strcpy ( failedNames[d], name[z] );

			d++;
		}
	}


// *************************************************************************************************************


	//output


	//printing * line
	
	for ( no = 1; no <= SIZE1; no++ ) 
	{
		printf( " *" );	
	}


	//printing the table

	printf( "\n\n\n  Summary of exam results of the class: \n\n" );

	printf( "\n   # \t Std_ID \t       Name \t\t   Marks \t Total \t Average \n\n" );
	
	int rows, columns;

	for ( rows = 0; rows < students; rows++ ) 
	{
		printf( "  %2d \t  ", rows + 1 );

		printf( "%d \t  ", id[rows] );

		printf( "%25s    ", name[rows] );

		for ( columns = 0; columns < subjects; columns++ ) 
		{
			printf( "%3d  ", marks[rows][columns] );
		}

		printf( "\t  %3d", total[rows] );

		printf( "\t %6.2f \n", average[rows] );
	}


	//printing other details

	printf( "\n\n  Number of Students   : %3d \n", students );
	printf( "  Number of Subjects   : %3d \n\n", subjects ); 
	
	printf( "  Average of the class : %.2f \n\n\n", classAverage );

	printf( "  ID number of the student who got highest marks : %d ( %s ) \n", best, bestName );
	printf( "  ID number of the student who got lowest marks  : %d ( %s ) \n\n\n", last, lastName );

	printf( "  Number of students who passed the exam : %d \n\n", a );

	printf( "  \t\t Name \t\t ID Number \n\n" );

	int p, q;

	for ( p = 0; p < a; p++ ) 
	{
		printf( "%25s \t   %d \n", passedNames[p], passed[p] );
	}
	
	printf( "\n\n  Number of students who failed the exam : %d \n\n", b );

	if ( b > 0 ) 
	{
		printf( "  \t\t Name \t\t ID Number \n\n" );

		for ( q = 0; q < b; q++ ) 
		{ 
			printf( "%25s \t   %d \n", failedNames[q], failed[q] );
		}	

		printf( "\n ***Students who failed are required to sit for the exam again*** \n\n\n" );
	}


	//printing 2 * lines

	for ( num = 1; num <= SIZE2; num++ ) 
	{
		for ( no = 1; no <= SIZE1; no++ ) 
		{
			printf( " *" );
		}

		puts( "" );
	}

	printf( "\n\n" );


	return 0;

} 

//end of function main


// *************************************************************************************************************
// *************************************************************************************************************


