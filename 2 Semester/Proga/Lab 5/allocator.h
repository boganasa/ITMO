#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdexcept>
#include <variant>
#include <iostream>
template <std::size_t numberOfBlocks>
struct AllocatorStruct{
    template <typename T >
    class Allocator
    {
    private:
        struct Node
        {
            Node* next;
        };
        union Block
        {
            T meaning;
            Node* node;
        };

        std::size_t number{numberOfBlocks};
        std::size_t sizeBlock{sizeof(Block)};

        Block* sizeOfAllocator{NULL};
        Node* lastPointer{NULL};
        Block* startOfAllocator{NULL};
        Block* endOfAllocator{NULL};

    public:
        Allocator()
        {
            sizeOfAllocator = (Block*) ::malloc(sizeBlock * number);
            startOfAllocator = sizeOfAllocator + 0;
            endOfAllocator = startOfAllocator + number;
            lastPointer = reinterpret_cast<Node*>(startOfAllocator);
            lastPointer->next = NULL;
        }

        T* allocate(const std::size_t s = 1)
        {
            T* result = NULL;
            for (std::size_t i = 0; i < s; i++)
            {
                if ((s > number) || (lastPointer == NULL))
                { 
                    throw std::bad_alloc{};
                    std::cout << "Bida";
                }
                if (i == 0) 
                {
                    result = reinterpret_cast<T*>(lastPointer);
                }
                if (lastPointer->next == NULL) 
                { 
                    Block* next_block = reinterpret_cast<Block*>(lastPointer) + 1; 
                    Node* next_node = reinterpret_cast<Node*>(next_block); 

                    if (endOfAllocator > next_block)
                    {
                        lastPointer->next = next_node;
                        next_node->next = NULL;
                    }
                }
            }
            return result;
        }
        
        void deallocate(T* p, std::size_t n) 
        { 
            Block* merge = (Block*)p; 

            if ((startOfAllocator <= merge) && ((merge + n) <= endOfAllocator))
            {
                for (std::size_t i = 0; i < n; i++) {
                    Block *free = merge++;
                    Node *new_node = reinterpret_cast<Node *>(free);

                    new_node->next = lastPointer;
                    lastPointer = new_node;
                }
            }
            else
            {
                throw std::invalid_argument("Error, too few memory");
            }
        }
        using value_type = T;
        template <class U>
        using other = Allocator<U>;
    };
};

#endif