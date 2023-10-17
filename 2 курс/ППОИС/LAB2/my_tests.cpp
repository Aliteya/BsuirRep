#include "gtest/gtest.h"
#include "auto_repair_shop.h"

TEST(AutoRepairShopTest, GreetTest){
    auto_repair_shop my_shop("CarFix");
    std::string expected_output = "Welcome to our repair shop CarFix\nOur prices: engine repair 450, suspension repair 300, battery repair 50, brakers repair 150\n";
    testing::internal::CaptureStdout();
    my_shop.greet();
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected_output, actual_output);
}

TEST(AutoRepairShopTest, SeeYaTest){
    auto_repair_shop my_shop;
    my_shop.car_counter = 5;
    std::string expected_output = "we help 5 cars\n";
    testing::internal::CaptureStdout();
    my_shop.see_ya();
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected_output, actual_output);
}

TEST(EngineTest, PartSayTest){
    Engine my_engine;
    my_engine.condition = 0;
    std::string expected_output = "engine say BTOOOOOOM\n";
    testing::internal::CaptureStdout();
    my_engine.part_say();
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected_output, actual_output);
}

TEST(SuspensionTest, PartSayTest){
    Suspension my_suspension;
    my_suspension.condition = 0;
    std::string expected_output = "suspension say PSSSSSSSSSSGGGIIII\n";
    testing::internal::CaptureStdout();
    my_suspension.part_say();
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected_output, actual_output);
}

TEST(BatteryTest, PartSayTest){
    Battery my_battery;
    my_battery.condition = 0;
    std::string expected_output = "battery say PICPICPIC\n";
    testing::internal::CaptureStdout();
    my_battery.part_say();
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected_output, actual_output);
}

TEST(BatteryTest, PartRepairTest){
    Battery my_battery;
    my_battery.condition = 0;
    testing::internal::CaptureStdout();
    my_battery.part_repair();
    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(actual_output.find("The battery is charging, please wait") != std::string::npos);
    EXPECT_TRUE(actual_output.find("battery is 100 percent charged\n") != std::string::npos);
}
 
TEST(EngineTest, PartSay){
  Engine engine;
  engine.condition = 0;
  testing::internal::CaptureStdout();
  engine.part_say();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "engine say BTOOOOOOM\n");
}

TEST(SuspensionTest, PartSay){
  Suspension suspension;
  suspension.condition = 0;
  testing::internal::CaptureStdout();
  suspension.part_say();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "suspension say PSSSSSSSSSSGGGIIII\n");
}

TEST(BrakesTest, PartSay){
  Brakes brakes;
  brakes.condition = 0;
  testing::internal::CaptureStdout();
  brakes.part_say();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "brakers say ATTENTION FIRE ON THE FLOOR\n");
}

TEST(BrakesTest, PartRepair){
  Brakes brakes;
  brakes.condition = 0;
  testing::internal::CaptureStdout();
  brakes.part_repair();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "A cool car doesn't need brakes\n");
}

TEST(CarTest, CarSay){
  car my_car("Mitsubishi Carisma 1997", 1, 1, 1, 1);
  testing::internal::CaptureStdout();
  my_car.car_say();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "your car Mitsubishi Carisma 1997 normally working\n");
}

TEST(CarTest, MakeExpList){
  auto_repair_shop shop;
  car my_car("Mitsubishi Carisma 1997", 1, 1, 1, 1);
  my_car.make_exp_list(shop);
  EXPECT_EQ(shop.our_exp.size(), 1);
  EXPECT_EQ(shop.our_exp[0].first, "Mitsubishi Carisma 1997");
  EXPECT_EQ(shop.our_exp[0].second, 1);
}

TEST(OrdinaryWorkerTest, StartCheckIntact){
  auto_repair_shop shop;
  shop.engine_price = 100;
  shop.suspension_price = 200;
  shop.battery_price = 50;
  shop.brakers_price = 150;
  car my_car("Mitsubishi Carisma 1997", 1, 1, 1, 1);
  master mymaster("Ryan Gosling");
  ordinary_worker worker("John Doe");
  testing::internal::CaptureStdout();
  worker.start_check(my_car, mymaster, shop);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Your car is intact\n");
}

TEST(CashierTest, ProfitCheck){
  auto_repair_shop shop;
  shop.profit = 500;
  cashier mycashier("Ryan Gosling");
  testing::internal::CaptureStdout();
  mycashier.profit_check(shop);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Our profit: 500BYN\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}