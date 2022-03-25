#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include <unistd.h> // close()

int main()
{
  char server_message[256] = "You have reached the server";

  // create the server socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // define the server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(6060);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // bind the socket to our specified IP and port
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  listen(server_socket, 5); // ARGS: the socket / backlog, how many connections can be waiting for this socket at any time

  int client_socket;                                 // accept connection to client socket (2-way connect)
  client_socket = accept(server_socket, NULL, NULL); // ARGS: socket to accept connections on / struct that will be populated with info about client / ??

  // send the message
  send(client_socket, server_message, sizeof(server_message), 0); // ARGS: socket to send data on / the data / data size / optional flags

  // close the socket
  close(server_socket);

  return 0;
}