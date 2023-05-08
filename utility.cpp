#include "utility.h"
int mod(int num, int limit){
	return num%limit >= 0 ? num%limit : limit+num;

}

