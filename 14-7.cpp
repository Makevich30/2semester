#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Goods {
public:
    Goods(const string& name, float price, const string& manufacturer, int age) 
        : name(name), price(price), manufacturer(manufacturer), age(age) {}

    virtual void displayInfo() const = 0;
    virtual bool isType(const string& type) const = 0;

protected:
    string name;
    float price;
    string manufacturer;
    int age;
};

class Toy : public Goods {
public:
    Toy(const string& name, float price, const string& manufacturer, const string& material, int age) 
        : Goods(name, price, manufacturer, age), material(material) {}

    void displayInfo() const override {
        cout << "Toy: " << name << ", Price: $" << price << ", Manufacturer: " << manufacturer
             << ", Material: " << material << ", Age Group: " << age << "+ years" << endl;
    }

    bool isType(const string& type) const override {
        return type == "Toy";
    }

private:
    string material;
};

class Book : public Goods {
public:
    Book(const string& name, const string& author, float price, const string& publisher, int age) 
        : Goods(name, price, author, age), author(author), publisher(publisher) {}

    void displayInfo() const override {
        cout << "Book: " << name << ", Author: " << author << ", Price: $" << price
             << ", Publisher: " << publisher << ", Age Group: " << age << "+ years" << endl;
    }

    bool isType(const string& type) const override {
        return type == "Book";
    }

private:
    string author;
    string publisher;
};

class SportsEquipment : public Goods {
public:
    SportsEquipment(const string& name, float price, const string& manufacturer, int age) 
        : Goods(name, price, manufacturer, age) {}

    void displayInfo() const override {
        cout << "Sports Equipment: " << name << ", Price: $" << price << ", Manufacturer: " << manufacturer
             << ", Age Group: " << age << "+ years" << endl;
    }

    bool isType(const string& type) const override {
        return type == "Sports Equipment";
    }
};

int main() {
    vector<Goods*> inventory;
    inventory.push_back(new Toy("Doll", 10.99, "Toy Inc.", "Plastic", 3));
    inventory.push_back(new Book("Harry Potter", "J.K. Rowling", 15.99, "Scholastic", 10));
    inventory.push_back(new SportsEquipment("Football", 19.99, "SportsGear Ltd.", 8));

    cout << "Inventory:" << endl;
    for (const auto& item : inventory) {
        item->displayInfo();
    }

    string searchType = "Toy";
    cout << "\nSearching for " << searchType << ":" << endl;
    for (const auto& item : inventory) {
        if (item->isType(searchType)) {
            item->displayInfo();
        }
    }

    for (const auto& item : inventory) {
        delete item;
    }
    inventory.clear();

    return 0;
}
