#include <iostream> 
#include <iomanip> 
#include <sstream> 
using namespace std; 
 
const int MAX_BOOKS = 10; 
 
struct Book 
{ 
    string no; 
    string title; 
    string author; 
    double price; 
}; 
struct creditCard 
{ 
    string cardNumber; 
    string password; 
 
}; 
void addToCart(Book cart[],int &cartSize, Book books[], int numBooks, const string &input) 
{ 
    int index; 
    istringstream iss(input); 
    while(iss >> index) 
 { 
        index--; 
        if (index>=0 && index <numBooks) 
  { 
            if(cartSize <MAX_BOOKS) 
   { 
                cart[cartSize++]= books[index]; 
            } 
            else 
   { 
                cout <<"\nCart is full" <<endl; 
                break; 
            } 
        } 
        else  
  { 
            cout << "Invaild book index"; 
            break; 
        } 
 
    } 
} 
 
bool Payment(creditCard &creditCard) 
{ 
    cout << "Enter Credit/Debit card details:" <<endl; 
    cout << "Credit Number: "; 
    cin >> creditCard.cardNumber; 
    cout << "Password: "; 
    cin >> creditCard.password; 
    cout << endl <<endl; 
 
    return !creditCard.cardNumber.empty() && !creditCard.password.empty(); 
} 
 
void availableBooks(Book books[], int numBooks) 
{ 
    cout << "       --Available Books--     " << endl; 
    for (int i = 0; i< numBooks; i++) 
 { 
        cout <<books[i].no << "Title: " << setw(20)<< left << books[i].title << "\t Price: $" << 
  fixed <<setprecision(2) << setw(6) << right <<books[i].price << endl  
  << "   Author: " << books[i].author <<endl <<endl; 
    } 
    cout << endl << "       --------------------      "<<endl; 
} 
 
void searchBooks (Book books[], int numBooks, const string& search) 
{ 
    cout << "       --Searhced Books--     " << endl; 
    for(int i = 0 ; i<numBooks; ++i) 
 { 
        if(books[i].title.find(search) != string :: npos || books[i].author.find(search) != string :: 
npos) 
  { 
            cout<<books[i].no << "Title: " << setw(20) << left << books[i].title  
   << "\tPrice: $" <<fixed <<setprecision(2) << setw(6) <<right 
<<books[i].price << endl  
   << "   Author: " << books[i].author <<endl <<endl; 
        } 
    } 
    cout << endl << "       --------------------      "<<endl; 
} 
 
void display() 
{ 
    cout << "\n\n       --Book Store--     " << endl <<endl; 
    cout << "1. View available books" << endl; 
    cout << "2. Search a book by title or author (Upper Case)" << endl; 
    cout << "3. Add books to a shopping cart" << endl; 
    cout << "4. View the contents of the shopping cart" << endl; 
    cout << "5. Complete the purchase" << endl; 
    cout << "6. Exit" << endl; 
    cout << endl << "       --------------------      "<<endl; 
} 
 
int main () 
{ 
    Book books [MAX_BOOKS] =  
 { 
        {"1. ","A TIME TO KILL", "JOHN GRISHAM", 20.15}, 
        {"2. ","THE HOUSE OF MIRTH", "EDITH WHARTON", 15.15}, 
        {"3. ","EAST OF EDEN", "JOHN STEINBECK", 17.65}, 
        {"4. ","THE SUN ALSO RISES", "ERNEST HEMINGWAY", 10.00}, 
        {"5. ","NUMBER THE STARS", "LOIS LOWRY", 25.61}, 
    }; 
    creditCard creditCard; 
    Book cart[MAX_BOOKS]; 
    int numBooks = 5; 
    int cartSize = 0; 
    while(true) 
 { 
        display(); 
        int choice; 
        cout << "Enter your Choice: "; 
        cin >> choice; 
        cout <<endl <<endl; 
        switch (choice) 
        { 
        case 1: 
            availableBooks(books, numBooks);     
            break; 
        case 2: 
            { 
                cin.ignore(); 
                cout << "Enter the title or author's name: "; 
                string search; 
                getline(cin, search); 
                searchBooks(books, numBooks, search); 
            } 
            break; 
        case 3: 
            { 
                cin.ignore(); 
                availableBooks(books, numBooks); 
                cout << "Enter the index number to add to the cart: "; 
                //cin >> index; 
                string input; 
                getline(cin, input); 
                addToCart(cart, cartSize, books, numBooks, input); 
                cout << "\nAdded to the cart" << endl; 
 
            } 
            break; 
        case 4: 
            { 
             availableBooks(cart, cartSize); 
            if(cartSize>0) 
   { 
                        double cost = 0.0; 
                        for (int i = 0; i<cartSize; ++i) 
      { 
                        cost += cart[i].price;  
                        } 
                    cout << "Total cost: $" << cost << endl; 
            } 
            } 
            break; 
        case 5: 
            { 
                if(cartSize>0) 
    { 
                    if(Payment(creditCard)) 
     { 
                        double cost = 0.0; 
                        for (int i = 0; i<cartSize; ++i) 
      { 
                        cost += cart[i].price;  
                        } 
                    cout << "Total cost: $" << cost << endl; 
                    cout << "Purchase completed. Thank you.\n" << endl; 
                    cartSize =0; 
                    } 
         
                    else  
     { 
                    cout << "Invaild card details. Payment failed." << endl; 
                    } 
                } 
                else { 
                    cout <<"\nCart is empty. Add books to the cart first" <<endl; 
                } 
 
 
            } 
            break; 
        case 6:  
            cout << "Exited form the Book store." << endl; 
            return 0; 
         
        default: 
            cout<< "Invaild choice. Please enter a number between  1 to 6"; 
        } 
    } 
} 