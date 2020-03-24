// Music Store Manangement System in C++ Design and Developed by CodeWithC.com

#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
using namespace std;

int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "kiosk", 3306, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};

void newOrder();
void headerLogo();

int main()
{
    system("cls");
    system("SELF ORDERING SYSTEM");
    system("color 0f");

    db_response::ConnectionFunction();

    int chooseOneFromMenu = 0;
    char exitSurity;

    headerLogo();

    cout << "Please Select Menu" << endl;
    cout << "1. New Order" << endl;
    cout << "2. View Order" << endl << endl;
    cout << "Selection :";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {

    case 1 :
        newOrder();
        break;
  
    case 9:
    ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            return 0;
        }
        else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }
        else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 7. Press Enter To Continue...";
        _getch();
        system("cls");
        main();
        break;
    }
    return 0;
}

void newOrder() {

    system("cls");

    int x = 1, orderItemId[20] = { NULL };
    string code = "", orderItemPrice[20];
    char again;
    float ttl_price = 0.00;

    headerLogo();

    cout << " >>    ORDER     <<" << endl << endl;

    do {

        cout << "Insert Food/Drink Code (Item No. " << x << ')' << endl;
        cout << "CODE :";
        cin >> code;

        string findbyid_query = "SELECT * FROM items WHERE code = '" + code + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate){
            res = mysql_store_result(conn);

            int ttlRow = mysql_num_rows(res);

            if (ttlRow > 0){

                row = mysql_fetch_row(res);
                cout << "MENU :" << row[1] << "-" << row[2] << endl;
                cout << "RM :" << row[4] << endl << endl;

                ttl_price += stof(row[4]);
                orderItemPrice[x] = row[4];

                //store data to array
                string item_id = row[0];
                orderItemId[x] = atoi(item_id.c_str()); //convert string to int

                x++;
      
            } else {
                cout << "Item not found!" << endl;
            }

        } else {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

        

        cout << "Add other item?(Y/y) or (N/n)" << endl;
        cin >> again;


    } while ((again == 'Y') || (again == 'y'));

    //check at least 1 order


    //list out all order list

    system("cls");

    //insert into order
    string order_q = "INSERT INTO orders(price, status) values ('" + to_string(ttl_price) + "', 1)";
    const char* order_str = order_q.c_str();
    qstate = mysql_query(conn, order_str);

    if (!qstate) {

        //get last row id
        string last_id_q = "SELECT id FROM orders ORDER by id DESC LIMIT 1";
        const char* lid_str = last_id_q.c_str();
        qstate = mysql_query(conn, lid_str);
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);
    }


    for (int i = 1; i <= 11; i++) {

        if (orderItemId[i] != NULL) {

            string order_id = row[0];

            string order_q = "INSERT INTO order_items (order_id, item_id, price, notes) VALUES ('"+ order_id +"', '"+to_string(orderItemId[i])+"','"+ orderItemPrice[i] +"','EX NOTES')";
            const char* order_str = order_q.c_str();
            qstate = mysql_query(conn, order_str);
            
        } else {
            break; // exit from loop;
        }
    }

}


void headerLogo() {

    cout << endl << endl << "===================================" << endl;
    cout << "|| QAYYUM MAMAK STYLE RESTAURANT ||" << endl;
    cout << "===================================" << endl << endl;
}
