#pragma once
#include <unordered_set>

class EventBus;
typedef struct _ENetHost ENetHost; // have to forward declare it like this because C sucks
typedef struct _ENetPeer ENetPeer;

namespace Net
{
  class NetworkServer
  {
  public:
    NetworkServer(EventBus* eventBus);
    ~NetworkServer();

    NetworkServer(const NetworkServer&) = delete;
    NetworkServer(NetworkServer&&) = delete;
    NetworkServer& operator=(const NetworkServer&) = delete;
    NetworkServer& operator=(NetworkServer&&) = delete;

    void Poll(double dt);

  private:
    EventBus* _eventBus;
    ENetHost* _server;
    std::unordered_set<ENetPeer*> _clients;
  };
}