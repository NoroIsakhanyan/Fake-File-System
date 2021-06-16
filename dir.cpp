#include "dir.h"

dir::dir(const std::string& name)
: m_name{name}
{}

dir::~dir()
{
    size_t SIZE_OF_DIRECTORIES = m_directories.size();
    for (int i = 0; i < SIZE_OF_DIRECTORIES; ++i)
		{
			delete m_directories[i];
		}
}

std::string& dir::getName() const
{
    return m_name;
}

std::vector<dir*>& dir::getDirectories() const
{
    return m_directories;
}

std::vector<std::string>& dir::getFiles() const
{
    return m_files;
}

