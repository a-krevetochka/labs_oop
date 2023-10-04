//
// Created by meteo on 03.10.2023.
//
namespace INumerable{
    template<typename T>
    class INumerable {
        virtual void setValue(std::string value) = 0;

        virtual std::string getValue() const = 0;

        virtual T operator+(const T& right) = 0;

        virtual T operator-(const T& right) = 0;

        virtual bool operator==(const T& right) = 0;

        virtual bool operator<(const T& right) = 0;

        virtual bool operator>(const T& right) = 0;

        virtual T operator=(const T& right) = 0;

        virtual void print() = 0;
    };
}






