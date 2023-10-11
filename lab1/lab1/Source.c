﻿/*. Napisati program koji prvo procita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamicki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i ucitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrzi ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100*/


#include <stdio.h>
#define MAX_SIZE 50
#define MAX_LINE 1024

typedef struct _student {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;
}Student;

int main(){

	int noRows = 0;

	FILE *filePointer = NULL;

	char buffer[MAX_LINE] = { 0 };

	filePointer = fopen("students.txt", "r");
	if (!filePointer) {
		printf("File is not open!\n");

		return -1;
	}

	while (!feof(filePointer)) {
		fgets(buffer, MAX_LINE, filePointer);
		noRows++;
	}

	printf("%d", noRows);

	fclose(filePointer);
	return 0;
}