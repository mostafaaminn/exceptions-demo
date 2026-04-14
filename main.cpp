#include <iostream> 
#include <string> 
#include <stdexcept> 

#include "utils.hpp" 

int main() { 
	std::string email;

	while(true) { 
		std::cout << "enter your email address: ";
		std::getline(std::cin, email);

	try {
		check_email(email);
		std::cout << "valid email entered. \n";
		break;
	} catch (const std::invalid_argument& e) {
		std::cout << e.what() << "\n";
		std::cout << "please try again. \n";
	}
}
	return 0;
}
