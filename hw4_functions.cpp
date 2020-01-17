/******************************************************************
 * Program #: Homework #4
 *
 * Programmer: Logan Morro
 *
 * Due Date: 3/29/2020
 *
 * EGRE 491, Spring 2020       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: Program to demonstrate makefiles
 *
 * Input: all the functions take in a vector that contains all the parts, and take in the variable num_parts which cotains the amount of parts as an int.
 *
 * Output: No direct output, however the print functions do cout the catalog parts. *
 ******************************************************************/


#include <cstring>
#include "hw4.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


//void print_catalog(vector<part> &list, int num_parts)
//this function isnt called in out main.cpp.
//input: a vector containing the parts list, and an int containing the number of parts
//output: this function couts the part numbers, part descriptions, and part price.
void print_catalog(vector<part> &list)
{
	int i;

	cout<<"\tCatalog\n";
	cout<<"Part no.\tDescription\tPrice\n";
	cout<<"----------------------------------------\n";

	for(i=0;list.size();i++)
		cout<<"%d\t%s\t%.2f\n",list[i].part_no, list[i].description,
		                    list[i].price;
	cout<<"\n\n";
}


//void print_full_catalog(vector<part> &list, int num_parts)
//this function prints the full catalog(part number, description, price, manufactor name, and manufactor part number)
//input: a vector containing the whole part list and an int that contains the number of parts
//output: this function couts the whole catalog
void print_full_catalog(vector<part> &list)
{
	int i;

	cout<<"\tFull Catalog including supplier\n";
	cout<<"Part no.    Description\t\tPrice\t  Supplier\tManu. Part No.\n";
	cout<<"-------------------------------------------------------------------------\n";

	for(i=0;i<list.size();i++)
	cout<<list[i].part_no<<"\t"<< list[i].description<<"\t"<<
		                    list[i].price<<"\t  "<< list[i].source.dealer<<"\t\t"<< list[i].source.part_no<<"\n";
	cout<<"\n\n";
}


//all the bool function below are comparison functions for our part structure
//we have comparison functions for the part number, part price, and manufacture number
bool sortByPart_no(const part &lhs, const part &rhs){return lhs.part_no < rhs.part_no; }
bool sortByPrice(const part &lhs, const part &rhs){return lhs.price < rhs.price; }
bool sortByManufacture_no(const part &lhs, const part &rhs){return lhs.source.part_no < rhs.source.part_no; }


//void sort_catalog(vector<part> &part_list, int num_parts, int type)
//this function sorts the part_list based on t he type of sort passed. the type of sort passed is saved into the variable type as an int.
//input: a vector containg the whole part list and the type of sort we will be doing (BY_PARTS,BY_PRICE,BY_manu)
//output: no output just sorts the vectors.
void sort_catalog(vector<part> &part_list, int type)
{
	if(type==BY_PARTS){ sort(part_list.begin(), part_list.end(), sortByPart_no); }
	if(type==BY_PRICE){ sort(part_list.begin(), part_list.end(), sortByPrice); }
	if(type==BY_manu){ sort(part_list.begin(), part_list.end(), sortByManufacture_no); }	
}
