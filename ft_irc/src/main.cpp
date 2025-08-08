#include <iostream>
#include <cstdlib>
#include "../includes/network/Server.hpp"

bool isValidPort(const std::string& portStr)
{
	int port;
	bool valid;

	for (size_t i = 0; i < portStr.size(); ++i)
	{
		if (!isdigit(portStr[i]))
			return false;
	}

	port = std::atoi(portStr.c_str());
	valid = port > 0 && port <= 65535;

	return valid;
}

int main(int argc, char** argv)
{
	if (argc != 3)
    {
		std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
		return 1;
	}

	std::string portStr(argv[1]);
	std::string password(argv[2]);

	if (!isValidPort(portStr))
    {
		std::cerr << "Error: Invalid port number." << "Usa entre 1 y 65535" << std::endl;
		return 1;
	}

	int port = std::atoi(portStr.c_str());

	try
	{
		Server ircServer(port, password);
		ircServer.run();
	} 
	catch (const std::exception& e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
