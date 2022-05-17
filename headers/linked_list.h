
/*
 * @Author: Jerry
 * @Date: 2022/5/16.
*/

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
/* ownership checking is not necessary for low-level data structures, like LinkedList
 * Ref: https://stackoverflow.com/questions/62647338/c-warning-assigning-newly-created-gslowner-to-non-owner
 * However, using smart pointer when transferring ownership of object is a good practise.
 */
#pragma once
#include <array>

template<class T>
class ListNode {
public:
    T val;
    ListNode *next;

    explicit ListNode(T val, ListNode* next): val(val), next(next) {};
};

template<class T>
class LinkedList {
private:
    ListNode<T>* _startNode = nullptr;
    std::size_t _size = 0;
public:
    std::size_t size() const {
        return this->_size;
    }

    ListNode<T>* getHeadNode() const {
        return this->_startNode;
    }

    T at(std::size_t index) {
        if (index < 0 || index > this->_size) {
            throw std::invalid_argument("Index Out of Range");
        }
        auto current = this->_startNode;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->val;
    }

    void add(T val) {
        auto node = this->_startNode;
        auto newNode = new ListNode<T>(val, nullptr);
        this->_size += 1;

        if (node == nullptr) {
            this->_startNode = newNode;
            return;
        }

        while(node->next != nullptr) {
            node = node->next;
        }
        node->next = newNode;
    }

    template<class... Arg>
    static std::unique_ptr<LinkedList<T>> of(Arg... args) {
        std::array<int, sizeof...(args)> argList {args...};
        auto resultList = std::make_unique<LinkedList<T>>();

        for(auto arg: argList) {
            resultList->add(arg);
        }

        return resultList;
    }


    ~LinkedList() {
       auto next = _startNode;
       while (next != nullptr) {
           auto current = next;
           next = next->next;
           delete current;
       }
    }
};
