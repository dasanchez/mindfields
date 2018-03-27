# Client/Server options

## Server Requirements

The server software will be responsible for:
1. Generating the word list. This means storing and handling a dictionary files (or multiple ones), as well as publishing randomized game lists.
2. Tracking teams and individual players.
3. Tracking turns and points.
4. Running timers.
5. Providing game state and all data each player needs.
6. Setting the winner.

## Server Options

1. HTTP vs WebSocket  
WebSocket is bi-rirectional, full-duplex, and requires a single TCP connection for the lifecycle of the WebSocket connection. 

2. Server software  
**JavaScript**  
Node.js: asynchronous event-driven JavaScript runtime.  
Socket.io: JavaScript library for realtime web applications.  
Express: web application framework for Node.js.
**Python**  
Flask: micro web framework for Python.  
Tornado: Python web framework and asynchronous networking library. 
Pyramid: lightweight Python web framework aimed at taking small web apps into big web apps. 
Django: web framework written in Python.  
Twisted Python: event-driven networking engine written in Python.
**C++**  
Qt: cross-platform application framework.

## Client Requirements

The client needs to do the following:
1. Provide an interface to the user (GUI).
2. Issue requests and receive responses from the server.

## Client Options

1. Stand-alone vs Web  
A stand-alone client can be programmed with Python, QML, or C++ and a TCP or HTTP library.
A web client will require some HTML, CSS, and Javascript (HTML5 canvas).

2. Client software  
**C++**    
Qt  
**Python**  
**Javascript**  
socket.io  
QML: user interface markup language.

## Messaging
Use JSON: a lightweight data-interchange format, to pass messages between client and server.

## Current Plan 

### Development

- Server side: Python and TCP sockets or a small web framework (possibly Tornado) for exploring HTTP, or C++ on Qt depending on development environment availability.
- Client side: QML or Qt Widgets. Qt Widgets will allow for some rapid prototyping of the UI, while QML will speed up porting the functionality to Javascript.

### Release
- Server side: Use Tornado or socket.io with websockets.
- Client side: Develop a web client using socket.io and react.js.
