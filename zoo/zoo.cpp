
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Animal {
protected:
    string name;
    size_t age;

public:
    Animal(const string& name, size_t age) : name(name), age(age) {}
    virtual ~Animal() {}


    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    size_t getAge() const { return age; }
    void setAge(size_t age) { this->age = age; }


    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const = 0;
};


class Cat : public Animal {
    string color;

public:
    Cat(const string& name, size_t age, const string& color)
        : Animal(name, age), color(color) {}

    void sound() const override { cout << "Meow" << endl; }
    void type() const override { cout << "Cat" << endl; }
    void show() const override {
        cout << "Type: Cat\nName: " << name << "\nAge: " << age << "\nColor: " << color << endl;
    }
};


class Dog : public Animal {
    string breed;

public:
    Dog(const string& name, size_t age, const string& breed)
        : Animal(name, age), breed(breed) {}

    void sound() const override { cout << "Woof" << endl; }
    void type() const override { cout << "Dog" << endl; }
    void show() const override {
        cout << "Type: Dog\nName: " << name << "\nAge: " << age << "\nBreed: " << breed << endl;
    }
};


class Parrot : public Animal {
    string color;

public:
    Parrot(const string& name, size_t age, const string& color)
        : Animal(name, age), color(color) {}

    void sound() const override { cout << "Squawk" << endl; }
    void type() const override { cout << "Parrot" << endl; }
    void show() const override {
        cout << "Type: Parrot\nName: " << name << "\nAge: " << age << "\nColor: " << color << endl;
    }
};


class Hamster : public Animal {
    string favoriteFood;

public:
    Hamster(const string& name, size_t age, const string& favoriteFood)
        : Animal(name, age), favoriteFood(favoriteFood) {}

    void sound() const override { cout << "Squeak" << endl; }
    void type() const override { cout << "Hamster" << endl; }
    void show() const override {
        cout << "Type: Hamster\nName: " << name << "\nAge: " << age << "\nFavorite Food: " << favoriteFood << endl;
    }
};


class HomeZoo {
    vector<Animal*> zoo;

public:
    HomeZoo() = default;

    ~HomeZoo() {
        for (auto animal : zoo) {
            delete animal;
        }
        zoo.clear();
    }

    void addAnimal(Animal* animal) {
        zoo.push_back(animal);
    }

    void addRandomAnimals() {
        zoo.push_back(new Cat("Murka", 2, "White"));
        zoo.push_back(new Dog("Rex", 3, "Labrador"));
        zoo.push_back(new Parrot("Kesha", 1, "Green"));
        zoo.push_back(new Hamster("Fluffy", 1, "Seeds"));
    }

    void showAllAnimals() const {
        for (const auto& animal : zoo) {
            animal->show();
            cout << "----------------------\n";
        }
    }

    void editAnimal(size_t index, const string& newName, size_t newAge) {
        if (index < zoo.size()) {
            zoo[index]->setName(newName);
            zoo[index]->setAge(newAge);
        }
        else {
            cout << "Invalid index!" << endl;
        }
    }

    void removeAnimal(size_t index) {
        if (index < zoo.size()) {
            delete zoo[index];
            zoo.erase(zoo.begin() + index);
        }
        else {
            cout << "Invalid index!" << endl;
        }
    }

    void removeAllAnimals() {
        for (auto animal : zoo) {
            delete animal;
        }
        zoo.clear();
    }
};
int main()
{
    HomeZoo myZoo;
    
    myZoo.addRandomAnimals();


    cout << "All animals in the zoo:\n";
    myZoo.showAllAnimals();


    cout << "Editing the first animal...\n";
    myZoo.editAnimal(0, "MurkaUpdated", 3);


    myZoo.showAllAnimals();


    cout << "Removing the second animal...\n";
    myZoo.removeAnimal(1);


    myZoo.showAllAnimals();
}

