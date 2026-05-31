/**
 * Created by max on 25.05.26.
 *
 * @file main.cpp
 * @brief The main class
 */

#include <exception>
#include <iostream>

#include "engine/Engine.h"
int main()
{
    try
    {
        Engine app;
        app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
