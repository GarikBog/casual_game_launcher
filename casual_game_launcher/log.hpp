#ifndef STRING
#include<string>
#define STRING
#endif // !STRING

#ifndef STACK
#include<stack>
#define STACK
#endif // !STACK

#ifndef VECTOR
#include<vector>
#define VECTOR
#endif // !VECTOR



class Request {
private:
	std::string command = "";
	std::vector<std::string> arguments;

public:
	
	Request(std::string command);
	Request(std::string command, std::vector<std::string> args);
	Request(std::pair< std::string, std::vector < std::string>>);


	std::pair< std::string, std::vector < std::string>> data();
};


class Log {
private:
	std::stack<Request> requests;

public:


	void add(Request request);
	
	std::pair < std::string, std::vector<std::string>> get_request();
	

};