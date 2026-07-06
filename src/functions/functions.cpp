#include "functions.h"
#include <iostream>
#include <bits/stdc++.h>
#include "../extra_commands/extra_commands.h"

void help(){
    std::cout << "help - List all of the commands in MiniOS" << std::endl;
    std::cout << "exit - Exit MiniOS" << std::endl;
    std::cout << "clear - Clear the terminal" << std::endl;
    std::cout << "list - List MiniOS generated files or user generated files" << std::endl;
    std::cout << "mkfile - Make a file" << std::endl;
    std::cout << "rmfile - Delete a file" << std::endl;
}

void run(std::string mini_script, std::string username){
    std::stringstream msss(mini_script);
    std::string line;

    while(std::getline(msss, line, '\n')){
        if(line == "clear"){
            system("clear");
        }

        else if(line == "infofetch"){
            infofetch(username);
        }
    }
}
