#ifndef FILESYSTEM
#define FILESYSTEM
#include "dir.cpp"

class F_S{
public:
    F_S();
public:
    //Operations
    void ls(); // display file system
    void mkdir(std::string& ); //creat folder
    void rmdir(std::string& ); //delete folder
    void touch(std::string& ); // creat file
    void rm(std::string& ); //delete file
    void cd(std::string& ); // go to the given folder
    void cd_back(); //go to parent of current folder
    void pwd(); // folder state
private:
    //Operation Helpers
    bool IS_DIR_UNIQUE(std::string& );
    bool IS_FILE_UNIQUE(std::string& );
private:
    std::vector<dir*> m_dirs;
    dir* m_root;
    dir* m_child;
};


#endif //FILESYSTEM