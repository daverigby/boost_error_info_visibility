#include "boost_exception.h"
#include <iostream>

int main() {
    try {
        foo(5);
    } catch (const std::exception& e) {
        std::cout << "Caught " << typeid(e).name() << ": " << e.what() << '\n';
        const boost::stacktrace::stacktrace* st = boost::get_error_info<traced>(e);
        if (st) {
            std::cout << *st << '\n';
            return 0;
        }
        std::cerr << "FAIL get_error_info() unable to find stacktrace\n";
        return 1;
    }
}
