#include <iostream>
using namespace std;

struct ShoppingCart
{
    string name;
    float price;
    int qty;
    float total;
};

ShoppingCart shoppingCart[10000];
int shoppingCartItem = 0;

// total price for all items in the cart
float totalPrice()
{
    float total = 0;
    for (int i = 0; i < shoppingCartItem; i++)
    {
        total += shoppingCart[i].price * shoppingCart[i].qty;
    }
    return total;
}
// add item to the cart
void addItem()
{
    ShoppingCart newItem;
    cout << "Enter Item Name: ";
    cin >> newItem.name;
    cout << "Enter Item Price: ";
    cin >> newItem.price;
    cout << "Enter Item Quantity: ";
    cin >> newItem.qty;

    cout << "[Success] Item added to cart\n";

    shoppingCart[shoppingCartItem] = newItem;
    shoppingCartItem++;
}
// display menu
void displayMenu()
{
    cout << "\n***Welcome to Shopping Cart ***\n";
    cout << "---------------------\n";
    cout << "1. Add Item\n";
    cout << "2. Update Item\n";
    cout << "3. Display Cart\n";
    cout << "4. Quit\n";
    cout << "---------------------\n";
    cout << "Enter your choice: ";
}
// display all items in the cart
void displayCart()
{

    cout << "Items in your shopping cart\n";
    cout << "--------------------------------------------------\n";
    cout << "|Item\t\tPrice\tQuantity\tTotal\t |\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < shoppingCartItem; i++)
    {
        cout << "| - " << shoppingCart[i].name << "\t"
             << "$" << shoppingCart[i].price << "\t"
             << shoppingCart[i].qty << "\t\t"
             << "$" << shoppingCart[i].price * shoppingCart[i].qty << "\t|" << endl;
    }
    cout << "--------------------------------------------------\n";
    cout << "# item: " << shoppingCartItem << " Total price: $" << totalPrice() << endl;
    cout << "--------------------------------------------------\n";
}
// update item in the cart
void updateCart()
{
    int option;

    cout << "press [1] to update qty\n";
    cout << "press [2] to delete item\n";
    cout << "press [3] to cancel\n";
    cout << "option: ";
    cin >> option;
    if (option >= 1 && option <= 3)
    {
        // update qty
        if (option == 1)
        {
            string name;
            cout << "Enter item name: ";
            cin >> name;
            for (int i = 0; i < shoppingCartItem; i++)
            {
                if (shoppingCart[i].name == name)
                {
                    cout << "Enter new qty: ";
                    cin >> shoppingCart[i].qty;
                    cout << "\n[Sucess] Item updated sucessfully\n";
                    return;
                }
                else
                {
                    cout << "\n[!] Item not found\n";
                }
            }
        }
        // delete item
        if (option == 2)
        {
            // search item by name
            string name;
            cout << "Enter item name: ";
            cin >> name;
            for (int i = 0; i < shoppingCartItem; i++)
            {
                if (shoppingCart[i].name == name)
                {
                    // remove the item from the cart
                    for (int j = i; j < shoppingCartItem; j++)
                    {
                        shoppingCart[j] = shoppingCart[j + 1];
                    }
                    shoppingCartItem--;
                    cout << "\n[Sucess] Item deleted sucessfully\n";
                    return;
                }
                else
                {
                    cout << "\n[!] Item not found\n";
                }
            }
        }
        // back to main menu
        if (option == 3)
        {
            return;
        }
    }
    else
    {
        cout << "[Error] invalid option\n";
    }
}

int main()
{
    int menu;
    do
    {
        displayMenu();
        cin >> menu;
        switch (menu)
        {
        case 1:
            addItem();
            break;
        case 2:
            updateCart();
            break;
        case 3:
            displayCart();
            break;
        case 4:
            cout << "Exiting the program\n";
            break;
        default:
            cout << "[Error] Invalid menu\n";
        }
    } while (menu >= 1 && menu <= 4);
    return 0;
}
