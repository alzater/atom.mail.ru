// TestField.h
#include <cxxtest/TestSuite.h>

#include "../../stack/stack.h"

class TestStack : public CxxTest::TestSuite
{
public:
    void testDefaultConstructor(void)
    {
        Stack<int> stack;
        TS_ASSERT(stack.empty());

        stack.push(10);
        TS_ASSERT(!stack.empty());
    }

    void testConstructor(void)
    {
        Stack<int> stack(3);
        TS_ASSERT(stack.empty());

        stack.push(4);
        stack.push(7);
        stack.push(2);

        TS_ASSERT_EQUALS(stack.size(), 3);
    }

    void testSize(void)
    {
        Stack<int> stack(3);
        TS_ASSERT_EQUALS(stack.size(), 0);

        stack.push(4);
        TS_ASSERT_EQUALS(stack.size(), 1);

        stack.push(5);
        TS_ASSERT_EQUALS(stack.size(), 2);

        stack.pop();
        TS_ASSERT_EQUALS(stack.size(), 1);

        stack.push(5);
        TS_ASSERT_EQUALS(stack.size(), 2);

        stack.pop();
        TS_ASSERT_EQUALS(stack.size(), 1);

        stack.pop();
        TS_ASSERT_EQUALS(stack.size(), 0);
    }

    void testEmpty(void)
    {
        Stack<int> stack(3);
        TS_ASSERT(stack.empty());

        stack.push(4);
        TS_ASSERT(!stack.empty());

        stack.push(5);
        TS_ASSERT(!stack.empty());

        stack.pop();
        TS_ASSERT(!stack.empty());

        stack.push(5);
        TS_ASSERT(!stack.empty());

        stack.pop();
        TS_ASSERT(!stack.empty());

        stack.pop();
        TS_ASSERT(stack.empty());
    }

    void testPushAndPop(void)
    {
        Stack<int> stack(3);
        TS_ASSERT(stack.empty());
        TS_ASSERT_EQUALS(stack.size(), 0);

        stack.push(4);
        stack.push(7);
        stack.push(2);
        TS_ASSERT_EQUALS(stack.size(), 3);
        TS_ASSERT_EQUALS(stack.top(), 2);
        TS_ASSERT(!stack.empty());

        stack.pop();
        TS_ASSERT_EQUALS(stack.size(), 2);
        TS_ASSERT_EQUALS(stack.top(), 7);
        TS_ASSERT(!stack.empty());

        stack.pop();
        TS_ASSERT_EQUALS(stack.size(), 1);
        TS_ASSERT_EQUALS(stack.top(), 4);
        TS_ASSERT(!stack.empty());

        stack.pop();
        TS_ASSERT_EQUALS(stack.size(), 0);
        TS_ASSERT(stack.empty());
    }
};
