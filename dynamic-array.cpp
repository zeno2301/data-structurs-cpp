/*
Динамический массив - отличается от статического тем что его вместимость 
можно увеличивать во время работы программы


std::vector<std::string> names; // динамический массив в С++ 




*/

#include <iostream>


class DynamicArray {
private:
    int* data_; // уазатель на динамический массив в куче, хранит адрес самой первой ячейки памяти, где лежат числа 
    size_t size_; // текущее кол-во добавленных элементов 
    size_t capacity_; // общая вместимость выделенной памяти 

public:
    DynamicArray() // конструктор по умолчанию, вызывается при создании обьекта 
        : data_(nullptr),
          size_(0),
          capacity_(0) {}

    ~DynamicArray() { // дестркутор освобождающий динамическую память в кучи 
        delete[] data_; 
    }

    void push_back(int value) { // метод добавления элемента 
        if (size_ == capacity_) { // если массив полностью заполнен то мы вызываем приватный метож для расширения памяти
            increase_capacity();
        }

        data_[size_] = value; // записываем число в свободную ячейку  (индекс св. яч. равен текущ. сайз)
        ++size_;
    }

    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    int& operator[](int index) {
        return data_[index];
    }


    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

private:
    void increase_capacity() {
        int new_capacity {};

        if (capacity_ == 0) {
            new_capacity = 1;
        } else {
            new_capacity = capacity_ * 2;
        }

        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        delete[] data_;

        data_ = new_data;
        capacity_ = new_capacity;
    }


};



int main() 
{
    DynamicArray numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(40);
    numbers.push_back(70);
    numbers.pop_back();


    for (size_t i = 0; i < numbers.size(); ++i ){
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << numbers.capacity() << std::endl;

    numbers.push_back(30);
    numbers.push_back(30);
    for (size_t i = 0; i < numbers.size(); ++i ){
        std::cout << numbers[i] << " ";
    }
    std::cout << numbers.capacity() << std::endl;
    std::cout << std::endl;
}