#include "tunnel.hpp"

#include <errno.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

namespace ioz {

Tunnel::Tunnel() {
  struct ifreq ifr;
  memset(&ifr, 0, sizeof(ifr));

  int fd, err;

  const char *dev = "tun0";

  if ((fd = open("/dev/net/tun", O_RDWR)) < 0) {
    throw std::runtime_error("failed to open tun");
  }

  ifr.ifr_flags = IFF_TUN | IFF_NO_PI | IFF_MULTI_QUEUE | IFF_NAPI;
  strncpy(ifr.ifr_name, dev, IFNAMSIZ);

  if ((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0) {
    close(fd);

    throw std::runtime_error("failed TUNSETIFF syscall");
  }

  this->tun_fd = fd;
}

Tunnel::~Tunnel() {
  if (this->tun_fd > -1) close(this->tun_fd);
}

void Tunnel::Run() {
  char buf[4000];
  while (true) {
    int n = read(this->tun_fd, buf, sizeof(buf));
    if (n <= 0) {
      throw std::runtime_error(strerror(errno));
    }
    std::cout << "got packet" << n << std::endl;
  }
}

void Tunnel::HandlePacket(std::vector<uint8_t> &&packet) {
  int n = write(this->tun_fd, packet.data(), packet.size());
  if (n < 0) {
    throw std::runtime_error(strerror(errno));
  }
}

}  // namespace ioz
