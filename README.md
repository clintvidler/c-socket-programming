# Socket programming in C

## Description

Sockets are the low-level endpoints used for processing information across a network. Some common protocols like HTTP, FTP rely on sockets to make connections. Socket Programming is the route of connecting two points on a network to communicate with each other. In this video, you will learn the basics of Socket Programming like definitions, Client socket workflow, Server Socket workflow and many more.

### TCP Client

1. make socket
2. connect to socket
3. recieive from socket

### TCP Server

1. make socket
2. bind to ip and port
3. listen for connections
4. accept to get another socket to connect - then send() or recv() to handle data to/from client

### Notes

The client and server flow similarly but with differences, i.e. client connects, while server binds and listens.

## References

Socket Programming Tutorial In C For Beginners | Part 1:

https://www.youtube.com/watch?v=LtXEMwSG5-8
