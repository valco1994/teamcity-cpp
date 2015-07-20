#define BOOST_TEST_MAIN

#include <iostream>

#include <boost/test/unit_test.hpp>

using namespace std;

/* Suite tree tests */
BOOST_AUTO_TEST_SUITE(my_suite1)

BOOST_AUTO_TEST_CASE(my_test1) {
    BOOST_CHECK(2 == 1);
}

BOOST_AUTO_TEST_CASE(my_test2) {
    int i = 0;

    BOOST_CHECK_EQUAL(i, 2);
    BOOST_CHECK_EQUAL(i, 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(my_test3) {
    int i = 0;

    BOOST_CHECK_EQUAL(i, 0);
}

BOOST_AUTO_TEST_SUITE(my_suite2)

BOOST_AUTO_TEST_CASE(my_test4) {
    int i = 0;

    BOOST_CHECK_EQUAL(i, 1);
}

BOOST_AUTO_TEST_SUITE(internal_suite)

BOOST_AUTO_TEST_CASE(my_test5) {
    int i = 0;

    BOOST_CHECK_EQUAL( i, 1 );
}

BOOST_AUTO_TEST_SUITE_END() 

BOOST_AUTO_TEST_SUITE_END()

/* Other */
BOOST_AUTO_TEST_CASE(testCerr) {
    cerr << "Hello from cerr" << endl;
}

BOOST_AUTO_TEST_CASE(testCout) {
    cerr << "Hello from cout" << endl;
}

static void ThrowRuntimeError() {
    throw runtime_error("runtime exception text");
}

BOOST_AUTO_TEST_CASE(testException) {
    ThrowRuntimeError();
}

BOOST_AUTO_TEST_CASE(testAssertExceptionGood) {
    BOOST_CHECK_THROW(ThrowRuntimeError(), runtime_error);
}

BOOST_AUTO_TEST_CASE(testAssertExceptionFail) {
    BOOST_CHECK_THROW(ThrowRuntimeError(), logic_error);
}

BOOST_AUTO_TEST_CASE(testFatal) {
    BOOST_FAIL("bfail");
}
    
BOOST_AUTO_TEST_CASE(testError) {
    BOOST_ERROR("berror");
}
    
BOOST_AUTO_TEST_CASE(testNothing) {}
