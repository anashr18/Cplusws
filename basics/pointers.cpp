
#include <string>
#include <stdio.h>
#include <memory>
class Project
{
    std::string m_name;

public:
    void setProjectName(std::string name)
    {
        this->m_name = name;
    }
    std::string getProjectName()
    {
        return this->m_name;
    }
};

class Employee
{
    std::shared_ptr<Project> *m_pProject{};

public:
    void setProject(Project *project)
    {
        this->m_pProject = project;
    }
    const Project *getProject() const
    {
        return m_pProject;
    }
};

int main()
{
    std::shared_ptr<Project> prj = std::make_shared<Project>();
    prj->setProjectName("Sample Project");
    std::unique_ptr<Employee> e1 = std::make_unique<Employee>();
    e1->setProject(prj.get());
    return 0;
}