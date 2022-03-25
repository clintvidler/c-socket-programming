#include <stdio.h>
#include <stdlib.h>

#include <string.h> // for string manipulation

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include <unistd.h> // close()

int main()
{
  // point to a html file
  FILE *html_data;                      // file pointer to hold the data
  html_data = fopen("index.html", "r"); // stdlib - ARGS: / filename / read/write

  // read the html file into this program
  char response_data[1024];
  fgets(response_data, 1024, html_data); // ARGS: read into / how much to read / file to read from

  char http_header[2048] = "HTTP/1.1 200 OK\r\n\n"; // response header

  // combine header and body data
  strcat(http_header, response_data); // http_header now also contains response data

  // create a socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // define the address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(6060);
  server_address.sin_addr.s_addr = INADDR_ANY;

  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  listen(server_socket, 5);

  int client_socket;
  while (1)
  { // run until interupted, i.e. ctrl+c
    client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, http_header, sizeof(http_header), 0);

    shutdown(client_socket, 1); // close(client_socket); caused -> net::ERR_CONNECTION_RESET
  }

  return 0;
}