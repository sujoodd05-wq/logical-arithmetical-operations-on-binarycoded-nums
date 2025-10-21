#include "Bits.h"
#include <iostream>
#include "BitNode.h"
#include "stack"
#include "queue"
#include <math.h>
using namespace std;



//*********...I did the linked list to be from (MSB) to (LSB)...*********

//constructor by parameter.....
Bits:: Bits(int num)
{
 
    head = nullptr;
    if (num == 0) {
        head = new BitNode();
        head = 0;
        return;
    }
    while (num > 0) {
        BitNode* newNode = new BitNode();
        newNode->bit = num % 2; 
        newNode->next = head;
        head = newNode;
        num /= 2;
    }

}

//defult consrtuctor...
Bits::Bits()
{
    head = new BitNode();
    head->bit = 0;
   
}

//copy constructor....
Bits::Bits(const Bits&b)
{
    
        BitNode* p1 = b.head;
        head = nullptr;  // Initialize head
        BitNode* tail = nullptr;

        while (p1 != nullptr) {
            BitNode* newNode = new BitNode();
            newNode->bit = p1->bit;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
                tail = head;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }

            p1 = p1->next;
        }
    }


//destructor....
Bits::~Bits()
{
    while (head) {
        BitNode* temp = head;
        head = head->next;
        delete temp;
    }
}

//assighnment operator...
Bits Bits::operator=(const Bits & cbit)
{

    //Clear existing linked list
    while (head) {
        BitNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Use stack to reverse the order of bits
    stack<bool> bitStack;
    BitNode* p1 = cbit.head;
    while (p1!=nullptr) {
        bitStack.push(p1->bit); 
        p1 = p1->next;
    }
    //stack to linkedlist
    head = nullptr;
    BitNode* last = nullptr;
    while (!bitStack.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit=bitStack.top();
        bitStack.pop();

        if (head==nullptr) {
            head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode; 
            last = newNode;
        }
       
    }
    
    return *this;
}

//assignment operator with number 
Bits Bits::operator=(int num)
{
    // Clear existing list
    while (head) {
        BitNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Handle number 0 case
    if (num == 0) { 
        head = new BitNode();
        head->bit = 0;
        return *this;
    }
    stack<bool>bitstack;
    while (num > 0) {
        bitstack.push(num % 2);
        num=num / 2;
    }
    head = nullptr;
    BitNode* last = nullptr;
    while (!bitstack.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = bitstack.top();
        bitstack.pop();

        if (head == nullptr) {
            head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode;  
            last = newNode;
        }

    }

    return *this;

}


//**Arithmatic functios**
Bits Bits::operator+(const Bits&o)
{ 
    BitNode* p1 = head;
    BitNode* p2 = o.head;
    stack<bool>s1, s2, s3;
  
    int sum = 0, carry = 0;
    
    while (p1 != nullptr) {
        s1.push(p1->bit);
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        s2.push(p2->bit);
        p2 = p2->next;
    }
    
    while (!s1.empty() || !s2.empty()|| carry) {
        int num1=0, num2=0;
        if (!s1.empty()) {
            num1 = s1.top();
            s1.pop();
        }
        
        if (!s2.empty()) {
            num2 = s2.top();
            s2.pop();
        }
    

        sum = num2 + num1 + carry;
        s3.push(sum % 2);
        carry = sum / 2;
      
     }
    if (carry) {
        s3.push(1);
    }
    Bits temp;
    temp.head = nullptr;
    BitNode* last = nullptr;
    while (!s3.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = s3.top();
        s3.pop();

        if (temp.head == nullptr) {
            temp.head = newNode; 
            last = newNode;
        }
        else {
            last->next = newNode; 
            last = newNode;
        }

    }

    return temp;
   
    }

int Bits::operator-(const Bits&b)
{
    stack<bool> s1, s2;
    BitNode* p1 = head;
    BitNode* p2 = b.head;

    while (p1) {
        s1.push(p1->bit);
        p1 = p1->next;
    }
    while (p2) {
        s2.push(p2->bit);
        p2 = p2->next;
    }

    int d = 0;
    
        while (!s1.empty() || !s2.empty()) {
            int num1 = 0, num2 = 0;
            if (!s1.empty()) {
                num1 = s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                num2 = s2.top();
                s2.pop();
            }

            if (num1 != num2) {
                d++;
            }
        }
        return d;
}

//left shift functions$$$
Bits Bits::operator<<(int shift)
{
    Bits result;
    BitNode* p1 = head;
    queue<bool>q1;
    while (p1 != nullptr) {
        q1.push(p1->bit);
        p1 = p1->next;
    }
    for (int i = 0; i < shift; i++) {
        q1.push(0);
    }
    result.head = nullptr;
    BitNode* last = nullptr;
    while (!q1.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = q1.front();
        q1.pop();

        if (result.head == nullptr) {
            result.head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode;  
            last = newNode;
        }
    }
    return result;
}

Bits Bits::operator<<(Bits& o)
{
    BitNode* p1 = head;
    BitNode* p2 = o.head;
    queue<bool>q1, q2;

    while (p1 != nullptr) {
        q1.push(p1->bit);
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        q2.push(p2->bit);
        p2 = p2->next;
    }

    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    while (!q1.empty() && q1.front() == 0) {
        q1.pop();
    }
    Bits result;
    result.head = nullptr;
    BitNode* last = nullptr;
    while (!q1.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = q1.front();
        q1.pop();

        if (result.head == nullptr) {
            result.head = newNode; 
            last = newNode;
        }
        else {
            last->next = newNode;  
            last = newNode;
        }
    }
    return result;

}

ostream& operator<<(ostream& os, const Bits& bits) {

    queue<int> q;
    BitNode* temp = bits.head;

    // Push bits into the queue
    while (temp) {
        q.push(temp->bit);
        temp = temp->next;
    }

    // Pop bits from the queue and write to ostream
    while (!q.empty()) {
        os << q.front();
        q.pop();
    }

    return os;
}

//right shift functions$$$
Bits Bits::operator>>(int shift)
{
    Bits result;
    BitNode* p1 = head;
    stack<bool>q1, s;
    while (p1 != nullptr) {
        q1.push(p1->bit);
        p1 = p1->next;
    }
    for (int i = 0; i < shift; i++) {
        q1.pop();
    }
    while (!q1.empty()) {
        s.push(q1.top());
        q1.pop();
    }
    result.head = nullptr;
    BitNode* last = nullptr;
    while (!s.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = s.top();
        s.pop();

        if (result.head == nullptr) {
            result.head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode;  
            last = newNode;
        }
    }
    return result;

}

Bits Bits::operator>>(Bits& o)
{
    BitNode* p1 = head;
    BitNode* p2 = o.head;
    queue<bool>q1, q2;

    while (p1 != nullptr) {
        q1.push(p1->bit);
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        q2.push(p2->bit);
        p2 = p2->next;
    }

    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    while (!q1.empty() && q1.front() == 0) {
        q1.pop();
    }
    Bits result;
    result.head = nullptr;
    BitNode* last = nullptr;
    while (!q2.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = q2.front();
        q2.pop();

        if (result.head == nullptr) {
            result.head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode;  
            last = newNode;
        }
    }
    return result;

}

istream& operator>>(istream& is, Bits& b)
{
    int num;
    is >> num;
    stack<bool>s1;
    if (num == 0) {
        s1.push(0);
        // Handle special case for zero

    }
    else {
        while (num > 0) {
            s1.push(num % 2);  // Extract LSB and insert at front
            num /= 2;
        }
    }

    b.head = nullptr;
    BitNode* last = nullptr;

    while (!s1.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = s1.top();
        s1.pop();

        if (b.head == nullptr) {
            b.head = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }
    while (!s1.empty()) {
        is >> s1.top();
        s1.pop();
    }


    return is;
}

//*********LOGICAL OPERATORS*********
Bits Bits::operator&(const Bits& o)
{
    BitNode* p1 = head;
    BitNode* p2 = o.head;
    stack<bool>s1, s2, s3;

    int sum = 0, carry = 0;

    while (p1 != nullptr) {
        s1.push(p1->bit);
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        s2.push(p2->bit);
        p2 = p2->next;
    }

    while (!s1.empty() || !s2.empty() || carry) {
        int num1 = 0, num2 = 0;
        if (!s1.empty()) {
            num1 = s1.top();
            s1.pop();
        }

        if (!s2.empty()) {
            num2 = s2.top();
            s2.pop();
        }
        s3.push(num1 & num2); 
    }
    //Remove zeros from the MSB
    while (!s3.empty() && s3.top() == 0) {
        s3.pop();
    }
    Bits temp;
    temp.head = nullptr;
    BitNode* last = nullptr;
    while (!s3.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = s3.top();
        s3.pop();

        if (temp.head == nullptr) {
            temp.head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode;  
            last = newNode;
        }

    }

    return temp;

}

Bits Bits::operator|(const Bits&o)
{
    BitNode* p1 = head;
    BitNode* p2 = o.head;
    stack<bool>s1, s2, s3;
    
    int sum = 0, carry = 0;

    while (p1 != nullptr) {
        s1.push(p1->bit);
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        s2.push(p2->bit);
        p2 = p2->next;
    }

    while (!s1.empty() || !s2.empty() || carry) {
        int num1 = 0, num2 = 0;
        if (!s1.empty()) {
            num1 = s1.top();
            s1.pop();
        }

        if (!s2.empty()) {
            num2 = s2.top();
            s2.pop();
        }
        s3.push(num1 | num2);
    }
    //Remove zeros from the MSB
    while (!s3.empty() && s3.top() == 0) {
        s3.pop();
    }
    Bits temp;
    temp.head = nullptr;
    BitNode* last = nullptr;
    while (!s3.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = s3.top();
        s3.pop();

        if (temp.head == nullptr) {
            temp.head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode; 
            last = newNode;
        }

    }

    return temp;

}

Bits Bits::operator^(const Bits&o)
{
    BitNode* p1 = head;
    BitNode* p2 = o.head;
    stack<bool>s1, s2, s3;
    
    int sum = 0, carry = 0;

    while (p1 != nullptr) {
        s1.push(p1->bit);
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        s2.push(p2->bit);
        p2 = p2->next;
    }

    while (!s1.empty() || !s2.empty() || carry) {
        int num1 = 0, num2 = 0;
        if (!s1.empty()) {
            num1 = s1.top();
            s1.pop();
        }

        if (!s2.empty()) {
            num2 = s2.top();
            s2.pop();
        }
        s3.push(num1 ^ num2);
    }
    //Remove zeros from the MSB
    while (!s3.empty() && s3.top() == 0) {
        s3.pop();
    }
    Bits temp;
    temp.head = nullptr;
    BitNode* last = nullptr;
    while (!s3.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = s3.top();
        s3.pop();

        if (temp.head == nullptr) {
            temp.head = newNode;  
            last = newNode;
        }
        else {
            last->next = newNode;  
            last = newNode;
        }

    }

    return temp;

}

Bits Bits::operator!()
{
    BitNode* p1 = head;
    queue<bool> q1;

    while (p1 != nullptr) {
        q1.push(!p1->bit);
        p1 = p1->next;
    }

    while (!q1.empty() && q1.front() == 0) {
       q1.pop();
    }
    if (q1.empty()) {  // If queue becomes empty, push a single zero bit
        q1.push(0);
    }

    Bits temp;
    temp.head = nullptr;
    BitNode* last = nullptr;

    while (!q1.empty()) {
        BitNode* newNode = new BitNode();
        newNode->bit = q1.front();
        q1.pop();

        if (temp.head == nullptr) {
            temp.head = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    return temp;
}
  
//Friends functions...
    char* toString(Bits& b) {
        queue<int> s;
        BitNode* p = b.head;

        // Push all bits onto the stack to reverse order
        while (p != nullptr) {
            s.push(p->bit);
            p = p->next;
        }

        // array of chars for the bitstring
        int size = s.size();
        char* result = new char[size + 1];  // +1 for /0
        int index = 0;

        while (!s.empty()) {
            result[index++] = s.front() + '0';  // Convert bit to character ('0' or '1')
            s.pop();
        }

        result[index] = '\0';  
        return result;
    }

    int toDecimal(Bits& b) {
        BitNode* p = b.head;
        int decimalValue = 0;
        int power = 0;
        stack<bool>q;
        while (p != nullptr) {
            q.push(p->bit);
            p = p->next;
        }
        // Traverse the linked list and compute the decimal value
        while (!q.empty() ) {
            decimalValue += q.top() * pow(2,power);  
            power++;
           q.pop();
        }

        return decimalValue;
    }