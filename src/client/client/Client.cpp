#include "Client.h"
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace client;
using namespace std;
#define PORT 8080



struct sockaddr_in serv_addr;

Client::Client()
{

  buffer.resize(1024);

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      std::cout << "Socket creation error" << endl;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
      std::cout << "Invalid address / Address not supported" << endl;
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      std::cout << "Connection Failed" << endl;

  send(sock , hello.c_str() , hello.size() , 0);
  std::cout << "Hello message sent\n" << endl;
  valread = read( sock , (char*) buffer.c_str() , buffer.size());
  std::cout << buffer << endl;
}
