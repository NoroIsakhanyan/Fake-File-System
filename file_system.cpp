#include "file_system.h"

F_S::F_S()
: m_root{new dir("root")}
{
    m_child = m_root;
    m_dirs.push_back(m_root);
}


bool F_S::IS_DIR_UNIQUE(std::string& d_name)
{
    std::vector<dir*> DIRECTORIES = m_child->getDirectories();
    for(auto f : DIRECTORIES){
        if(f->getName() == d_name){
            return false;
        }
    }
    return true;
}

bool F_S::IS_FILE_UNIQUE(std::string& f_name)
{
    std::vector<std::string> FILES = m_child->getFiles();
    for(auto f : FILES){
        if(f == f_name){
            return false;
        }
    }
    return true;
}

void F_S::ls(){
    std::cout << "\nDirectory: " << m_child->getName() << "\n";
    std::cout << "-------------------------------------------";
    std::cout << "\nDirectories: \n";
        
        size_t DIRECTORIES_COUNT = m_child->getDirectories().size();
		for (int i = 0; i < DIRECTORIES_COUNT; ++i)
		{
			if (i == DIRECTORIES_COUNT - 1)
			{
				std::cout << m_child->getDirectories()[i]->getName();
			}
			else
			{
				std::cout << m_child->getDirectories()[i]->getName() << ", ";
			}
		}

	std::cout << "\nFiles: \n";

        size_t FILES_COUNT = m_child->getFiles().size();
		for (int i = 0; i < FILES_COUNT; ++i)
		{
			if (i == FILES_COUNT - 1)
			{
				std::cout << m_child->getFiles()[i];
			}
			else
			{
				std::cout << m_child->getFiles()[i] << ", ";
			}
		}
		std::cout << "\n\n";
}

void F_S::mkdir(std::string& d_name){
    if(IS_DIR_UNIQUE(d_name)){
        m_child->getDirectories().push_back(new dir(d_name));
    }else{
        std::cout << "\n ERROR:: A folder with " << "|" << d_name << "|" << " is already created. \n";
    }
}

void F_S::rmdir(std::string& d_name){
    size_t DIRECTORIES_COUNT = m_child->getDirectories().size();

    for(int i = 0; i < DIRECTORIES_COUNT; ++i){
        if(m_child->getDirectories()[i]->getName() == d_name){
            delete m_child->getDirectories()[i];
            m_child->getDirectories().erase(m_child->getDirectories().begin() + i);
            return;
        }
    }
    std::cout << " \n there is no folder with |" << d_name << "| name. \n"; 
}

void F_S::touch(std::string& f_name){
    if(IS_FILE_UNIQUE(f_name)){
        m_child->getFiles().push_back(f_name);
    }else{
        std::cout << "\n ERROR:: A file with " << "|" << f_name << "|" << " is already created. \n";
    }
}

void F_S::rm(std::string& f_name){
    size_t FILES_COUNT = m_child->getFiles().size();
    for(int i = 0; i < FILES_COUNT; ++i){
        if(m_child->getFiles()[i] == f_name){
            m_child->getFiles().erase(m_child->getFiles().begin() + i);
            return;
        }
    }
     std::cout << " \n There is no file with |" << f_name << "| name. \n"; 
}

void F_S::cd(std::string& d_name){
    size_t DIRECTORIES_COUNT = m_child->getDirectories().size();
    for (int i = 0; i < DIRECTORIES_COUNT; ++i)
		{
			if (m_child->getDirectories()[i]->getName() == d_name)
			{
				m_child = m_child->getDirectories()[i];
				m_dirs.push_back(m_child);
				return;
			}
		}
		std::cout << "Error:: There is no directory with name |" << d_name << "|\n\n";
}

void F_S::cd_back(){
    size_t DIRS_SIZE = m_dirs.size();

    if (DIRS_SIZE == 1)
		{
			return;
		}
    auto tmp = m_dirs[DIRS_SIZE - 2];
	m_child = tmp;
}

void F_S::pwd()
	{
		std::cout << "Current Directory Path: ";
        size_t DIRS_SIZE = m_dirs.size(); 
		for (int i = 0; i < DIRS_SIZE; ++i)
		{
			std::cout << m_dirs[i]->getName() << "/";
		}
		std::cout << "\n\n";
}

