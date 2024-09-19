#include <iostream>
#include <fstream>

using std::string;

class songWritter
{
private:
    string text;

public:
    void writeSong(int numberOfVerses, int reffrainLines, int versesLines[])
    {
        string line; // temporary variable to hold the answer
        string reffrain;
        string verses[numberOfVerses];

        std::cout << "Send a reffrain:" << std::endl;
        for (int i = 0; i <= reffrainLines; i++)
        {
            line = "";
            std::getline(std::cin, line);
            line += '\n';
            reffrain += line;
        }

        for (int i = 0; i < numberOfVerses; i++)
        {
            std::cout << "Send your " << i + 1 << " verse:" << std::endl;
            for (int j = 0; j < versesLines[i]; j++)
            {
                line = "";
                std::getline(std::cin, line);
                line += '\n';
                verses[i] += line;
            }
        }

        for (int i = 0; i < numberOfVerses; i++)
        {
            try
            {
                if (reffrain == "" || verses[i] == "")
                {
                    string message = "Your reffrain or verse was not specified";
                    throw message;
                }
            }
            catch (const string &msg)
            {
                std::cout << "Error: " << msg << std::endl;
            }

            text += verses[i] + '\n';
            text += reffrain + '\n';
        }
    }

    void saveSong(string fileName)
    {
        try
        {
            std::fstream file;

            file.open(fileName, std::ios::out);

            if (file.is_open())
            {
                file << text;
                file.close();
            }
            else
            {
                throw std::runtime_error("The file " + fileName + " does not exist");
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what();
        }
    }
};