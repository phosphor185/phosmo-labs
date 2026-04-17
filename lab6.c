#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fin, *fout;
	char fam[30], im[30], otch[30];
	int god;

	fin = fopen ("doc.txt", "r");
	fout = fopen ("res.txt", "w");

	while(fscanf(fin, "%30s %30s %30s %d", fam, im, otch, &god) == 4){
		if (god > 1980){
			fprintf(fout, "%s %s %s %d\n", fam, im, otch, god);
		}
}

	fclose(fin);
	fclose(fout);
	return 0;
	
}

//СОЗДАТЬ ФАЙЛ DOC.TXT С ФИОГ
