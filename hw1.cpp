/******************************************************************
 * Program #: Homework #1
 *
 * Programmer: Robert H. Klenke
 *
 * Due Date: NA
 *
 * EGRE 347, Spring 2020       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: Program to demonstrate makefiles
 *
 * Input: NA
 *
 * Output: print statements showing the results.
 *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "hw1.h"

void print_full_catalog(struct part list[], int num_parts);
void print_catalog(struct part list[], int num_parts);
void sort_catalog(struct part list[], int num_parts, int price_or_parts);

int main()
{
	FILE *infile = NULL;
	char infilename[MAXCHAR];
	char line[MAXCHAR];
	struct part part_list[NO_OF_PARTS];
	int num_of_parts, i = 0;

	printf("Program to read in a part catalog from a file \n");

	/* input file name to read and try and open it */
	while(infile == NULL) {
		printf("Input catalog filename: ");
		scanf("%s",infilename);
		printf("\n\n");
		if((infile = fopen(infilename, "r")) == NULL) {
			printf("ERROR: file %s can not be opened!\n",infilename);
		}
	}

	while(fscanf(infile,"%d %s %f %s %d\n", &part_list[i].part_no, part_list[i].description,
		                              &part_list[i].price, part_list[i].source.dealer,
									  &part_list[i].source.part_no) != EOF) {
		i++;
		if(i > NO_OF_PARTS) {
			printf("ERROR, number of parts in catalog is greater than list size!\n");
			exit(0);
		}
	}

	num_of_parts = i;

	print_full_catalog(part_list, num_of_parts);		// print as read

	sort_catalog(part_list, num_of_parts, BY_PARTS);	// sort by part number

	print_full_catalog(part_list, num_of_parts);				// print sorted by part number

	sort_catalog(part_list, num_of_parts, BY_PRICE);	// sort by price

	print_full_catalog(part_list, num_of_parts);				// print sorted by price number


}		/* end main */
