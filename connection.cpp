#include "connection.hpp"

connection::connection(boost::asio::ip::tcp::socket socket) : m_socket(std::move(socket))
{
}

void connection::start()
{
    do_read();
}

void connection::do_read()
{
    auto self(shared_from_this());
    m_socket.async_read_some(
        boost::asio::buffer(m_data, max_length),
        [this, self](boost::system::error_code ec, size_t length)
        {
            if(!ec){
                do_write(length);
            }
        }
    );
}

void connection::do_write(size_t length)
{
     auto self(shared_from_this());
     boost::asio::async_write(
         m_socket, boost::asio::buffer(m_data, length),
          [this, self](boost::system::error_code ec, std::size_t /*length*/)
          {
            if (!ec) {
                do_read();
            }
          }
     );
}

