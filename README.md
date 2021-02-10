Build and run CMake project - note that `get_error_info()` in boost_exception_test.cc fails - this appears to be due to the hidden (non-external) visibility on my `typeinfo for boost::error_info<tag_stacktrace, ...` symbol:
```
cmake .. && make && ./boost-exception-test 
-- The C compiler identification is AppleClang 12.0.0.12000032
-- The CXX compiler identification is AppleClang 12.0.0.12000032
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Boost: /usr/local/lib/cmake/Boost-1.73.0/BoostConfig.cmake (found version "1.73.0")  
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/dave/Documents/Code/error_info_visibility/build
Scanning dependencies of target boost-exception-lib
[ 25%] Building CXX object CMakeFiles/boost-exception-lib.dir/boost_exception_lib.cc.o
[ 50%] Linking CXX shared library libboost-exception-lib.dylib
[ 50%] Built target boost-exception-lib
Scanning dependencies of target boost-exception-test
[ 75%] Building CXX object CMakeFiles/boost-exception-test.dir/boost_exception_test.cc.o
[100%] Linking CXX executable boost-exception-test
[100%] Built target boost-exception-test
Caught N5boost16exception_detail19error_info_injectorISt12out_of_rangeEE: Some random exception
FAIL get_error_info() unable to find stacktrace
```

If the default visibility is changed to default then the test passes:
```
cmake -DCMAKE_CXX_VISIBILITY_PRESET=default .. && make && ./boost-exception-test
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/dave/Documents/Code/error_info_visibility/build
[ 25%] Building CXX object CMakeFiles/boost-exception-lib.dir/boost_exception_lib.cc.o
[ 50%] Linking CXX shared library libboost-exception-lib.dylib
[ 50%] Built target boost-exception-lib
[ 75%] Building CXX object CMakeFiles/boost-exception-test.dir/boost_exception_test.cc.o
[100%] Linking CXX executable boost-exception-test
[100%] Built target boost-exception-test
Caught N5boost16exception_detail19error_info_injectorISt12out_of_rangeEE: Some random exception
 0# foo(int) in /Users/dave/Documents/Code/error_info_visibility/build/libboost-exception-lib.dylib
 1# main in /Users/dave/Documents/Code/error_info_visibility/build/./boost-exception-test
```

I tried adding ` _attribute_((visibility("default")))` to a forward decl of boost::error_info but no success (see commented out code in boost_exception_test.cc).
