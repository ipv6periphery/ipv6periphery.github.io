#include <arpa/inet.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string expand_ipv6(const struct in6_addr &addr) {
  std::ostringstream oss;

  // IPv6 是 8 组 16-bit
  for (int i = 0; i < 8; ++i) {
    uint16_t part = (addr.s6_addr[i * 2] << 8) | addr.s6_addr[i * 2 + 1];

    oss << std::hex << std::setw(4) << std::setfill('0') << part;

    if (i != 7)
      oss << ":";
  }

  return oss.str();
}

int main() {
  std::string line;

  while (std::getline(std::cin, line)) {
    if (line.empty())
      continue;

    struct in6_addr addr;

    if (inet_pton(AF_INET6, line.c_str(), &addr) != 1) {
      continue;
    }

    std::cout << expand_ipv6(addr) << "\n";
  }

  return 0;
}
