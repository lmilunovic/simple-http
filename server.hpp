#pragma once

#include <boost/asio.hpp>

class server
{
public:
    server(boost::asio::io_context& io_context, short port);
private:
    void do_accept();
    boost::asio::ip::tcp::acceptor m_acceptor;
};