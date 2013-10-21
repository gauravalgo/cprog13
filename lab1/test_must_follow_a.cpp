#include <cxxtest/TestSuite.h>

#include "must_follow_a.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:

    // Testcase 1

    // This testcase sets up a 5 sized array (precondition). Note that
    // the second argument (length) to must_follow_a is 4. The
    // expected result is successs.

    // Do make additional tests of your own and try it out. 

    void test_1( void )
    {
        char vek[] = {'x', 'a', 'b', 'x', 'a', 'b', 'x'};
        int result = must_follow_a(vek, 7, 'a', 'b');
        TS_ASSERT_EQUALS( result, 2);        
    }
    void test_2( void ){
        char vek2[] = {'b', 'b', 'a', 'b', 'b'};
        int res = must_follow_a(vek2, 3, 'a', 'b');
        TS_ASSERT_EQUALS( res, 0);
    }
    void test_3( void ){
        char vek2[] = {'c', 'a', 'a', 'a', 'a'};
        int res = must_follow_a(vek2, 3, 'a', 'b');
        TS_ASSERT_EQUALS( res, 0);
    }

};
