#include "file_system.cpp"



void start(F_S& s){
    bool exit = false;
    std::string command;
    std::cin >> command;
    std::string name;
    std::cin >> name;
    
    do{
        if(command == "ls"){
            system("cls");
            s.ls();
            start(s);
        }
        else if(command == "mkdir"){
            system("cls");
            s.mkdir(name);
            start(s);
        }
        else if(command == "rmdir"){
            system("cls");
            s.rmdir(name);
            start(s);
        }
        else if(command == "touch"){
            system("sls");
            s.touch(name);
            start(s);
        }
        else if(command == "rm")
        {
            system("cls");
            s.rm(name);
            start(s);
        }
        else if(command == "cd")
        {
            system("cls");
            s.cd(name);
            start(s);
        }
        else if(command == "cd..")
        {
            system("cls");
            s.cd_back();
            start(s);
        }
        else if(command == "pwd")
        {
            system("sls");
            s.pwd();
            start(s);
        }
        else if(command == "exit")
        {
            exit = true;
        }
        else
        {
            std::cout << std::endl <<  "Invalid command,please check commands" << std::endl;
            start(s);
        }
    }while (!exit);
    
}

int main(){
    F_S f_system;

    start(f_system);

}