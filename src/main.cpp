#include <iostream>
#include "functions/functions.h"
#include <vector>

struct file{
    std::string name;
    std::string content;
};

void list(std::vector<file> files){
    for(int i = 0; i < files.size(); i++){
        std::cout << files[i].name << std::endl;
    }
}

int main(){
    std::string prompt = "guest@MiniOS: ";

    std::vector<file> normal_files = {};
    std::vector<file> user_files = {};

    file readme = {"readme.txt", "Welcome to MiniOS, an OS that runs in your terminal!\nI recommend running MiniOS in TTY!\nHave fun!\n\nMiniOS was made by therealmaksim4"};
    normal_files.push_back(readme);

    system("clear");

    std::cout << "Welcome to MiniOS, type \"help\" to list all commands..." << std::endl;

    bool running = true;

    while(running){
        std::string cmd;

        std::cout << prompt;
        std::cin >> cmd;

        if(cmd == "exit"){
            running = false;
        }

        else if(cmd == "help"){
            help();
        }

        else if(cmd == "clear"){
            system("clear");
        }

        else if(cmd == "list"){
            std::cout << "M - MiniOS generated files, U - user generated files: ";
            std::cin >> cmd;

            if(cmd == "M" || cmd == "m"){
                list(normal_files);
            }

            else if(cmd == "U" || cmd == "u"){
                list(user_files);
            }

            else{
                std::cout << "Please type a valid command..." << std::endl;
            }
        }

        else if(cmd == "mkfile"){
            std::cout << "Type the name of the file: ";
            std::cin >> cmd;

            user_files.push_back({cmd, ""});
        }

        else{
            std::cout << "Please type a valid command..." << std::endl;
        }
    }

    return 0;
}
