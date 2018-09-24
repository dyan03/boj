#include <stdio.h>
#include <stdlib.h>

int isRow(char** map,int size) {
	int i, j;
	int count=0;
	int numRow = 0;
	
	for (i = 0; i < size; ++i) {
		count = 0;
		for (j = 0; j < size; ++j) {
			if (map[i][j] == '.') {
				if (++count == 2) {
					numRow++;
					
				}
				else if (count > 2) {
					continue;
				}

			}else{
				count = 0;
			}
		}
	}
	return numRow;
}

int isCol(char** map, int size) {
	int i, j;
	int count = 0;
	int numCol = 0;

	for (i = 0; i < size; ++i) {
		count = 0;
		for (j = 0; j < size; ++j) {
			if (map[j][i] == '.') {
				if (++count == 2) {
					numCol++;
				}
				else if (count > 2) { continue; }

			}
			else{
				count = 0;
			}
		}
	}
	return numCol;
}

int main() {

	char** map;
	int size;
	int i, j;

	scanf("%d", &size);
	map = (char**)malloc(sizeof(char*)*(size));
	
	for (i = 0; i < size; i++) {
		map[i] = (char*)malloc(sizeof(char)*(size));
	}

	for (i = 0; i < size; i++) {
	
		for (j = 0; j < size; j++) {
			scanf(" %c", &map[i][j]);
		}
		
		
	}

	printf("%d %d", isRow(map, size) , isCol(map, size));


	return 0;
}


