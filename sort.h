#ifndef SORT_H
#define SORT_H

#include <memory>
#include <vector>

template <typename T> struct TreeNode
{
    TreeNode(const T& d);

    T data;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;
};

template <typename T> class Sort
{
public:
    Sort() = default;
    ~Sort() = default;

    static void sort(std::vector<T>& array);

private:
    static void push(const T& data,
                     std::shared_ptr<TreeNode<T>>& t);
    static void read(std::vector<T>& array,
                     const std::shared_ptr<TreeNode<T>>& t);
};

template <typename T>
TreeNode<T>::TreeNode(const T& d)
{
    data = d;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void Sort<T>::push(const T& data,
                   std::shared_ptr<TreeNode<T>>& t)
{
   if (!t)
   {
       t = std::shared_ptr<TreeNode<T>>(new TreeNode<T>(data));
   }
   else if (t->data < data)
       push(data, t->right);
   else
       push(data, t->left);
}

template <typename T>
void Sort<T>::read(std::vector<T>& array,
                   const std::shared_ptr<TreeNode<T>>& t)
{
    if (t == nullptr) return;
    read(array, t->left);
    array.push_back(t->data);
    read(array, t->right);
}

template <typename T>
void Sort<T>::sort(std::vector<T>& array)
{
    std::shared_ptr<TreeNode<T>> t = nullptr;
    for(size_t i = 0; i < array.size(); i++)
    {
        push(array[i], t);
    }
    array.clear();
    read(array, t);
}

#endif // SORT_H
