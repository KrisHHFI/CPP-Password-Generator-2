// Created by Kristopher Pepper, in 2023.
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

char alphabetLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
std::string generatedPassword = {};
int length = 20;
char symbols[29] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '{', '}', '[', ']', '|', ':', ';', '"', '\'', '<', '>', ',', '.', '/', '?'};
std::string userChoice;

bool isInteger(const std::string &input)
{
    std::string trimmedInput = input;
    trimmedInput.erase(std::remove_if(trimmedInput.begin(), trimmedInput.end(), ::isspace), trimmedInput.end());

    for (char c : trimmedInput)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

void randomLetter()
{
    int randomLetter = rand() % 26;
    int capsOrNot = rand() % 2;

    if (capsOrNot == 0)
    {
        char uppercaseLetter = toupper(alphabetLetters[randomLetter]);
        generatedPassword.push_back(uppercaseLetter);
    }
    else
    {
        generatedPassword.push_back(alphabetLetters[randomLetter]);
    }
}

void randomNumber()
{
    int randomNumber = rand() % 10;
    std::string randomNumberChar = std::to_string(randomNumber);
    generatedPassword += randomNumberChar;
}

void randomSymbol()
{
    int randomSymbol = rand() % 29;
    generatedPassword.push_back(symbols[randomSymbol]);
}

int generatePassword()
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < length; i++)
    {
        int choice = rand() % 3;

        if (choice == 0)
        {
            randomLetter();
        }
        else if (choice == 1)
        {
            randomNumber();
        }
        else
        {
            randomSymbol();
        }
    }
    std::cout << generatedPassword << std::endl;
    generatedPassword = {};
}

int main()
{
    std::cout << "--- CPP-Password-Generator-2 ---" << std::endl;

    while (true)
    {
        std::cout << "\nGenerate Password = g | Set Length = l | Exit = e : ";
        std::getline(std::cin, userChoice);

        if (userChoice == "g")
        {
            generatePassword();
        }
        else if (userChoice == "l")
        {
            std::cout << "Current length is " << length << ". Enter a new length: ";
            std::string input;
            std::getline(std::cin, input);
            input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end()); // Remove leading and trailing spaces

            if (isInteger(input))
            {
                try
                {
                    length = std::stoi(input);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout << "Invalid integer. Please enter a valid integer." << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid integer. Please enter a valid integer." << std::endl;
            }
        }
        else if (userChoice == "e")
        {
            std::cout << "Program exited." << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid. Please enter 'g' to generate a password, 'l' to set the length, or 'e' to exit." << std::endl;
        }
    }

    return 0;
}