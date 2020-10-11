#include <iostream>
#include <string>

#include "server.hpp"

int main()
{
  try{
    boost::asio::io_context io;
    server s{io, 6789};
    io.run();
  } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
  }

  return 0;
}