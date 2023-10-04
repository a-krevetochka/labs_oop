#include "string"
class Vector {
public:
    Vector();

    Vector(int n);

    Vector(int n, std::string);

    ~Vector();

    signed char operator[](int i) const;

    void push_back(int x);

    void pop_back();

    int get_size() const;

    int* begin();

    int* end();

    void clear();
private:
    int size;
    int capacity;
    unsigned  char* data;
};