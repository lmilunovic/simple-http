#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
  boost::asio::io_service io;

  tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 6789));

  try{
    for (;;)
    {
        tcp::socket socket(io);
        acceptor.accept(socket);
        std::string msg = "Hello World!";

        boost::system::error_code ignored_error;
        boost::asio::write(socket, boost::asio::buffer(msg), ignored_error);
    }
  } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
  }

  return 0;
}