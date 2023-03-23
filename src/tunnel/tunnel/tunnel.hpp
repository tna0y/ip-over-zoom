#include "common/packet_handler.hpp"

namespace ioz {
class Tunnel : PacketHandler {
  int tun_fd = -1;

 public:
  Tunnel();
  void Run();

  // PacketHandler
  void HandlePacket(std::vector<uint8_t>&& packet) override;
};
}  // namespace ioz