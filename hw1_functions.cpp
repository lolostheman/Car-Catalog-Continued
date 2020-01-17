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
#include "hw1.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

/* function to swap two part structures - passed by reference */
/*void swap_parts(struct part *part_a, struct part *part_b)
{
	struct part temp_part;

	temp_part.part_no = part_a->part_no;
	temp_part.price = part_a->price;
	strcpy(temp_part.description,part_a->description);
	temp_part.source.part_no = part_a->source.part_no;
	strcpy(temp_part.source.dealer,part_a->source.dealer);

	part_a->part_no = part_b->part_no;
	part_a->price = part_b->price;
	strcpy(part_a->description,part_b->description);
	part_a->source.part_no = part_b->source.part_no;
	strcpy(part_a->source.dealer,part_b->source.dealer);

	part_b->part_no = temp_part.part_no;
	part_b->price = temp_part.price;
	strcpy(part_b->description,temp_part.description);
	part_b->source.part_no = temp_part.source.part_no;
	strcpy(part_b->source.dealer,temp_part.source.dealer);


}*/

void print_catalog(vector<part> &list, int num_parts)
{
	int i;

	cout<<"\tCatalog\n";
	cout<<"Part no.\tDescription\tPrice\n";
	cout<<"----------------------------------------\n";

	for(i=1;i<num_parts;i++)
		cout<<"%d\t%s\t%.2f\n",list[i].part_no, list[i].description,
		                    list[i].price;

	cout<<"\n\n";


}

void print_full_catalog(vector<part> &list, int num_parts)
{
	int i;

	cout<<"\tFull Catalog including supplier\n";
	cout<<"Part no.    Description\t\tPrice\t  Supplier\tManu. Part No.\n";
	cout<<"-------------------------------------------------------------------------\n";

	for(i=1;i<num_parts;i++)
	cout<<list[i].part_no<<"\t"<< list[i].description<<"\t"<<
		                    list[i].price<<"\t  "<< list[i].source.dealer<<"\t\t"<< list[i].source.part_no<<"\n";

	cout<<"\n\n";


}
bool sortByPart_no(const part &lhs, const part &rhs){return lhs.part_no < rhs.part_no; }
bool sortByPrice(const part &lhs, const part &rhs){return lhs.price < rhs.price; }
bool sortByManufacture_no(const part &lhs, const part &rhs){return lhs.source.part_no < rhs.source.part_no; }

void sort_catalog(vector<part> &part_list, int num_parts, int type)
{
	if(type==BY_PARTS){ sort(part_list.begin(), part_list.end(), sortByPart_no); }
	if(type==BY_PRICE){ sort(part_list.begin(), part_list.end(), sortByPrice); }
	if(type==BY_manu){ sort(part_list.begin(), part_list.end(), sortByManufacture_no); }	
}
