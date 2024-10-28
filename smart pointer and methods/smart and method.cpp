#include <iostream>
#include <utility>

template <typename T>
class UniquePtr {
private:
    T* ptr;

public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }


    ~UniquePtr() {
        delete ptr;
    }

    void Swap(UniquePtr& other) noexcept {
        std::swap(ptr, other.ptr);
    }

    T* Release() noexcept {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void Free() noexcept {
        delete ptr;
        ptr = nullptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* Get() const noexcept {
        return ptr;
    }
};

int main()
{

}