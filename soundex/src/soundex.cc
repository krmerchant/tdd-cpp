#include  "gmock/gmock.h"

using ::testing::Eq;

class Soundex
{
  public:
  std::string encode(const std::string& word) const
  {
    return ZeroPad(word);
  }

  private:
  std::string ZeroPad(const std::string& word) const
  {
    return word+"000";
  }
};

class SoundexEncoding : public testing::Test
{
  public:
    Soundex soundex;
};


TEST_F(SoundexEncoding, RetrainFirstLetter)
{
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

//PICK UP AT 2.7 page 30