#include <gtest/gtest.h>
#include "StringUtils.h"

// Slice Tests
TEST(StringUtilsTest, SliceTest) {
    EXPECT_EQ(slice("Hello, World!", 0, 5), "Hello");
    EXPECT_EQ(slice("Hello, World!", -6), "World!");
    EXPECT_EQ(slice("Hello, World!", 7, 12), "World");
    EXPECT_EQ(slice("Hello, World!", 7, -1), "World");
    EXPECT_EQ(slice("Hello, World!", 7), "World!");
    EXPECT_EQ(slice("Hello, World!", -6, -1), "World");
    EXPECT_EQ(slice("Hello, World!", 20, 25), ""); // Out of bounds
    EXPECT_EQ(slice("Hello, World!", -20, -15), ""); // Out of bounds
}

// Capitalize Tests
TEST(StringUtilsTest, CapitalizeTest) {
    EXPECT_EQ(Capitalize("hello"), "Hello");
    EXPECT_EQ(Capitalize("HELLO"), "Hello");
    EXPECT_EQ(Capitalize(""), "");
    EXPECT_EQ(Capitalize("h"), "H");
    EXPECT_EQ(Capitalize("hello world"), "Hello world");
    EXPECT_EQ(Capitalize("123hello"), "123hello");
}

// Upper Tests
TEST(StringUtilsTest, UpperTest) {
    EXPECT_EQ(Upper("hello"), "HELLO");
    EXPECT_EQ(Upper("HeLlO"), "HELLO");
    EXPECT_EQ(Upper(""), "");
    EXPECT_EQ(Upper("123hello"), "123HELLO");
    EXPECT_EQ(Upper("Hello, World!"), "HELLO, WORLD!");
}

// Lower Tests
TEST(StringUtilsTest, LowerTest) {
    EXPECT_EQ(Lower("HELLO"), "hello");
    EXPECT_EQ(Lower("HeLlO"), "hello");
    EXPECT_EQ(Lower(""), "");
    EXPECT_EQ(Lower("123HELLO"), "123hello");
    EXPECT_EQ(Lower("Hello, World!"), "hello, world!");
}

// LStrip Tests
TEST(StringUtilsTest, LStripTest) {
    EXPECT_EQ(LStrip("  hello"), "hello");
    EXPECT_EQ(LStrip("hello  "), "hello  ");
    EXPECT_EQ(LStrip("  hello  "), "hello  ");
    EXPECT_EQ(LStrip(""), "");
    EXPECT_EQ(LStrip("   "), "");
    EXPECT_EQ(LStrip("\t\nhello"), "hello");
}

// RStrip Tests
TEST(StringUtilsTest, RStripTest) {
    EXPECT_EQ(RStrip("hello  "), "hello");
    EXPECT_EQ(RStrip("  hello"), "  hello");
    EXPECT_EQ(RStrip("  hello  "), "  hello");
    EXPECT_EQ(RStrip(""), "");
    EXPECT_EQ(RStrip("   "), "");
    EXPECT_EQ(RStrip("hello\t\n"), "hello");
}

// Strip Tests
TEST(StringUtilsTest, StripTest) {
    EXPECT_EQ(Strip("  hello  "), "hello");
    EXPECT_EQ(Strip("hello"), "hello");
    EXPECT_EQ(Strip(""), "");
    EXPECT_EQ(Strip("   "), "");
    EXPECT_EQ(Strip("\t\nhello\t\n"), "hello");
}

// Center Tests
TEST(StringUtilsTest, CenterTest) {
    EXPECT_EQ(Center("hello", 9), "  hello  ");
    EXPECT_EQ(Center("hello", 10, '-'), "--hello---");
    EXPECT_EQ(Center("hello", 3), "hello"); // Width smaller than string
    EXPECT_EQ(Center("", 5, '*'), "*****"); // Empty string
}

// LJust Tests
TEST(StringUtilsTest, LJustTest) {
    EXPECT_EQ(LJust("hello", 9), "hello    ");
    EXPECT_EQ(LJust("hello", 10, '-'), "hello-----");
    EXPECT_EQ(LJust("hello", 3), "hello"); // Width smaller than string
    EXPECT_EQ(LJust("", 5, '*'), "*****"); // Empty string
}

// RJust Tests
TEST(StringUtilsTest, RJustTest) {
    EXPECT_EQ(RJust("hello", 9), "    hello");
    EXPECT_EQ(RJust("hello", 10, '-'), "-----hello");
    EXPECT_EQ(RJust("hello", 3), "hello"); // Width smaller than string
    EXPECT_EQ(RJust("", 5, '*'), "*****"); // Empty string
}

// Replace Tests
TEST(StringUtilsTest, ReplaceTest) {
    EXPECT_EQ(Replace("hello world", "world", "there"), "hello there");
    EXPECT_EQ(Replace("hello world world", "world", "there"), "hello there there");
    EXPECT_EQ(Replace("hello world", "o", "O"), "hellO wOrld");
    EXPECT_EQ(Replace("hello world", "x", "y"), "hello world"); // No match
    EXPECT_EQ(Replace("", "world", "there"), ""); // Empty string
}

// Split Tests
TEST(StringUtilsTest, SplitTest) {
    EXPECT_EQ(Split("hello world"), std::vector<std::string>({"hello", "world"}));
    EXPECT_EQ(Split("hello  world"), std::vector<std::string>({"hello", "world"}));
    EXPECT_EQ(Split("hello,world", ","), std::vector<std::string>({"hello", "world"}));
    EXPECT_EQ(Split("hello,,world", ","), std::vector<std::string>({"hello", "", "world"}));
    EXPECT_EQ(Split("", ","), std::vector<std::string>({""})); // Empty string
    EXPECT_EQ(Split("   ", " "), std::vector<std::string>({})); // Only whitespace
}

// Join Tests
TEST(StringUtilsTest, JoinTest) {
    EXPECT_EQ(Join(",", {"hello", "world"}), "hello,world");
    EXPECT_EQ(Join(" ", {"hello", "world"}), "hello world");
    EXPECT_EQ(Join("", {"hello", "world"}), "helloworld");
    EXPECT_EQ(Join(",", {}), ""); // Empty vector
    EXPECT_EQ(Join(",", {"hello"}), "hello"); // Single element
}

// ExpandTabs Tests
TEST(StringUtilsTest, ExpandTabsTest) {
    EXPECT_EQ(ExpandTabs("hello\tworld"), "hello    world");
    EXPECT_EQ(ExpandTabs("hello\tworld", 8), "hello   world");
    EXPECT_EQ(ExpandTabs("\t\t", 4), "        "); // Multiple tabs
    EXPECT_EQ(ExpandTabs("", 4), ""); // Empty string
    EXPECT_EQ(ExpandTabs("hello", 4), "hello"); // No tabs
}

// EditDistance Tests
TEST(StringUtilsTest, EditDistanceTest) {
    EXPECT_EQ(EditDistance("kitten", "sitting"), 3);
    EXPECT_EQ(EditDistance("saturday", "sunday"), 3);
    EXPECT_EQ(EditDistance("", ""), 0); // Empty strings
    EXPECT_EQ(EditDistance("hello", "hello"), 0); // Identical strings
    EXPECT_EQ(EditDistance("hello", "HELLO", true), 0); // Case-insensitive
    EXPECT_EQ(EditDistance("hello", "HELLO", false), 4); // Case-sensitive
}