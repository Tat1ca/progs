#include <iostream>
#include <fstream>

using namespace std;


class Code
{
public:
    fstream fin = fstream("TextFile.txt");
    char str[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    char alpha[53] = "GgJjMmAaHhVvWwRrFfUuZzEeSsPpBbLlOoYyXxLiQqCcDdNnTtKk";
    char sym;
    void Encode()
    {
        for (; !fin.eof();)
        {
            fin.get(sym);
            for (int i = 0; i < 53; ++i)
            {
                if (sym) == str[i]
                {

                }
            }
        }

    }
};

int main()
{
    
}