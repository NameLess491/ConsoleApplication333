//1
#include <iostream>

template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Before Swap: x = " << x << ", y = " << y << "\n";
    Swap(x, y);
    std::cout << "After Swap: x = " << x << ", y = " << y << "\n";

    std::string s1 = "Hello", s2 = "World";
    std::cout << "Before Swap: s1 = " << s1 << ", s2 = " << s2 << "\n";
    Swap(s1, s2);
    std::cout << "After Swap: s1 = " << s1 << ", s2 = " << s2 << "\n";

    return 0;
}
//2
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        data.pop_back();
    }

    T peek() const {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    size_t count() const {
        return data.size();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack count: " << stack.count() << "\n";
    std::cout << "Top of stack: " << stack.peek() << "\n";

    stack.pop();
    std::cout << "After pop, top of stack: " << stack.peek() << "\n";
    std::cout << "Stack count: " << stack.count() << "\n";

    return 0;
}

//3
#include <iostream>
#include <queue>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::queue<T> data;

public:
    void enqueue(const T& value) {
        data.push(value);
    }

    void dequeue() {
        if (data.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        data.pop();
    }

    T peek() const {
        if (data.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }

    size_t count() const {
        return data.size();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Queue<std::string> queue;
    queue.enqueue("Alice");
    queue.enqueue("Bob");
    queue.enqueue("Charlie");

    std::cout << "Queue count: " << queue.count() << "\n";
    std::cout << "Front of queue: " << queue.peek() << "\n";

    queue.dequeue();
    std::cout << "After dequeue, front of queue: " << queue.peek() << "\n";
    std::cout << "Queue count: " << queue.count() << "\n";

    return 0;
}
//4
#include <iostream>
#include <vector>
#include <string>

class Cafe {
public:
    struct Employee {
        std::string name;
        std::string position;

        Employee(const std::string& name, const std::string& position)
            : name(name), position(position) {}
    };

private:
    std::vector<Employee> employees;

public:
    void addEmployee(const std::string& name, const std::string& position) {
        employees.emplace_back(name, position);
    }

    // Ітератори
    using iterator = std::vector<Employee>::iterator;
    using const_iterator = std::vector<Employee>::const_iterator;

    iterator begin() { return employees.begin(); }
    iterator end() { return employees.end(); }
    const_iterator begin() const { return employees.begin(); }
    const_iterator end() const { return employees.end(); }

    void display() const {
        for (const auto& employee : employees) {
            std::cout << employee.name << " - " << employee.position << "\n";
        }
    }
};

int main() {
    Cafe cafe;
    cafe.addEmployee("Alice", "Barista");
    cafe.addEmployee("Bob", "Manager");
    cafe.addEmployee("Charlie", "Chef");

    std::cout << "Employees list:\n";
    cafe.display();

    std::cout << "\nUsing foreach loop:\n";
    for (const auto& employee : cafe) {
        std::cout << employee.name << " - " << employee.position << "\n";
    }

    return 0;
}
