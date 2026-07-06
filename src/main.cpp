#include <iostream>
#include "functions/functions.h"
#include <vector>
#include "extra_commands/extra_commands.h"

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
    std::string username;

    std::cout << "Your username for this session: ";
    std::cin >> username;

    std::string prompt = "MiniOS: ";

    std::vector<file> normal_files = {};
    std::vector<file> user_files = {};

    file readme = {"readme.txt", "Welcome to MiniOS, an OS that runs in your terminal!\nI recommend running MiniOS in TTY!\nHave fun!\n\nMiniOS was made by therealmaksim4"};
    normal_files.push_back(readme);

    file extra = {"extra.txt", "Some extra commands in MiniOS are:\ninfofetch"};
    normal_files.push_back(extra);

    file base_script = {"base_script.ms", "clear\ninfofetch"};
    normal_files.push_back(base_script);

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

        else if(cmd == "rmfile"){
            std::cout << "Type the name of the file you want to delete: ";
            std::cin >> cmd;

            for(int i = 0; i < user_files.size(); i++){
                if(cmd == user_files[i].name){
                    user_files.erase(user_files.begin() + i);
                }
            }
        }

        else if(cmd == "content"){
            std::cout << "Type the name of the file you want to see the content of: ";
            std::cin >> cmd;

            for(int i = 0; i < normal_files.size(); i++){
                if(cmd == normal_files[i].name){
                    std::cout << normal_files[i].content << std::endl;
                }
            }

            for(int i = 0; i < user_files.size(); i++){
                if(cmd == user_files[i].name){
                    std::cout << user_files[i].content << std::endl;
                }
            }
        }

        else if(cmd == "infofetch"){
            infofetch(username);
        }

        else if(cmd == "run"){
            std::cout << "Type the name of the file you want to run: ";
            std::cin >> cmd;

            for(int i = 0; i < normal_files.size(); i++){
                if(cmd == normal_files[i].name){
                    run(normal_files[i].content, username);
                }
            }

            for(int i = 0; i < user_files.size(); i++){
                if(cmd == user_files[i].name){
                    run(user_files[i].content, username);
                }
            }
        }

        else{
            std::cout << "Please type a valid command..." << std::endl;
        }
    }

    return 0;
}
