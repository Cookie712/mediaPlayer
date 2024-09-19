#include <iostream>
#include <fstream>

using std::string;

class songReader
{
private:
    string content;

public:
    void readSong(string filename)
    {
        try
        {
            std::fstream file;
            file.open(filename);

            if (file.is_open())
            {
                string line;

                while (file.good())
                {
                    std::getline(file, line);
                    content += line + "\n";
                }
            }
            else
            {
                throw std::runtime_error("There is a problem with a file");
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what();
        }
    }

    void displaySong()
    {
        std::cout << "********************************" << std::endl;
        std::cout << content << std::endl;
    }
};