

#include <boost/asio/ip/network_v6.hpp>
#include <cstddef>
#include <cstdint>
#include <format>

#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

static void hilbert_xy(uint32_t s, int order, uint32_t &x, uint32_t &y) {
  uint32_t state = 0;
  x = y = 0;

  for (int i = 2 * order - 2; i >= 0; i -= 2) {
    uint32_t row = 4 * state | ((s >> i) & 3);

    x = (x << 1) | ((0x936C >> row) & 1);
    y = (y << 1) | ((0x39C6 >> row) & 1);

    state = (0x3E6B94C1 >> (2 * row)) & 3;
  }

  y = ((1u << order) - 1) - y;
}

int main() {

  std::string line;
  std::unordered_map<uint32_t, size_t> count{};
  while (std::getline(std::cin, line)) {
    auto net = boost::asio::ip::make_network_v6(line);
    if (net.prefix_length() != 48)
      continue;
    uint64_t len = net.prefix_length();
    auto nbytes = net.network().to_bytes();
    uint32_t prefix = std::accumulate(
        nbytes.begin(), nbytes.begin() + 4, uint64_t{0},
        [](uint32_t acc, uint8_t byte) { return (acc << 8) | byte; });
    count[prefix]++;
  }

  for (auto &c : count) {
    uint32_t x, y;
    // 32 - 8 = 24
    // 24 / 2 = 12 (order)
    hilbert_xy(c.first, 12, x, y);
    std::cout << std::format("{:02x}00::/8,{:d},{:d},{:d}\n", (c.first >> 24),
                             x, y, c.second);
  }
}
