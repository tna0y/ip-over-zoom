#include <vector>

namespace ioz {
struct PacketHandler {
  virtual ~PacketHandler(){};
  virtual void HandlePacket(std::vector<uint8_t>&& packet);
};
}  // namespace ioz