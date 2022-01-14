#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Server.h"
using namespace server;
using namespace std;
#define PORT 8080


int server_fd, new_socket, valread;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);
std::string buffer;
std::string hello = "Hello from server";

Server::Server()
{
  buffer.resize(1024);

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
      perror("socket failed");
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
      perror("setsockopt");

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
      perror("bind failed");
  if (listen(server_fd, 3) < 0)
      perror("listen");
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
      perror("accept");

  valread = read(new_socket,(char*)buffer.c_str(), buffer.size());
  //std::cout << buffer << endl;
  printf("%s\n",buffer.c_str());
  send(new_socket, hello.c_str(), hello.size(), 0);
  //std::cout << "Hello message sent" << endl;
  printf("Hello message sent");
}
