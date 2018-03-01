#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define IP_ADDRESS "127.0.0.1"
#define PORT 5555

int main()
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	cout << "Connected to server!" << endl;

	char buffer[1024] = { "hello!" };
	send(server, buffer, sizeof(buffer), 0);
	cout << "Message sent!" << endl;

	closesocket(server);
	WSACleanup();
	cout << "Socket closed" << endl;

	cin.get();
}