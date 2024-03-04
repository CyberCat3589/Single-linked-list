#include <cstddef>

template <typename Type>
class SingleLinkedList
{
    struct Node
    {
        Node() = default;
        Node(const Type& val, Node* next) : value(val), next_node(next){}
        Type value;
        Node* next_node = nullptr;
    };

public:
    SingleLinkedList() = default;

    // Возвращает количество элементов в списке
    [[nodiscard]] size_t GetSize() const noexcept
    {
        return size_;
    }

    // Сообщает, пустой ли список
    [[nodiscard]] bool IsEmpty() const noexcept
    {
        return size_ > 0 ? false : true;
    }

private:
    Node head_ = Node();
    size_t size_ = 0;
};