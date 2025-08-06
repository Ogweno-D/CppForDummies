//
// Created by DO on 06/08/2025.
//

// #include "LinkedList.h"
# include <iostream>
using  namespace  std;
class Employee
{
    private:
    int employeeNumber;
    std::string employeeName;

    public:
    Employee():employeeNumber(0){}
    explicit Employee(int const e_no, string name):employeeNumber(e_no),employeeName(std::move(name)){}

    // Friendliness galore
    friend ostream& operator<<(ostream& os, const Employee& e);
    friend istream& operator>>(istream& is, Employee& e);

};
// Overload the >> and << operators for my employee class
istream&operator>>(istream& is, Employee& employee)
{
    cout << "Enter Employee Number: ";
    cin>> employee.employeeNumber;
    cout << "Enter Employee Name: ";
    cin>>employee.employeeName;
    return is;
}
ostream&operator<<(ostream& os, const Employee& e)
{

    cout << "Employee Name : " << e.employeeName << endl;
    cout << "Employee No: " << e.employeeNumber << endl;
    return os;
}

// Struct for the node
template <class T>
struct Node
{
    T  data;
    Node * next{};
};

// class LinkedList
template <class T>
class LinkedList
{
    private:
    Node<T> * head;
    public:
    LinkedList():head(nullptr)
    {
        cout <<"You have used me to construct yourself!"<<endl;
    };
    //Destructor
    ~LinkedList()
    {
        delete head;
        cout << "The destructor is called!" << endl;
    }
    void append(T data)
    {
        auto * newNode = new Node<T>();

        newNode->data = std::move(data); // TODO::Overload = operator and pass the reference here
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> * current = head;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

    }
    void remove(T data)
    {
        //Edge case
        if (head==nullptr)
        {
            return;
        }

        // Case !: Removing the head node!
        if(head->data == data) // Check if there is data in the current (head)
        {
            Node<T> * current = head; // Set a temporary pointer to the head
            head = head->next; // Move the head(the first link to the next one)
            delete current; // Delete the current pointer
            // The destructor is called
        }
        // Case 2 : Removing any node in the middle of the list
        else
        {
            Node<T> * current = head;
            while(current->next != nullptr && current->next->data != data)
            {
                current = current->next; // Stop before the node to be deleted
            }
            if(current->next == nullptr)
            {
                Node<T> * temp = current->next; // Point to the node to be deleted.
                temp->next = temp->next; // Skip the node

                delete temp; // Delete the node;
            }

        }
    }
    void display()
    {
        Node<T> * temp = head; // Set the pointer(temp) to the head of the linked list
        while(temp != nullptr)
        {
            cout << "Employee Details" << endl;
            cout << "======================\n" << endl;
            std::cout << temp->data << " "; // Display the data of the current node(pointed by temp)
            temp = temp->next; // Set the head to the next to also access te next node::Move to the next link
        }
        std::cout << std::endl;
    }
};

int main()
{
    char choice;
    // Linked list for my employees
    LinkedList<Employee> lemp;
    Employee employee;

    // Fill that list whilst engaging the user!
    do
    {
        cin>>employee;
        lemp.append(employee);
        cout << "Do you want to add another employee? 'y' or 'n'" << endl;
        cin>> choice;
    } while (choice == 'y' || choice == 'Y');

    lemp.display();

    return 0;

}
