#include <iostream>
#include <string_view>
#include "../include/DNSTypes.h"


// DNS server does not directly store domains, it stores
// DNS Resource Records (RRs)
// This row below is recorded as one record instead of 
// storing std::string doamin, std::string ip:
// google.com   A   142.250.190.14  TTL=300


// Model the concept as a single object

// Abstract Data Types
// An ADT defines what operations can be performed on data 
// and what behavior to expect without specifying how those 
// operations are implemented in code.

// The defining feature of an ADT is the absolute separation 
// between its public specification (interface) and its 
// internal details (implementation).

// Interface (What): This is the user-facing contract defining 
//                  the supported operations, expected parameters,                  
//                  return types, and preconditions/postconditions.

// Implementation (How): The concrete code and data structures 
//                      (arrays, pointers, linked lists) used 
//                      under the hood to store data and 
//                      execute the operations.

// Examples
// Stack (LIFO - Last In, First Out)
// Elements are added and removed from the same end (the top)
// Ops:
// push(x): Insert element x onto the top.
// pop(): Remove and return the top element.
// peek(): Read the top element without removing it.
// isEmpty(): Check if the stack contains elements.
// Possible implementations: Arrays or sinlgy linked lists

// Queue (FIFO - First In, First Out)
// Elements enter at the rear and exit from the front.
// Ops:
// enqueue(x): Insert element x at the rear.
// dequeue(): Remove and return the front element.
// front(): View the rear element.
// Possible implementations: Cicular Array or doubly linked list

// Map/Dictionary (Associative Array)
// Stores key-value pairs where each unique key maps to a specific value.
// Ops:
// insert(key, value): Map key to value
// lookup(key): Retrieve value associated with key
// delete(key): Remove key-vlue mapping
// Possible Implementations: Hash table, binary search tree, or trie

// Priority Queue
// Each element has an associated priority; elements with high 
// priority are served before low priority elements.
// Ops:
// insert(x, p): add element x with priority p
// extractMax(): Remove and return the highest priority element 
// Possible Implementations: Binary Heap, Fibonacci Heap, unsorted Array

// BENEFITS OF USING ADTs

// Encapsulation & Information Hiding: Users cannot directly 
//      modify internal states or rely on memory layout 
//      details.

// Flexibility & Maintainability: The underlying implementation 
//      can be swapped without breaking dependent application 
//      code

// Algorithm Analysis: Allows computer scientists to reason 
//      about algorithm complexity (using Big-O notation) 
//      purely based on the theoretical bounds of the ADT's 
//      interface operations.

// Modern C++ encourages automatic storage duration and RAII.
// Let the compiler manage object lifetimes whenever possible. 


// DNS Record is a value type, meaning that two records with 
// identical contents should be considered identical. A record 
// is simply data with no identity beyond its contents. 
// noneed for polymorphism, inheritence, pointers, and
// dynamic allocation.
class DNSRecord
{
    public:
        DNSRecord(...);
        std::string_view domain() const noexcept;
        // std::string_view: Instead of making an expensive copy 
        // of a string (like returning a std::string), 
        // this function returns a lightweight "view(a pointer + length)"
        // into a string that already exists elsewhere in memory.
        // It's like sending someone a link to a Google Doc 
        // instead of printing out a 50-page copy and mailing it to them.

        // noexcept: tells the compiler (and programmers) that this 
        // function is guaranteed never to throw an exception 
        // (error) during execution.
        // allows the C++ compiler to generate faster, more 
        // optimized machine code.
        dns::RecordType type() const noexcept;
        
        std::string_view value() const noexcept;
        
        dns::TTL tll() const noexcept;
        
        void setTTL(dns::TTL ttl);

        bool matches(std::string_view domain) const noexcept;
    
    private:
        dns::DomainName domain_;

        dns::RecordType type_;

        std::string value_;

        dns::TTL ttl_;

        
};