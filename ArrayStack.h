#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {

        data.push_back(value);

    }

    void pop() {

        if (data.empty())
        {
            cout << "ArrayStack is empty" << endl;
        } else
        {
            data.pop_back();
        }

    }

    T top() const {

        if (data.empty())
        {
            cout << "ArrayStack is empty" << endl;
        } else
        {
            return data.back();
        }

    }

    bool empty() const {

        if (data.empty())
        {
            return true;
        } else
        {
            return false;
        }

    }

    int size() const {

        if (data.empty())
        {
            cout << "ArrayStack is empty" << endl;
        } else
        {
            return data.size();
        }

    }
};

#endif
