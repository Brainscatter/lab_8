// lab_8.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <string.h>
#include <malloc.h>
#include <stdio.h>

char* inputString(int strNum) {
	char inStr[1000];
	char* str;

	printf("please, input the %d string: ", strNum);
	scanf("%s", &inStr);
	str = (char*)malloc(strlen(inStr) * sizeof(char) + 1);
	strcpy(str, inStr);

	return str;
}

void printOperations(){
	printf("select operation, wich you need:\n");
	printf("	1. Strings concatenation\n");
	printf("	2. Concatenation of string and first n symbols of the second string\n");
	printf("	3. Compare 2 strings\n");
	printf("	4. Compare first n symbols from strings\n");
	printf("	5. Copy second string into the first\n");
	printf("	6. Copy first n symbols from second string into the first\n");
	printf("	7. Get lenght of the string\n");
	printf("	8. Find the first occurrance of symbol in the string\n");
	printf("	9. Find the last occurrance of symbol in the string\n");
	printf("	10. Find the anyone symbol from second string into first\n");
	printf("	11. Get lenght of first string, wich conclude symbols from second string\n");
	printf("	12. Get lenght of first string, wich not conclude symbols from second string\n");
	printf("	13. Select from the single line the tokens (pieces), separated by any of the set of symbols (delimiters) entering the second line\n\n");
}

int main(){
	char* strFirst;
	char* strSecond;
	char* strFinal;
	int choiceOperation;
	int amountSymbols;
	int counter;
	int counterSecond;
	int symbolCounter;
	int symCheck;
	char sym;
	

	printOperations();
	printf("enter the number of operation: ");
	scanf("%d", &choiceOperation);

	if ((choiceOperation < 1) || (choiceOperation > 13)) {
		printf("wrong variant");
		strFirst = " ";
		strSecond = " ";
	}
	else{
		if ((choiceOperation > 6) && (choiceOperation < 10)) {
			strFirst = inputString(1);
			strSecond = " ";
		}
		else {
			strFirst = inputString(1);
			strSecond = inputString(2);
		}
	}


	switch (choiceOperation) {
		case 1: {
			strFinal = (char*)malloc((strlen(strFirst) + strlen(strSecond)) * sizeof(char) + 1);
			strcpy(strFinal, strFirst);
			strcat(strFinal, strSecond);
			printf("concatenation of the strings is: %s\n", strFinal);
			free(strFinal);
			break;
		}
		case 2: {
			printf("enter the amount of symbols: ");
			scanf("%d", &amountSymbols);
			strFinal = (char*)malloc((strlen(strFirst) + amountSymbols) * sizeof(char) + 1);
			strcpy(strFinal, strFirst);
			strncat(strFinal, strSecond, amountSymbols);
			printf("Concatenation of string and first n symbols of the second string: %s\n", strFinal);
			free(strFinal);
			break;
		}
		case 3: {
			switch (strcmp(strFirst, strSecond)) {
				case -1: 
					printf("first string > second string\n");
					break;
				case 0: 
					printf("first string = second string\n");
					break;
				case 1: 
					printf("first string < second string\n");
					break;
				default: 
					printf("sorry, there is some problems in my programm");
					break;
			}
		}
		case 4: {
			printf("enter the amount of symbols: ");
			scanf("%d", &amountSymbols);
			switch (strncmp(strFirst, strSecond, amountSymbols)) {
				case -1:
					printf("first %d symbols from first string > first %d symbols from second string\n", amountSymbols, amountSymbols);
					break;
				case 0:
					printf("first %d symbols from first string = first %d symbols from second string\n", amountSymbols, amountSymbols);
					break;
				case 1:
					printf("first %d symbols from first string < first %d symbols from second string\n", amountSymbols, amountSymbols);
					break;
				default:
					printf("sorry, there is some problems in my programm");
					break;
			}
		}
		case 5: {
			printf("%s\n", strcpy(strFirst, strSecond));
			break;
		}
		case 6: {
			printf("enter the amount of symbols: ");
			scanf("%d", &amountSymbols); 
			printf("%s\n", strncpy(strFirst, strSecond, amountSymbols));
		}
		case 7: {
			printf("the lenght of the string: %d\n", strlen(strFirst));
		}
		case 8: {
			printf("enter the symbol, wich you want to find: ");
			scanf(" %c", &sym);
			strFinal = strchr(strFirst, (int)(sym));
			printf("first position of your symbol is: %d\n", strlen(strFirst) - strlen(strFinal) + 1);
			break;
		}
		case 9: {
			printf("enter the symbol, wich you want to find: ");
			scanf(" %c", &sym);
			strFinal = strrchr(strFirst, (int)(sym));
			printf("last position of your symbol is: %d\n", strlen(strFirst) - strlen(strFinal) + 1);
			break;
		}
		case 10: {
			printf("enter the symbol, wich you want to find: ");
			scanf(" %c", &sym);
			symbolCounter = 0;
			symCheck = 0;
			for (counter = 0; counter < strlen(strSecond); counter++) {
				if (strSecond[counter] == sym) {
					symCheck = 1;
					counter = strlen(strSecond);
				}
			}
			if (symCheck == 1) {
				for (counter = 0; counter < strlen(strFirst); counter++) {
					if (strFirst[counter] == sym) {
						symbolCounter++;
					}
				}
				printf("there is %d '%c' symbol in the first string\n", symbolCounter, sym);
			}
			else {
				printf("there is no '%c' symbol in the second string\n", sym);
			}
			break;
		}
		case 11: {
			symbolCounter = 0;
			for (counter = 0; counter < strlen(strSecond); counter++) {
				for (counterSecond = 0; counterSecond < strlen(strFirst); counterSecond++) {
					if (strFirst[counterSecond] == strSecond[counter]) {
						symbolCounter++;
					}
				}
			}
			printf("the lenght of first string, wich conclude symbols from second string: %d\n", symbolCounter);
		}
		case 12: {
			symbolCounter = 0;
			for (counter = 0; counter < strlen(strSecond); counter++) {
				for (counterSecond = 0; counterSecond < strlen(strFirst); counterSecond++) {
					if (strFirst[counterSecond] == strSecond[counter]) {
						symbolCounter++;
					}
				}
			}
			printf("the lenght of first string, wich not conclude symbols from second string: %d\n", strlen(strFirst) - symbolCounter);
		}
		case 13: {
			printf("enter the symbol, wich you want to find: ");
			scanf(" %c", &sym);
			for (counter = 0; counter < strlen(strSecond); counter++) {
				if (strSecond[counter] == sym) {
					symCheck = 1;
					counter = strlen(strSecond);
				}
			}
			if (symCheck = 1) {
				for (counter = 0; counter < strlen(strFirst); counter++) {
					if (strFirst[counter] != sym) {
						printf("%c", strFirst[counter]);
					}
					else {
						if (strFirst[counter + 1] != sym) {
							printf("\n");
						}
					}
				}
			}
			else {
				printf("illegal symbol");
			}
			printf("\n");
		}
	}
	
	

    return 0;
}

