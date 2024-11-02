#include <memory>
#include <string>
#include <iostream>
#include <gtest/gtest.h>

#include "../citizens/Citizen.h"
#include "../citizens/BoyBuilder.h"
#include "../citizens/Boy.h"
#include "../citizens/Girl.h"
#include "../citizens/GirlBuilder.h"
#include "../citizens/Woman.h"
#include "../citizens/WomanBuilder.h"
#include "../citizens/Man.h"
#include "../citizens/ManBuilder.h"


/*
TEST(PolicyTest, CanCreateEducationService) {
    // Test the creation of Education service
    shared_ptr<Education> education = make_shared<Education>();
    EXPECT_EQ(education->getTypeOfPublicService(), "Education")
        << "Expected the type of public service to be 'Education'.";
}
*/

// Boy builder tests and Boy class tests
TEST(BoyBuilderTest, addGenderTest){
  std::shared_ptr<BoyBuilder> boybuilder = make_shared<BoyBuilder>();
  boybuilder->addGender();
  std::shared_ptr<Citizen> boy = boybuilder->getCitizen();
  ASSERT_NE(boy, nullptr);
  EXPECT_EQ(boy->getGender(), "Male");
}

TEST(BoyBuilderTest, addTypeTest){
  std::shared_ptr<BoyBuilder> boybuilder = make_shared<BoyBuilder>();
  boybuilder->addType();
  std::shared_ptr<Citizen> boy = boybuilder->getCitizen();
  ASSERT_NE(boy, nullptr);
  EXPECT_EQ(boy->getType(), "Boy");
}

TEST(BoyBuilderTest, addStatusTestWithValidInput) {
  std::shared_ptr<BoyBuilder> boyBuilder = std::make_shared<BoyBuilder>();

  std::istringstream input("Yes\n");
  std::cin.rdbuf(input.rdbuf());

  boyBuilder->addStatus();
  std::shared_ptr<Citizen> boy = boyBuilder->getCitizen();
  ASSERT_NE(boy, nullptr);
  EXPECT_TRUE(boy->getStatus()); 
}

TEST(BoyBuilderTest, addStatusTestWithInvalidInput) {
  std::shared_ptr<BoyBuilder> boyBuilder = std::make_shared<BoyBuilder>();

  std::istringstream input("Maybe\nno\n");
  std::cin.rdbuf(input.rdbuf()); 

  boyBuilder->addStatus();
  std::shared_ptr<Citizen> boy = boyBuilder->getCitizen();
  ASSERT_NE(boy, nullptr);
  EXPECT_FALSE(boy->getStatus());
}

TEST(BoyTest, getStatus){
  std::shared_ptr<Boy> boy = make_shared<Boy>();
  boy->setStatus(false);

  ASSERT_NE(boy, nullptr);
  EXPECT_FALSE(boy->getStatus());
}

TEST(BoyTest, getType){
  std::shared_ptr<Boy> boy = make_shared<Boy>();
  boy->setType("Boy");

  ASSERT_NE(boy, nullptr);
  EXPECT_EQ(boy->getType(), "Boy");
}

TEST(BoyTest, getStatus){
  std::shared_ptr<Boy> boy = make_shared<Boy>();
  boy->setGender("Male");

  ASSERT_NE(boy, nullptr);
  EXPECT_EQ(boy->getGender(), "Male");
}



// Girl Builder tests and girl class
TEST(GirlTest, getStatus) {
  std::shared_ptr<Girl> girl = make_shared<Girl>();
  girl->setStatus(true);

  ASSERT_NE(girl, nullptr);
  EXPECT_TRUE(girl->getStatus());
}

TEST(GirlTest, getType) {
  std::shared_ptr<Girl> girl = make_shared<Girl>();
  girl->setType("Girl");

  ASSERT_NE(girl, nullptr);
  EXPECT_EQ(girl->getType(), "Girl");
}

TEST(GirlTest, getGender) {
  std::shared_ptr<Girl> girl = make_shared<Girl>();
  girl->setGender("Female");

  ASSERT_NE(girl, nullptr);
  EXPECT_EQ(girl->getGender(), "Female");
}

TEST(GirlBuilderTest, addGenderTest){
  std::shared_ptr<GirlBuilder> girlBuilder = std::make_shared<GirlBuilder>();
  girlBuilder->addGender();
  std::shared_ptr<Citizen> girl = girlBuilder->getCitizen();
  ASSERT_NE(girl, nullptr);
  EXPECT_EQ(girl->getGender(), "Female");
}

TEST(GirlBuilderTest, addTypeTest){
  std::shared_ptr<GirlBuilder> girlBuilder = std::make_shared<GirlBuilder>();
  girlBuilder->addType();
  std::shared_ptr<Citizen> girl = girlBuilder->getCitizen();
  ASSERT_NE(girl, nullptr);
  EXPECT_EQ(girl->getType(), "Girl");
}

TEST(GirlBuilderTest, addStatusTestWithValidInput) {
  std::shared_ptr<GirlBuilder> girlBuilder = std::make_shared<GirlBuilder>();

  std::istringstream input("Yes\n");
  std::cin.rdbuf(input.rdbuf());

  girlBuilder->addStatus();
  std::shared_ptr<Citizen> girl = girlBuilder->getCitizen();
  ASSERT_NE(girl, nullptr);
  EXPECT_TRUE(girl->getStatus()); 
}

TEST(GirlBuilderTest, addStatusTestWithInvalidInput) {
  std::shared_ptr<GirlBuilder> girlBuilder = std::make_shared<GirlBuilder>();

  std::istringstream input("Maybe\nno\n");
  std::cin.rdbuf(input.rdbuf());

  girlBuilder->addStatus();
  std::shared_ptr<Citizen> girl = girlBuilder->getCitizen();
  ASSERT_NE(girl, nullptr);
  EXPECT_FALSE(girl->getStatus());
}

// Woman Builder tests and Woman class
TEST(WomanTest, getStatus) {
  std::shared_ptr<Woman> woman = make_shared<Woman>();
  woman->setStatus(false);

  ASSERT_NE(woman, nullptr);
  EXPECT_FALSE(woman->getStatus());
}

TEST(WomanTest, getType) {
  std::shared_ptr<Woman> woman = make_shared<Woman>();
  woman->setType("Woman");

  ASSERT_NE(woman, nullptr);
  EXPECT_EQ(woman->getType(), "Woman");
}

TEST(WomanTest, getGender) {
  std::shared_ptr<Woman> woman = make_shared<Woman>();
  woman->setGender("Female");

  ASSERT_NE(woman, nullptr);
  EXPECT_EQ(woman->getGender(), "Female");
}

TEST(WomanBuilderTest, addGenderTest){
  std::shared_ptr<WomanBuilder> womanBuilder = std::make_shared<WomanBuilder>();
  womanBuilder->addGender();
  std::shared_ptr<Citizen> woman = womanBuilder->getCitizen();
  ASSERT_NE(woman, nullptr);
  EXPECT_EQ(woman->getGender(), "Female");
}

TEST(WomanBuilderTest, addTypeTest){
  std::shared_ptr<WomanBuilder> womanBuilder = std::make_shared<WomanBuilder>();
  womanBuilder->addType();
  std::shared_ptr<Citizen> woman = womanBuilder->getCitizen();
  ASSERT_NE(woman, nullptr);
  EXPECT_EQ(woman->getType(), "Woman");
}

TEST(WomanBuilderTest, addStatusTestWithValidInput) {
  std::shared_ptr<WomanBuilder> womanBuilder = std::make_shared<WomanBuilder>();

  std::istringstream input("Yes\n");
  std::cin.rdbuf(input.rdbuf());

  womanBuilder->addStatus();
  std::shared_ptr<Citizen> woman = womanBuilder->getCitizen();
  ASSERT_NE(woman, nullptr);
  EXPECT_TRUE(woman->getStatus()); 
}

TEST(WomanBuilderTest, addStatusTestWithInvalidInput) {
  std::shared_ptr<WomanBuilder> womanBuilder = std::make_shared<WomanBuilder>();

  std::istringstream input("Maybe\nno\n");
  std::cin.rdbuf(input.rdbuf());

  womanBuilder->addStatus();
  std::shared_ptr<Citizen> woman = womanBuilder->getCitizen();
  ASSERT_NE(woman, nullptr);
  EXPECT_FALSE(woman->getStatus());
}

// Man Builder tests and Man class tests
TEST(ManTest, getStatus) {
  std::shared_ptr<Man> man = make_shared<Man>();
  man->setStatus(true);

  ASSERT_NE(man, nullptr);
  EXPECT_TRUE(man->getStatus());
}

TEST(ManTest, getType) {
  std::shared_ptr<Man> man = make_shared<Man>();
  man->setType("Man");

  ASSERT_NE(man, nullptr);
  EXPECT_EQ(man->getType(), "Man");
}

TEST(ManTest, getGender) {
  std::shared_ptr<Man> man = make_shared<Man>();
  man->setGender("Male");

  ASSERT_NE(man, nullptr);
  EXPECT_EQ(man->getGender(), "Male");
}

TEST(ManBuilderTest, addGenderTest){
  std::shared_ptr<ManBuilder> manBuilder = std::make_shared<ManBuilder>();
  manBuilder->addGender();
  std::shared_ptr<Citizen> man = manBuilder->getCitizen();
  ASSERT_NE(man, nullptr);
  EXPECT_EQ(man->getGender(), "Male");
}

TEST(ManBuilderTest, addTypeTest){
  std::shared_ptr<ManBuilder> manBuilder = std::make_shared<ManBuilder>();
  manBuilder->addType();
  std::shared_ptr<Citizen> man = manBuilder->getCitizen();
  ASSERT_NE(man, nullptr);
  EXPECT_EQ(man->getType(), "Man");
}

TEST(ManBuilderTest, addStatusTestWithValidInput) {
  std::shared_ptr<ManBuilder> manBuilder = std::make_shared<ManBuilder>();

  std::istringstream input("Yes\n");
  std::cin.rdbuf(input.rdbuf());

  manBuilder->addStatus();
  std::shared_ptr<Citizen> man = manBuilder->getCitizen();
  ASSERT_NE(man, nullptr);
  EXPECT_TRUE(man->getStatus()); 
}

TEST(ManBuilderTest, addStatusTestWithInvalidInput) {
  std::shared_ptr<ManBuilder> manBuilder = std::make_shared<ManBuilder>();

  std::istringstream input("Maybe\nno\n");
  std::cin.rdbuf(input.rdbuf());

  manBuilder->addStatus();
  std::shared_ptr<Citizen> man = manBuilder->getCitizen();
  ASSERT_NE(man, nullptr);
  EXPECT_FALSE(man->getStatus());
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}