#ifndef SORTPROTECTED_H
#define SORTPROTECTED_H

#include <memory>
#include <vector>

template <typename T> struct Node
{
    Node(const std::shared_ptr<T>& d);

    std::shared_ptr<T> data;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
};

template <typename T> class SortProtected
{
public:
    SortProtected() = default;
    ~SortProtected() = default;

    static void sort(std::vector<std::shared_ptr<T>>& array);

private:
    static void push(const std::shared_ptr<T>& data,
                     std::shared_ptr<Node<T>>& t);
    static void read(std::vector<std::shared_ptr<T>>& array,
                     const std::shared_ptr<Node<T>>& t);
};

template <typename T>
Node<T>::Node(const std::shared_ptr<T>& d)
{
    data = d;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void SortProtected<T>::push(const std::shared_ptr<T>& data,
                            std::shared_ptr<Node<T>>& t)
{
   if (!t)
   {
       t = std::shared_ptr<Node<T>>(new Node<T>(data));
   }
   else if (*(t->data) < *(data))
       push(data, t->right);
   else
       push(data, t->left);
}

template <typename T>
void SortProtected<T>::read(std::vector<std::shared_ptr<T>>& array,
                   const std::shared_ptr<Node<T>>& t)
{
    if (t == nullptr) return;
    read(array, t->left);
    array.push_back(t->data);
    read(array, t->right);
}

template <typename T>
void SortProtected<T>::sort(std::vector<std::shared_ptr<T>>& array)
{
    std::shared_ptr<Node<T>> t = nullptr;
    for(size_t i = 0; i < array.size(); i++)
    {
        push(array[i], t);
    }
    array.clear();
    read(array, t);
}


#endif // SORTPROTECTED_H
