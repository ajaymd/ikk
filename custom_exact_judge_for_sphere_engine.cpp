// C++ (5.1.1)

#include "spoj.h"
#include <stdlib.h>

using namespace std;

/* <0-255> normal, -2 eof */
int getChar(FILE *f) {
	int ch;
	if ((ch = getc(f))==EOF) return -2;
	return ch;
}

int main(void) {
	spoj_init();
	int ch1 = getChar(spoj_t_out);
	int ch2 = getChar(spoj_p_out);
	while (ch1 == ch2) {
		if (ch1==-2) return (SPOJ_RV_POSITIVE);
		ch1 = getChar(spoj_t_out);
		ch2 = getChar(spoj_p_out);
	};
	
	// If one of the files, has extra '\n' at the end, then also consider it as a valid output.
	if (ch1 == -2 && ch2 == '\n'){
		while(ch2 == '\n'){
			ch2 = getChar(spoj_p_out);
		}
		if (ch2 == -2){
			return SPOJ_RV_POSITIVE;
		}
	}
	else if (ch2 == -2 && ch1 == '\n'){
		while(ch1 == '\n'){ 
			ch1 = getChar(spoj_t_out);
		}
		if (ch1 == -2){
			return SPOJ_RV_POSITIVE;
		}
	}
	
	return SPOJ_RV_NEGATIVE;
}