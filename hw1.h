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

#define DESC_SIZE	40		// maximum size of part description
#define NO_OF_PARTS	10		// maximum number of parts in our extensive catalog
#define MAXCHAR		256		// maximum characters in the file name

#define	BY_PRICE	2
#define	BY_PARTS	3


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

