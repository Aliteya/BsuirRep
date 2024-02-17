#include "Factory.h"
#include "Customer.h"
#include "Human.h"
#include "Supplier.h"
#include "RawMaterial.h"
#include "ProductionLine.h"
#include "Manager.h"
#include "Employee.h"
#include "Engineer.h"
#include "Product.h"

int main(){

  try {
    Factory factory;
    RawMaterial rawMaterial("wood", 5);
    RawMaterial rawMaterial2("wool", 6);
    ProductionLine productionLine;
    Machine machine("Stanok", 221703, "Magic mixer");
    Engineer engineer("John Doe", 123, 50, &factory);
    Manager manager("Jane Smith", 456, 70, &factory);
    Supplier supplier;
    Customer customer;

    Product product = productionLine.manufacture(rawMaterial, rawMaterial2, factory);;
    engineer.work();
    Product producedProduct = engineer.operateMachine(machine, rawMaterial, rawMaterial2, productionLine, factory);
    manager.work();
    manager.add_subordinates(&engineer);
    manager.pay_salary();
    supplier.provide_materials(rawMaterial, factory);
    customer.buy_product(product, factory);
    customer.get_receipt();
    std ::cout << factory.get_profit();
    } catch (const std::string& error_message) {
        std::cout << "Error: " << error_message << std::endl;
    }
    return 0;
}
