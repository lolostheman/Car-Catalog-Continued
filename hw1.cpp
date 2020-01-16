/******************************************************************
 * Program #: Homework #1
 *
 * Programmer: Logan Morro
 *
 * Due Date: 2/10
 *
 * EGRE 491, Spring 2020       Instructor: Robert Klenke
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

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "hw1.h"

using namespace std;

void print_full_catalog(struct part list[], int num_parts);
void print_catalog(struct part list[], int num_parts);
void sort_catalog(struct part list[], int num_parts, int price_or_parts);

int main()
{
	FILE *infile = NULL;
	string  infilename;
	char line[MAXCHAR];
	struct part part_list[NO_OF_PARTS];
	int num_of_parts, i = 0;

	cout<<"Program to read in a part catalog from a file \n";

	/* input file name to read and try and open it */
	int x=0;
	while(x==0) {
		cout<<"Input catalog filename: ";
		cin>>infilename;
		cout<<"\n\n";
		ifstream myfile;
		myfile.open(infilename.c_str(), ios::in);
	//	infile = myfile;
		if(!myfile) {
			cout<<"ERROR: file "<<infilename<<" can not be opened!\n";
			x=0;
		}else{
			x=1;
			myfile.close();
		}
	}

	ifstream myfile (infilename);
	while(! myfile.eof()){
	       myfile>>part_list[i].part_no;
	       myfile>> part_list[i].description;
	       myfile>>part_list[i].price;
	       myfile>> part_list[i].source.dealer;
	       myfile>>part_list[i].source.part_no;
	       cout<<part_list[i].part_no<<" ";
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
