#include <iostream>
#include <string>

#define IS_ODD(x) ((x) % 2 == 1)

int main(int argc, char** argv)
{
    int alphabet[26] = {0, };

    std::string str;
    std::cin >> str;

    for (int i = 0; i < str.length(); ++i)
    {
        alphabet[str[i] - 'A']++;
    }

    int odd = 0;
    int oddIndex = 0;

    for (int i = 0; i < 26; ++i)
    {
        if (IS_ODD(alphabet[i]))
        {
            odd++;
            oddIndex = i;
        }
    }

    if (odd > 1)
    {
        std::cout << "I'm Sorry Hansoo" << std::endl;
        return 0;
    }

    std::string result = "";
    int half = 0;

    for (int i = 0; i < 26; ++i)
    {
        half = alphabet[i] / 2;
        for (int j = 0; j < half; ++j)
        {
            result += static_cast<char>('A' + i);
        }
    }

    std::string reverse = result;

    if (odd == 1)
    {
        result += static_cast<char>('A' + oddIndex);
    }

    for (int i = reverse.length() - 1; i >= 0; --i)
    {
        result += reverse[i];
    }

    std::cout << result << std::endl;

    return 0;
}