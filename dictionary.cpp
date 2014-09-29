/*
 * @Author: Jeff Berube
 * @Title: Dictionary (Assigment #1)
 *
 * @Description: Takes a stream of characters as input and outputs every unique word with its frequency.
 *
 */


#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;

#define MAX_WORD_LEN 132
#define MAX_ROWS 10

char dictionary[MAX_ROWS][MAX_WORD_LEN] = {0};
int freq[MAX_ROWS] = {0};

int dic_col = 0, ptr = 0;

int str_len(char *string) {
	
	int i = 0;

	while (*string++) i++;

	return i;

}

/*
 * str_cmp
 * 
 * Compares two strings. Takes 2 char pointers.
 *
 */

int str_cmp(char *string1, char *string2) {

	int i = 0;

	if (str_len(string1) != str_len(string2)) return 0;
	else {
		
		while (*string1++ != 0 && *string2++ != 0 && *string1 == *string2) i++;
	
		return i == str_len(dictionary[ptr]) ? 1 : 0;
	}
}

/*
 * str_search
 * 
 * Search for string in table
 *
 */

int str_search(char *string) {
	
	/* Create temporary pointer */
	int tmp_ptr = 0;

	/* Iterate through dictionary */
	while (tmp_ptr < ptr) {
		
		if (str_cmp(dictionary[tmp_ptr], dictionary[ptr])) break;
		tmp_ptr++;

	}

	return tmp_ptr == ptr ? tmp_ptr : -1;	

}

/*
 * dump
 *
 * Dumps dictionary
 *
 */

void dump() {

	cout << endl << "Word\t\t\tFrequency" << endl;
	cout << "----------------------------------" << endl << endl;

	int tmp_row = 0, tmp_col = 0;

	while (tmp_row < ptr) {

		cout <<  freq[tmp_row] << "\t\t";
		
		tmp_col = 0;

		while (tmp_col < str_len(dictionary[tmp_row]))
			cout << dictionary[tmp_row][tmp_col++];
		
		cout << endl;

	}

}



int main() {

	/* Define variables */
	char ch;
	int newline = 0;

	/* Read input */

	while(cin.good())
	{
		ch = cin.get();

		if(isalpha(ch)) {

			/* DICTIONARY ADD */				
			int index;

			if ((index = str_search(dictionary[ptr])) == -1) freq[ptr++];
			else freq[index]++; 
			newline = 1;	

		} else if (newline) {

			newline = 0;
		}
	}

	dump();
	return 0;

}
