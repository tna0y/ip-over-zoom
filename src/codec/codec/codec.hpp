
#include <stdint.h>

#include <vector>
namespace ioz {
struct Codec {
  virtual ~Codec(){};
  virtual std::vector<uint8_t> Encode(std::vector<uint8_t>&&);
  virtual std::vector<uint8_t> Decode(std::vector<uint8_t>&&);
};
}  // namespace ioz