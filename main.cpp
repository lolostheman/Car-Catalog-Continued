/******************************************************************
 * Program #: Homework #4
 *
 * Programmer: Logan Morro
 *
 * file: main.cpp
 *
 * Due Date: 3/29/2020
 *
 * EGRE 491, Spring 2020       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: This is the main function prints and reads files mostly
 *
 * Input: the name of the txt document that has the catalog information
 *
 * Output: the catalot.txt sorted in different ways
 *
 ******************************************************************/

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "hw4.h"

using namespace std;

void print_full_catalog(vector<part> &list, int num_parts);
void print_catalog(vector<part> &list, int num_parts);
void sort_catalog(vector<part> &list, int num_parts, int price_or_parts);

int main()
{
	FILE *infile = NULL;
	string  infilename;
	char line[MAXCHAR];
	vector<part> part_list;
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
	//this loop starts to build the vector untill the file reaches the end. the vector contains
	//elements that are part structs.
	while(! myfile.eof()){
		part_list.push_back(part());
	       myfile>>part_list[i].part_no;
	       myfile>> part_list[i].description;
	       myfile>>part_list[i].price;
	       myfile>> part_list[i].source.dealer;
	       myfile>>part_list[i].source.part_no;
	      // cout<<part_list[i].part_no<<" ";
		i++;
		if(i > NO_OF_PARTS) {
			printf("ERROR, number of parts in catalog is greater than list size!\n");
			exit(0);
		}
	}
	part_list.erase(part_list.end()-1);
	num_of_parts = i;

	print_full_catalog(part_list, num_of_parts);		// print as read

	sort_catalog(part_list, num_of_parts, BY_PARTS);	// sort by part number

	print_full_catalog(part_list, num_of_parts);				// print sorted by part number

	sort_catalog(part_list, num_of_parts, BY_PRICE);	// sort by price

	print_full_catalog(part_list, num_of_parts);				// print sorted by price number

	sort_catalog(part_list, num_of_parts, BY_manu); //sort by maufacture

	print_full_catalog(part_list, num_of_parts); //prints maunfacture sorted list

	

}		/* end main */
