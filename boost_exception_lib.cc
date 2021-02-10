#include "boost_exception.h"

PUBLIC_API void foo(int i) {
    throw boost::enable_error_info(std::out_of_range("Some random exception"))
            << traced(boost::stacktrace::stacktrace());
}
