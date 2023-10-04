#include<string>
#include <iostream>
#include "INumerable.h"
#include "vector.h"

namespace octal{
    class Octal : INumerable::INumerable<Octal> {
    private:
        Vector vector;
    public:
        Octal();

        Octal(std::string value);

        void setValue(std::string parameter) override;

        std::string getValue() const override;

        Octal operator+(const Octal& right) override;

        Octal operator-(const Octal& right) override;

        bool operator==(const Octal& right) override;

        bool operator<(const Octal& right) override;

        bool operator>(const Octal& right) override;

        Octal operator=(const Octal& right) override;

        ~Octal();

        friend std::ostream &operator<<(std::ostream & ostream, const Octal &octal);
    };
}


