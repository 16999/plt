#include "Client.h"
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace client;
using namespace std;
#define PORT 8080

Client::Client()
{
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char *hello = "Hello from client";
  char buffer[1024] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      std::cout << "Socket creation error" << endl;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
      std::cout << "Invalid address / Address not supported" << endl;
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      std::cout << "Connection Failed" << endl;

  send(sock , hello , strlen(hello) , 0);
  std::cout << "Hello message sent" << endl;
  valread = read( sock , buffer, 1024);
  std::cout << buffer ;
}
