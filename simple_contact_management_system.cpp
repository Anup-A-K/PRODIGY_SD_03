#include <iostream>
#include <fstream>
using namespace std;

struct Contact
{
    string name;
    string phone;
    string email;
};

int main()
{
    Contact *contacts = new Contact[10000];
    int size = 0;
    try
    {
        ifstream file("contacts.txt");
        while(!file.eof())
        {
            Contact* con = new Contact;
            file >> con->name;
            file >> con->phone;
            file >> con->email;
            contacts[size] = *con;
            delete con;
            size++;
        }
        file.close();
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }
    while(true)
    {
        cout << "1. Add contact" << endl;
        cout << "2. Display contacts" << endl;
        cout << "3. Edit contact" << endl;
        cout << "4. Delete contact" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1)
        {
            Contact* con = new Contact;
            cout << "Enter name: ";
            cin >> con->name;
            cout << "Enter phone: ";
            cin >> con->phone;
            cout << "Enter email: ";
            cin >> con->email;
            contacts[size] = *con;
            delete con;
            size++;
        }
        else if(choice == 2)
        {
            for(int i = 0; i < size; i++)
            {
                cout << "Name: " << contacts[i].name << endl;
                cout << "Phone: " << contacts[i].phone << endl;
                cout << "Email: " << contacts[i].email << endl;
                cout << endl;
            }
        }
        else if(choice == 3)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            for(int i = 0; i < size; i++)
            {
                if(contacts[i].name == name)
                {
                    cout << "Enter new name: ";
                    cin >> contacts[i].name;
                    cout << "Enter new phone: ";
                    cin >> contacts[i].phone;
                    cout << "Enter new email: ";
                    cin >> contacts[i].email;
                    break;
                }
            }
        }
        else if(choice == 4)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            for(int i = 0; i < size; i++)
            {
                if(contacts[i].name == name)
                {
                    for(int j = i; j < size - 1; j++)
                    {
                        contacts[j] = contacts[j + 1];
                    }
                    size--;
                    break;
                }
            }
        }
        else if(choice == 5)
        {
            break;
        }
        else 
        {
            cout << "Invalid choice" << endl;
        }
    }
    try 
    {
        ofstream file("contacts.txt");
        for(int i = 0; i < size; i++)
        {
            file << contacts[i].name << endl;
            file << contacts[i].phone << endl;
            file << contacts[i].email << endl;
        }
        file.close();
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }
}
