#pragma once
#include <memory>
#include <boost/asio.hpp>

class connection : public std::enable_shared_from_this<connection>
{
public:
    connection(boost::asio::ip::tcp::socket socket);
    void start();

private:
    void do_read();
    void do_write(size_t length);

    boost::asio::ip::tcp::socket m_socket;
    enum { max_length = 1024 };
    char m_data[max_length];
};