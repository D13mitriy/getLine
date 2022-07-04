#include <iostream>
#include <cstdlib>


char* resize(const char* str, unsigned size, unsigned new_size)
{
    
    char* arr = new char[new_size];
    for (unsigned i = 0; i < new_size ; i++)
    {
        arr[i] = str[i];
    }
    delete[] str;
    str = nullptr;
    arr[new_size] = '\0';
    return arr;
}
 
char* getline()
{
    char c ='\0';
    unsigned i = 0;
    unsigned n = 128;
    char* line = new char[n];
    line[0] = c;
    unsigned lineSize = n;
    while (std::cin.get(c) && c != '\n')
    {
             
        
        if (i > lineSize - 2)
        {
            n = n * 2;//Assertion `(old_top == initial_top (av) && old_size == 0) || ((unsigned long) (old_size) >= MINSIZE && prev_inuse (old_top) && ((unsigned long) old_end & (pagesize - 1)) == 0)' failed.
            line = resize(line, lineSize, n);
            lineSize = n;
            
        }
        line[i] = c;
        i++;
    }

   
    line[i] = '\0';
    
    
    
    return resize(line, n, i );

}


int main()
{
    const char * str = getline();
    std::cout << str <<"   " << sizeof(str) << std::endl;
    std::cout << sizeof(char) << std::endl;

    delete[] str;
    

	return 0;
}