// #include "gtcp.h"


// GTcp* GTcp::tcp(Mode mode, int port){

//   Printer::printMessageLine("Setup tcp...");

//   switch (mode) {
//     case Mode::Start:{
//       Printer::printMessage("Setup tcp complite, set as client");
//       return new GServer(port);
//     }
//     default:
//       return new GServer(port);
//   }

//   Printer::printMessage("Setup tcp complite, set as server");

// };

// GServer::GServer(int port) : AsyncServer(port){
//   _port = port;
// };

// void GServer::run(){
//   onClient(&handleNewClient);
//   begin();
// };

// void GServer::handleNewClient(void* arg, AsyncClient* client) {
    // Printer::printMessageLine("New client has been connected to server");

	// add to list
	// _clients.push_back(client);
	
	// register events
	// client->onData(&handleData, NULL);
	// client->onError(&handleError, NULL);
	// client->onDisconnect(&handleDisconnect, NULL);
	// client->onTimeout(&handleTimeOut, NULL);
  // }

// };
