#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
  string name;
  int quantity;
  float price;
};

class StockManagementSystem {
 private:
  vector<Product> products;

 public:
  StockManagementSystem() {}

  void addProduct(const Product& product) {
    products.push_back(product);
  }

  void removeProduct(const string& name) {
    for (int i = 0; i < products.size(); i++) {
      if (products[i].name == name) {
        products.erase(products.begin() + i);
        break;
      }
    }
  }

  void updateProductQuantity(const string& name, int quantity) {
    for (int i = 0; i < products.size(); i++) {
      if (products[i].name == name) {
        products[i].quantity = quantity;
        break;
      }
    }
  }

  void updateProductPrice(const string& name, float price) {
    for (int i = 0; i < products.size(); i++) {
      if (products[i].name == name) {
        products[i].price = price;
        break;
      }
    }
  }

  vector<Product> getProducts() { return products; }
};

int main() {
  StockManagementSystem stockManagementSystem;

  Product product1 = {"Pen", 100, 10};
  stockManagementSystem.addProduct(product1);

  Product product2 = {"Paper", 50, 5};
  stockManagementSystem.addProduct(product2);

  stockManagementSystem.updateProductQuantity("Pen", 200);
  stockManagementSystem.updateProductPrice("Paper", 10);

  vector<Product> products = stockManagementSystem.getProducts();

  for (int i = 0; i < products.size(); i++) {
    cout << products[i].name << ", " << products[i].quantity << ", " << products[i].price << endl;
  }

  return 0;
}