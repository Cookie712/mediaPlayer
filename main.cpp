#include <iostream>
#include "songReader.cpp"
#include "songWritter.cpp"

int main()
{
    int choose;
    songReader reader;
    songWritter writter;
    string fileName;

    int numOfVerses;
    int reffLines;
    int versLines[numOfVerses];

    while (choose != 0)
    {

        std::cout << "What would you like to do?" << std::endl;
        std::cout << "0: Kill execution of the program" << std::endl;
        std::cout << "1: Read a song from directory" << std::endl;
        std::cout << "2: Save a song to the file" << std::endl;

        std::cin >> choose;

        switch (choose)
        {
        case 0:
            std::cout << "Thank you for using the program" << std::endl;
        case 1:
            std::cout << "Please send a file name with the extansion" << std::endl;
            std::cin >> fileName;

            reader.readSong(fileName);
            reader.displaySong();
            break;
        case 2:
            std::cout << "Give number of Verses in your song" << std::endl;
            std::cin >> numOfVerses;
            std::cout << "Give number of lines in your reffrain" << std::endl;
            std::cin >> reffLines;

            for (int i = 0; i < numOfVerses; i++)
            {
                std::cout << "Give number of lines in your " << i + 1 << " verse" << std::endl;
                std::cin >> versLines[i];
            }

            std::cout << "Please send a file name with the extansion" << std::endl;
            std::cin >> fileName;

            writter.writeSong(numOfVerses, reffLines, versLines);
            writter.saveSong(fileName);
            break;
        default:
            std::cout << "Unknown option, please try again." << std::endl;
        }
    }
    return 0;
}