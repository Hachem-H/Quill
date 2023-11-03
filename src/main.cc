#include "Core/Application.hh"

int main()
{
    Quill::Application* application = new Quill::Application;
    application->Run();
    delete application;
}
