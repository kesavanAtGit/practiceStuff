#include <iostream>
#include <chrono>

class Timer {
private:
    using Clock = std::chrono::high_resolution_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<Clock> m_beg{Clock::now()};

public:
    void reset() {
        m_beg = Clock::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

// now this has become a good smart pointer class using moveSemantics
template<typename T>
class Auto_ptr {
private:
    T* m_ptr{};

public:
    Auto_ptr(T* ptr = nullptr)
        :m_ptr{ptr} {}

    ~Auto_ptr() {
        delete m_ptr;
    }

    // a copy constructor that does deep copying
    //Auto_ptr(const Auto_ptr& autoPtr) {
    //    m_ptr = new T;
    //    *m_ptr = *autoPtr.m_ptr;
    //}

    // move construct me daddy
    Auto_ptr(Auto_ptr&& autoPtr) {
        m_ptr = new T;
        *m_ptr = *autoPtr.m_ptr;
        autoPtr.m_ptr = nullptr;
    }

    // a deep copying overloaded assignment operator
    //Auto_ptr& operator=(const Auto_ptr& autoPtr) {
    //    if(&autoPtr == this)
    //        return *this;

    //    delete m_ptr;
    //    m_ptr = new T;
    //    *m_ptr = *autoPtr.m_ptr;
    //    return *this;
    //}

    // move assignment operator
    Auto_ptr& operator=(Auto_ptr&& autoPtr) {
        if(&autoPtr == this)
            return *this;

        delete m_ptr;
        m_ptr = new T;
        *m_ptr = *autoPtr.m_ptr;
        autoPtr.m_ptr = nullptr;
        return *this;
    }

    T& operator*() const {return *m_ptr;}
    T* operator->() const {return m_ptr;}
};

class Resource {
public:
    Resource() {std::cout << "construct me daddy \n";}
    ~Resource() {std::cout << "destruct me daddy \n";}
};

// resource class wrapped smart pointer class
Auto_ptr<Resource> doAllocation() {
    Auto_ptr<Resource> res{new Resource};
    return res;
}

int main() {
    Timer t{};

    Auto_ptr<Resource> res{};
    res = doAllocation();

    std::cout << t.elapsed();
    return 0;
}
