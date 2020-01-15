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

const int  DESC_SIZE = 40;		// maximum size of part description
const int  NO_OF_PARTS = 10;		// maximum number of parts in our extensive catalog
const int  MAXCHAR = 256;		// maximum characters in the file name

const int BY_PRICE = 2;
const int BY_PARTS = 3;


struct supplier {
	int part_no;
	char dealer[DESC_SIZE];
};

struct part {
	int part_no;
	float price;
	char description[DESC_SIZE];
	struct supplier source;
};

