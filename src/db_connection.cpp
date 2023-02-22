#include "include/config.h"
//#include <database.h>
#include <pqxx/pqxx>
#include <iostream>
//#include <config.h>
#include <string>

using namespace pqxx;

int main() 
{
    try 
    {
        connection C(CONN_STRING);
        if (C.is_open())
        {
            std::cout << "Opened database successfully: " << C.dbname() << std::endl;

        }
        else 
        {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
        C.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
