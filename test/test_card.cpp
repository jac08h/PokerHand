#include <gtest/gtest.h>
#include <exception>

#include "../src/card.h"

TEST(TestCard, InvalidInitializations) {
    ASSERT_THROW(Card{"0S"}, std::runtime_error);
}