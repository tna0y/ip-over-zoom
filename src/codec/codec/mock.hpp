#include "codec.hpp"

namespace ioz {
class MockCodec : Codec {
 public:
  std::vector<uint8_t> Encode(std::vector<uint8_t>&&) override;
  std::vector<uint8_t> Decode(std::vector<uint8_t>&&) override;
};
}  // namespace ioz