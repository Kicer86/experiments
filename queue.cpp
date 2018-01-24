
#include <iostream>


template<typename T>
class TS_ListHead final
{
    public:
        TS_ListHead(): m_first(nullptr), m_last(nullptr)
        {

        }

        ~TS_ListHead()
        {
            for (Node* n = m_first; n != nullptr; )
            {
                Node* next = n->next;

                delete n;

                n = next;
            }
        }

        void push(const T& item)
        {
            Node* node = new Node;
            node->data = item;
            node->next = m_first;

            if (m_last == nullptr)
                m_last = node;

            m_first = node;
        }


    private:
        struct Node
        {
            T data;

            Node* next;
        };

        Node* m_first;
        Node* m_last;
};


int main(int argc, char **argv)
{
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
