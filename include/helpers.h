#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>

class Helpers {
public:
	static std::string lowerString(std::string str){
		int len = (int) str.length();
		for (int i = 0; i < len; ++i){
			str[i] = tolower(str[i]);
		}

		return str;
	}

	static int randomPercentage(){
		return rand() % 100 + 1;
	}
};

#endif
