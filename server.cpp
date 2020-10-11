#include "server.hpp"
#include "connection.hpp"

#include <memory>

server::server(boost::asio::io_context& io_context, short port) :
m_acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
    do_accept();
}

void server::do_accept() 
{
    m_acceptor.async_accept(
        [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket)
        {
            if(!ec){
                std::make_shared<connection>(std::move(socket))->start();
            }

            do_accept();
        }
    );
}