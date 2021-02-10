#define PUBLIC_API __attribute__((visibility("default")))

// Forward-declaring _all_ of the following classes with extenral
// visibilty addresses the issue:
#if 0
namespace boost {
template <class Tag, class T>
class PUBLIC_API error_info;
};
namespace boost { namespace exception_detail {
class PUBLIC_API error_info_base;
};
};
namespace boost { namespace stacktrace {
class PUBLIC_API frame;
template <class Allocator> class PUBLIC_API basic_stacktrace;
};
};
#endif

#include <boost/stacktrace.hpp>
#include <boost/exception/all.hpp>

struct PUBLIC_API tag_stacktrace;
using traced = boost::error_info<struct tag_stacktrace, boost::stacktrace::stacktrace>;

extern void foo(int);
