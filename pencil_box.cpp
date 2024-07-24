#include <iostream>

class Pencil {
public:
    Pencil() { std::cout << "Pencil created!" << std::endl; }
    ~Pencil() { std::cout << "Pencil destroyed!" << std::endl; }
};

class Box {
public:
    Box() : count(0), x(nullptr) {}
    ~Box() {
        delete x; // Deleting memory pointed to by x
        std::cout << "Box destroyed!" << std::endl;
    }

    Box& operator=(const Box& rhs) {
        if (this == &rhs)
            return *this;

        count = rhs.count;
        delete x; // Deleting existing memory before assigning new memory

        // Vulnerable: Accessing x after deletion
        x = new Pencil(*rhs.x); // Creating a new Pencil object from rhs

        return *this;
    }

    void printCount() const {
        std::cout << "Count: " << count << std::endl;
    }

private:
    int count;
    Pencil* x;
};

int main() {
    Box box1;
    Box box2;

    // Assigning box2 to box1 (potential UAF vulnerability)
    box1 = box2;

    box1.printCount(); // Accessing count in box1
    return 0;
}