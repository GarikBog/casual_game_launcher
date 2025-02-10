#ifndef LOG
#include "log.hpp"
#define LOG
#endif // !LOG

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM


Request::Request(std::string command)
{
	this->command = command;
}


Request::Request(std::string command, std::vector<std::string> args)
{
	this->command = command;
    arguments = args;
}

Request::Request(std::pair<std::string, std::vector<std::string>> command)
{
    this->command = command.first;
    arguments = command.second;
}

std::pair<std::string, std::vector<std::string>> Request::data()
{
    return {command,arguments};
}

void Log::add(Request request)
{
    if (request.data().first == "EMPTY") return;
    std::cout << "\n\nLOG ADDS: " << request.data().first << "\nARGS: ";
    for (std::string str : request.data().second) {
        std::cout << "\n" << str;
    }
    requests.push(request);
}

std::pair<std::string, std::vector<std::string>> Log::get_request()
{
    if (requests.empty()) {
        return { "EMPTY",{} };
    }
    auto ans = requests.top().data();
    std::cout << "\nLOG RETURNED: " << ans.first;
    requests.pop();

    return ans;

}
