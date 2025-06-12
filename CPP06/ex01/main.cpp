#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 42;
    original.name = "Example";

    uintptr_t raw = Serializer::serialize(&original);
    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << &original << std::endl;
    std::cout << "Recovered pointer: " << recovered << std::endl;

    if (recovered == &original) {
        std::cout << "✅ Success: pointers are equals!" << std::endl;
    } else {
        std::cout << "❌ Error: pointers are different!" << std::endl;
    }

    std::cout << "data recovered: ID=" << recovered->id
              << ", Name=" << recovered->name << std::endl;

    return 0;
}
