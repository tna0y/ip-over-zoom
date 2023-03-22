#include "tunnel.hpp"

#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <net/if.h>
#include <sys/ioctl.h>

#include <string>
namespace ioz {

Tunnel::Tunnel() {
  struct ifreq ifr;
  memset(&ifr, 0, sizeof(ifr));

  int fd;

  if ((fd = open("/dev/net/tun", O_RDWR)) < 0) {
    throw std::runtime_error("failed to open tun");
  }

  ifr.ifr_flags = IFF_TUN | IFF_NO_PI | IFF_MULTI_QUEUE | IFF_NAPI;
  ifr.ifr_name = "tun0";
  if ((err = ioctl(fd, TUNSETIFF, (void*)&ifr)) < 0) {
    close(fd);
    std::runtime_error("failed TUNSETIFF");
  }
  this->tun_fd = fd;
}
Tunnel::~Tunnel() {
  if (this->tun_fd > -1) close(this->tun_fd);
}

void Tunnel::Run() {}
}  // namespace ioz