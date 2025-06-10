import java.util.Scanner; 
 
public class LabF1KioXiaoJie  
{ 
    public static void main(String[] args)  
    { 
        Scanner scanner = new Scanner(System.in); 
         
        int product1 = 0, product2 = 0, product3 = 0; 
 
        product1 = getStock(scanner, 1); 
        product2 = getStock(scanner, 2); 
        product3 = getStock(scanner, 3); 
         
        boolean run = true; 
        while (run) 
        { 
            displayMenu(); 
            int choice = scanner.nextInt(); 
             
            switch (choice) 
            { 
                case 1: 
                    int addProduct = getProduct(scanner); 
                    int addQuantity = getQuantity(scanner, "add"); 
                     
                    if (addProduct == 1) product1 += addQuantity; 
                    if (addProduct == 2) product2 += addQuantity; 
                    if (addProduct == 3) product3 += addQuantity; 
                     
                    System.out.println("Quantity updated"); 
                    break; 
                     
                case 2: 
                    int removeProduct = getProduct(scanner); 
                    int removeQuantity = getQuantity(scanner, "remove"); 
                           
                    if (removeProduct == 1 && product1 >= removeQuantity) 
                        product1 -= removeQuantity; 
                    else if (removeProduct == 2 && product2 >= removeQuantity)  
                        product2 -= removeQuantity; 
                    else if (removeProduct == 3 && product3 >= removeQuantity)  
                        product3 -= removeQuantity; 
                    else  
                        System.out.println("Quantity shouldn't be more than current quantity"); 
                    break; 
                     
                case 3: 
                    System.out.println("P1=" + product1 + " P2=" + product2 + " P3=" + product3);  
                    break; 
                 
                case 4:  
                    run = false; 
                    System.out.println("Thank you for using the system."); 
                    break; 
                     
                default: 
                    System.out.println("Invalid selection."); 
            } 
        } 
        scanner.close(); 
    } 
     
    public static int getStock(Scanner scanner, int productNumber)  
    { 
        int quantity; 
        do  
        { 
            System.out.print("Enter current stock quantity for product " + productNumber + ": "); 
            quantity = scanner.nextInt(); 
            if (quantity < 0)  
            { 
                System.out.println("Quantity should be positive."); 
            } 
        } while (quantity < 0); 
        return quantity; 
    } 
 
    public static void displayMenu()  
    { 
        System.out.println("Menu:"); 
        System.out.println("1. Add stock"); 
        System.out.println("2. Remove stock"); 
        System.out.println("3. Check quantity"); 
        System.out.println("4. Quit"); 
        System.out.print("Enter selection (1/2/3/4): "); 
    } 
 
    public static int getProduct(Scanner scanner)  
    { 
        int product; 
        do { 
            System.out.println("Product Selection:"); 
            System.out.println("1. Product 1"); 
            System.out.println("2. Product 2"); 
            System.out.println("3. Product 3"); 
            System.out.print("Enter selection (1/2/3): "); 
            product = scanner.nextInt(); 
            if (product < 1 || product > 3)  
            { 
                System.out.println("Invalid selection."); 
            } 
        } while (product < 1 || product > 3); 
        return product; 
    } 
 
    public static int getQuantity(Scanner scanner, String action)  
    { 
        int quantity; 
        do { 
            System.out.print("Enter quantity to " + action + ": "); 
            quantity = scanner.nextInt(); 
            if (quantity < 0)  
            { 
                System.out.println("Quantity should be positive."); 
            } 
        } while (quantity < 0); 
        return quantity; 
    } 
} 