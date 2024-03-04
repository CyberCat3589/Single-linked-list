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

    ~SingleLinkedList()
    {
        Clear();
    }

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

    void PushFront(const Type& value)
    {
        head_.next_node = new Node(value, head_.next_node);
        ++size_;
    }

    void Clear() noexcept
    {
        while (head_.next_node != nullptr)
        {
            Node* del_item = head_.next_node;
            head_.next_node = del_item->next_node;
            delete del_item;
            del_item = nullptr;
        }
        size_ = 0;
    }

private:
    Node head_ = Node();
    size_t size_ = 0;
};