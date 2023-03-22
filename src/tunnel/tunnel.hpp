
namespace ioz {
class Tunnel {
  int tun_fd = -1;

 public:
  Tunnel();
  void Run();
}
}  // namespace ioz