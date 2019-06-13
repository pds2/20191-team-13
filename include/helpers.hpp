#pragma once
#include <iostream>
#include <ctime>

class Helpers {
public:
	static std::string lowerString(std::string str){
		int len = (int) str.length();
		for (int i = 0; i < len; ++i){
			str[i] = tolower(str[i]);
		}

		return str;
	}

	static std::string upperString(std::string str){
		int len = (int) str.length();
		for (int i = 0; i < len; ++i){
			str[i] = toupper(str[i]);
		}

		return str;
	}

	static int easyRandom(int n){
		return rand() % n + 1;
	}

	static void waitForKey(){
		std::cout << "pressione Enter para continuar..." << std::endl;
		std::cin.get();
		std::cin.get();
	}
};
