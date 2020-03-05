#ifdef UNIT_TESTING_ENABLED
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif /* UNIT_TESTING_ENABLED */
