#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include <unistd.h> // close()

int main()
{
  // create socket with descriptor name
  int network_socket;                               // for return value of socket call
  network_socket = socket(AF_INET, SOCK_STREAM, 0); // ARGS: domain of the socket (for internet) / type of the socket (for TCP) / protocol (0 for default)

  // specify an address for the socket - to connect to
  struct sockaddr_in server_address;           // from netinet/in.h
  server_address.sin_family = AF_INET;         // same family as our socket
  server_address.sin_port = htons(6060);       // htons does type conversion
  server_address.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY specifies 0.0.0.0 a.k.a. any ip address on local machine

  int connection_status = connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address)); // ARGS: the socket / type casting to sockaddr (without the _in) and as pointer / size of the address

  // check for error
  if (connection_status == -1)
  {
    printf("There was an error making the connection to the remote socket \n\n");
  }

  // recieve data from the server
  char server_response[256];                                          // a string
  recv(network_socket, &server_response, sizeof(server_response), 0); // ARGS: the socket / destination to save data / size of the buffer / 0 for no flags

  // print the server's response
  printf("The server sent the data: %s\n", server_response);

  // and then close the socket
  close(network_socket); // needed to add '#include <unistd.h>'

  return 0;
}