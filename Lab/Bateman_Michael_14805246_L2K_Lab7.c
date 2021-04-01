/*
 * Author:           Michael Bateman
 * Student Number:   14805246
 * Lab Section:      L2K
 * Date:             4/1/2021 1:49:26 PM
 * Email:			 mikeb8ma@student.ubc.ca
 *           
 * Purpose:  Simple counter program that counts down by increments and displays it on the DAQ simulator 4.
 *
 */

#define _CRT_SECURE_NO_WARNINGS

/* INCLUDE STATEMENTS */

#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>

/* CONSTANTS */

#define TRUE     1
#define FALSE    0
#define ON       1
#define OFF      0
#define SWITCH1 1

/* DAQ SIMULATOR */

#define DAQ_SIMULATOR 4

/* FUNCTION PROTOTYPE */

void runProgram(int initial_value, int final_value);

/* MAIN FUNCTION */

int main(void) {

	// Variables

	int start_number;
	int end_number;

	// Taking our two inputs

	printf("Enter a counter start value: ");
	scanf("%d", &start_number);

	printf("Enter a counter end value: ");
	scanf("%d", &end_number);

	//Attempting to get the DAQ simulator going, if it works, great, if not, it prints an error message

	if (setupDAQ(DAQ_SIMULATOR) == TRUE) {
		runProgram(start_number, end_number);
	}
	else {
		printf("ERROR: failed to initialize DAQ\n");
	}

	return 0;
}

/* PROGRAM FUNCTION */

void runProgram(int initial_value, int final_value) {
	
	// Variables

	int value = initial_value;
	int to_print;
	int increment = ((4+6)%3)+2;
	int count;
	int digits_table[] = { 252, 96, 218, 242, 102, 182, 190, 224, 254, 246 };

	// This part of the function is the display section
	while (continueSuperLoop()) {

		// If statement to check if the switch is pressed

		if (digitalRead(SWITCH1) == ON) {

			// Checking to make sure we do not go past the final value

			if ((value - increment) >= final_value) {

				// Lines 90 to 98 are responsible for writing the digits on the DAQ

				value = value - increment;
				count = 0;
				to_print = value;
				while (value > 0 && count < 8) {
					displayWrite(digits_table[to_print % 10], count);
					to_print = to_print / 10;
					count++;
				}

				// We now delay by increment (s)
				delay(increment * 1000);
			}
		}

		// If the button is not turned to position "ON", we execute the following

		else {

			// Variables

			count = 0;
			to_print = value;

			// We write the value on the screen

			while (value > 0 && count < 8) {
				displayWrite(digits_table[to_print % 10], count);
				to_print = to_print / 10;
				count++;

			}
		}
	}
}

