#include "SystemTest.h"
#include "gtest/gtest.h"

#define ID 1

TEST(SceneStack, DummyTest) {
    ASSERT_EQ(2, (1+1));
}

TEST(SceneStack, pushtest) {
    DummyScene testScene(ID);
    ASSERT_EQ(ID, 1);
}
