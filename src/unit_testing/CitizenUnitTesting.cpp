#include <memory>
#include <string>
#include <iostream>
#include <gtest/gtest.h>

#include "../citizens/Citizen.h"
#include "../citizens/BoyBuilder.h"
#include "../citizens/Boy.h"


/*
TEST(PolicyTest, CanCreateEducationService) {
    // Test the creation of Education service
    shared_ptr<Education> education = make_shared<Education>();
    EXPECT_EQ(education->getTypeOfPublicService(), "Education")
        << "Expected the type of public service to be 'Education'.";
}
*/

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

    // Simulate "Yes" input
    std::istringstream input("Yes\n");
    std::cin.rdbuf(input.rdbuf());  // Redirect std::cin

    boyBuilder->addStatus();
    std::shared_ptr<Citizen> citizen = boyBuilder->getCitizen();
    ASSERT_NE(citizen, nullptr);

    std::shared_ptr<Boy> boy = std::dynamic_pointer_cast<Boy>(citizen);
    ASSERT_NE(boy, nullptr);
    EXPECT_TRUE(boy->getStatus());  // Expect the boy to be in school
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}