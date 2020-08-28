#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "BST.h"
#define SIZE 1000
static Student list[SIZE];

   
// readFile function:
// Reads a CSV text file of students with four fields:
// Last name,first name,ID,GPA
// 'fileName' is the name of the text file to read.
// Returns the number of lines read, or -1 on errors.
int readFile(const char fileName[]) {
    FILE *fptr;
    int lines = 0;

    if ((fptr = fopen(fileName, "r")) == NULL) {
        fprintf(stderr, "Error, failed to open %s: ", fileName);
        perror("");
        return -1;
    }
	
    char lastName[NAME_STR_LEN];
    char firstName[NAME_STR_LEN];
    long int ID;
    double GPA;
    
    while (feof(fptr) == 0) {
        // Read all fields from one line in the file into temporary variables
		// Assumes fields are separated by commas
        fscanf(fptr, "%39[^,],", lastName);
        fscanf(fptr, "%39[^,],", firstName);
        fscanf(fptr, "%ld,", &ID);
        fscanf(fptr, "%lf ", &GPA);


		strcpy(list[lines].lastName, lastName); //copy input of lastname to structure
		strcpy(list[lines].firstName, firstName); //copy input of firstname to structure
		list[lines].ID = ID; //copy input of ID to structure
		list[lines].GPA = GPA; //copy input of GPA to structure
		
        lines++;
    }

    return lines;
}

int cmpfunc(const void* a, const void* b) {
	double gpaA = ((Student*)a)->GPA;  // Get the GPA of item 'a'
    double gpaB = ((Student*)b)->GPA;  // Get the GPA of item 'b'
    if (gpaA == gpaB) {
    	return 0;
	}
	else if (gpaA < gpaB) {
		return 1;
	}
	else {
		return -1;
	}
}

int main(int argc, char** argv) {
	TreeNode* root;
	int i;
	int newSize = 50; // new size to print out 50 entries 
	double sortedGPA[SIZE];
	
    int lines = readFile("StudentList.txt");
    
    if (lines <= 0) {
    	printf("Quitting due to error or empty file.\n");
		return 1;
	}
	
    printf("\n%d lines read from the file.\n", lines);
    

	
	qsort(list,lines,sizeof(Student),cmpfunc); // qsort to sort GPA in decending order
	for(i=0;i<newSize;i++) {
    	printf("%s, %s, %d, %lf\n",list[i].lastName,list[i].firstName,list[i].ID,list[i].GPA); // print only 50 Student entries 	
	}
	printf("\n");	
	for(i=0;i<lines;i++){
		sortedGPA[i]= list[i].GPA; //Array og GPA values
	}

	root = rootInsert(sortedGPA,0,lines-1); //get root of sorted GPA
	inOrder(root); // print tree using in-order traversal
	printf("\n\nThe root of tree: %lf\n",root->data.num); // value at the root of the tree	
	
	TreeNode* node = search(root, 3.2204); //serach value in tree using BST
    if (node == NULL) {
    	printf("\nNumber was NOT found\n"); // when Number is not in tree
	}
	else {
    	printf("\nNumber was found\n");	// when number is in tree
	}
    return 0;	
}
