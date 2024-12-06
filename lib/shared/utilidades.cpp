#include <iostream>
#include <string>
#include <sstream>

int split(const std::string &input, char separator, std::string output[], int maxSize)
{
    std::istringstream stream(input);
    std::string segment;
    int count = 0;

    while (std::getline(stream, segment, separator))
    {
        if (count < maxSize)
        {
            output[count++] = segment;
        }
        else
        {
            break; // Evita ultrapassar o limite do array
        }
    }

    return count; // Retorna o número de elementos armazenados no array
}

// Exemplo de implementacão

// int main()
// {
//     const std::string text = "apple,banana,cherry";
//     char separator = ',';
//     const int maxSize = 10; // Tamanho máximo do array

//     std::string result[maxSize]; // Array para armazenar as substrings
//     int size = split(text, separator, result, maxSize);

//     // Exibe o resultado
//     std::cout << "Número de elementos: " << size << std::endl;
//     for (int i = 0; i < size; ++i)
//     {
//         std::cout << "Parte " << i + 1 << ": " << result[i] << std::endl;
//     }

//     return 0;
// }