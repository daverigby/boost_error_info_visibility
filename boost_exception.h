#define PUBLIC_API __attribute__((visibility("default")))

// I expected that adding external (default) visibility to a
// forward-decl of boost::error_info & error_info_base would fix the
// problem, but it doesn't - uncommenting this still gives the same
// error.
#if 0
namespace boost {
template <class Tag, class T>
class PUBLIC_API error_info;
};
namespace boost { namespace exception_detail {
class PUBLIC_API error_info_base;
};
};
#endif

#include <boost/stacktrace.hpp>
#include <boost/exception/all.hpp>

using traced = boost::error_info<struct tag_stacktrace, boost::stacktrace::stacktrace>;

extern void foo(int);
