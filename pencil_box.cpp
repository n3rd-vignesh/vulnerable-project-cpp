#include <iostream>

class Pencil {
public:
    Pencil() { std::cout << "Pencil created!" << std::endl; }
    ~Pencil() { std::cout << "Pencil destroyed!" << std::endl; }
};

class Box {
public:
    Box() : count(0), x(new Pencil()) {}
    ~Box() {
        delete x;
        std::cout << "Box destroyed!" << std::endl;
    }

    Box(const Box& rhs) : count(rhs.count), x(new Pencil(*rhs.x)) {} // Correct copy constructor

    Box& operator=(const Box& rhs) {
        if (this == &rhs)
            return *this;

        count = rhs.count;
        Pencil* temp = new Pencil(*rhs.x);
        delete x;
        x = temp;

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
    Box box2 = box1; // Copy initialization

    box1.printCount();
    box2.printCount();

    return 0;
}
