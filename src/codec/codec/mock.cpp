#include "mock.hpp"

namespace ioz {
std::vector<uint8_t> MockCodec::Encode(std::vector<uint8_t>&& in) {
  return std::move(in);
}
std::vector<uint8_t> MockCodec::Decode(std::vector<uint8_t>&& in) {
  return std::move(in);
}
}  // namespace ioz
