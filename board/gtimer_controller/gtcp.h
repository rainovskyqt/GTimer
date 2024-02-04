#ifndef GTCP_H
#define GTCP_H

#include <ESPAsyncTCP.h>
#include "enums.h"
#include "printer.h"

class GTcp
{
  public:
  // virtual void run();

  // static GTcp* tcp(Mode mode, int port);

  

};

// class GServer: public AsyncServer, public GTcp
// {

//   public:
//     GServer(int port);

//     void run() override;

//   private:
//     int _port;
//     static std::vector<AsyncClient*> _clients;

//     void handleNewClient(void* arg, AsyncClient* client);
// };

#endif // GTCP_H