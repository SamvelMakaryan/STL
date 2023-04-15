#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <exception>

namespace my {
    class out_of_range : public std::exception {
    public:
        const char* what() {
            return msg;
        }
    public:
        out_of_range(const char* str)
        : msg(str)
        {}
    private:
        const char* msg;
    };
}

#endif