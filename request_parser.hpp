#pragma once
#include "request.hpp"

namespace http {

    class request_parser {

    private:    
    
    enum state {
        method,
        version,
        header,
        end,
        bad
    };

        request m_request{};
        state parser_state{method};
        char current[];
        
    public:

        request parse() {

            while ( parser_state != end) {
                parser_state = consume_next();
            }

            return m_request;
        }

        state consume_next() {

            switch (parser_state)
            {
            case method:
                /* code */
                // return consume_method();
                break;
            case version:
                /**/
                //return consume_version();
                break;
            case header:
                /**/
                //return consume_header();
                break;
            case end:
                /**/
                // return parser_state;
                break;
            case bad:
                /**/
                // throw bad_state_exception(parser_state);
                break;

            default:
                break;
            }
        }
    };
}