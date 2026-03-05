//! Unit Tests for MPAGSCipher CaesarCipher Class
#include "gtest/gtest.h"

#include "VigenereCipher.hpp"

TEST(VigenereCipher, Encrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_EQ(cc.applyCipher(
                  "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES",
                  CipherMode::Encrypt),
              "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ");
}

TEST(VigenereCipher, Decrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_EQ(cc.applyCipher(
                  "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ",
                  CipherMode::Decrypt),
              "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES");
}
