#include "fabriic_system.h"
#include<gtest/gtest.h>

TEST(FactoryTest, ProfitManagement) {
    Factory factory("Test", 500);
    EXPECT_EQ(factory.get_profit(), 500);

    factory.add_profit(200);
    EXPECT_EQ(factory.get_profit(), 700);

    factory.subtract_profit(300);
    EXPECT_EQ(factory.get_profit(), 400);
}

TEST(RawMaterialTest, InvalidMaterial) {
    EXPECT_THROW(RawMaterial material("invalid_material", 10), std::runtime_error);
}

TEST(ProductionLineTest, ProductManufacturing) {
    RawMaterial mater1("wood", 10);
    RawMaterial mater2("wool", 10);
    Factory factory("Test", 500);
    ProductionLine line;
    Product product = line.manufacture(mater1, mater2, factory);
    EXPECT_EQ(product.product_name, "bed");
}

TEST(MachineTest, ProductionProcess) {
    RawMaterial mater1("wood", 10);
    RawMaterial mater2("wool", 10);
    Factory factory("Test", 500);
    ProductionLine line;
    Machine machine("TestMachine", 123, "TestType");

    EXPECT_EQ(machine.get_status(), 0);

    Product product = machine.produce(mater1, mater2, line, factory);

    EXPECT_EQ(product.product_name, "bed");
    EXPECT_EQ(machine.get_status(), 0);
}

TEST(EngineerTest, OperateMachine) {
    RawMaterial mater1("wood", 10);
    RawMaterial mater2("wool", 10);
    Factory factory("Test", 500);
    ProductionLine line;
    Machine machine("TestMachine", 123, "TestType");
    Engineer engineer("Jane Doe", 124, 3000, &factory);

    Product product = engineer.operateMachine(machine, mater1, mater2, line, factory);

    EXPECT_EQ(product.product_name, "bed");
}

TEST(ManagerTest, PaySalary) {
    Factory factory("Test", 5000);
    Engineer engineer1("Eng1", 125, 2000, &factory);
    Engineer engineer2("Eng2", 126, 2000, &factory);
    Manager manager("Man1", 127, 4000, &factory);

    manager.add_subordinates(&engineer1);
    manager.add_subordinates(&engineer2);

    EXPECT_NO_THROW(manager.pay_salary());
    EXPECT_EQ(factory.get_profit(), 1000);
}

TEST(SupplierTest, ProvideMaterials) {
    RawMaterial mater1("wood", 10);
    Factory factory("Test", 5000);
    Supplier supplier;

    EXPECT_NO_THROW(supplier.provide_materials(mater1, factory));
    EXPECT_EQ(mater1.amount, 15);
}

TEST(CustomerTest, BuyProduct) {
    RawMaterial mater1("wood", 10);
    RawMaterial mater2("wool", 10);
    Factory factory("Test", 500);
    ProductionLine line;
    Machine machine("TestMachine", 123, "TestType");
    Engineer engineer("Jane Doe", 124, 3000, &factory);
    Customer customer;

    Product product = engineer.operateMachine(machine, mater1, mater2, line, factory);
    customer.buy_product(product, factory);

    EXPECT_EQ(factory.get_profit(), 600);
    EXPECT_EQ(customer.cost, 100);
}

TEST(CustomerTest, GetReceipt) {
    RawMaterial mater1("wood", 10);
    RawMaterial mater2("wool", 10);
    Factory factory("Test", 500);
    ProductionLine line;
    Machine machine("TestMachine", 123, "TestType");
    Engineer engineer("Jane Doe", 124, 3000, &factory);
    Customer customer;

    Product product = engineer.operateMachine(machine, mater1, mater2, line, factory);
    customer.buy_product(product, factory);

    EXPECT_NO_THROW(customer.get_receipt());
}