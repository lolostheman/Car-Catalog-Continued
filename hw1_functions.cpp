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

using namespace std;

/* function to swap two part structures - passed by reference */
void swap_parts(struct part *part_a, struct part *part_b)
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


}

void print_catalog(struct part list[], int num_parts)
{
	int i;

	cout<<"\tCatalog\n";
	cout<<"Part no.\tDescription\tPrice\n";
	cout<<"----------------------------------------\n";

	for(i=0;i<num_parts;i++)
	cout<<"%d\t%s\t%.2f\n",list[i].part_no, list[i].description,
		                    list[i].price;

	cout<<"\n\n";


}

void print_full_catalog(struct part list[], int num_parts)
{
	int i;

	cout<<"\tFull Catalog including supplier\n";
	cout<<"Part no.    Description\t\tPrice\t  Supplier\tManu. Part No.\n";
	cout<<"-------------------------------------------------------------------------\n";

	for(i=0;i<num_parts;i++)
	cout<<list[i].part_no<<"\t"<< list[i].description<<"\t"<<
		                    list[i].price<<"\t  "<< list[i].source.dealer<<"\t\t"<< list[i].source.part_no<<"\n";

	cout<<"\n\n";


}

void sort_catalog(struct part list[], int num_parts, int price_or_parts)
{
	int i,j, tempx,tempy, size;
	int smallest, smallest_index;
	float cheapest;
	struct part temp_part;


	if(price_or_parts == BY_PARTS) {
		/* insertion sort */
		/* outer loop - go through loop once */
		for(i=0;i < num_parts;i++) {
			/* inner loop - go through from i until end */
			/* find smallest element in that section */
			smallest = list[i].part_no;
			smallest_index = i;
			for(j=i;j < num_parts; j++)
				if(list[j].part_no < smallest) {
					smallest = list[j].part_no;
					smallest_index = j;
				}
			/* found smallest, swap */
			swap_parts(&list[i], &list[smallest_index]);
		} /* end for */
	} /* end if */

	else if(price_or_parts == BY_PRICE) {
		/* insertion sort */
		/* outer loop - go through loop once */
		for(i=0;i < num_parts;i++) {
			/* inner loop - go through from i until end */
			/* find smallest element in that section */
			cheapest = list[i].price;
			smallest_index = i;
			for(j=i;j < num_parts; j++)
				if(list[j].price < cheapest) {
					cheapest = list[j].price;
					smallest_index = j;
			}
			/* found smallest, swap */
			swap_parts(&list[i], &list[smallest_index]);
		} /* end for */
	} /* end else if */
	else if(price_or_parts == BY_manu){
		for(i=0;i <num_parts; i++){
			cheapest = list[i].source.part_no;
			smallest_index = i;
			for(j=i; j < num_parts; j++)
				if(list[j].source.part_no < cheapest){
					cheapest = list[j].source.part_no;
					smallest_index = j;
				}
			swap_parts(&list[i], &list[smallest_index]);
		}
	}

}
