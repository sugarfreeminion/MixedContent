#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// ascii values for 0 and 9
const int zero = 48;
const int nine = 57;

bool IsNumber(char val)
{
    bool isNumber = false;

    if(val >= zero && val <= nine)
    {
        isNumber = true;
    }
    else
    {
        isNumber = false;
    }

    return isNumber;
}

int main(int argc, char *argv[])
{
    ifstream inputFile;
    string line;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        while(getline(inputFile,line))
        {
            stringstream lineStream(line);
            string val;
               
            vector<string> words;
            vector<string> numbers;

            while(getline(lineStream,val,','))
            {
                if(IsNumber(val[0]))
                {
                    numbers.push_back(val);
                }
                else
                {
                    words.push_back(val);
                }
            }
            
            unsigned int index = 0;

            if(words.size() > 0)
            {
                for(vector<string>::const_iterator itr=words.begin();
                    itr!=words.end();
                    ++itr)
                {
                    if(index < words.size()-1)
                    {
                        cout << *itr << ",";
                    }
                    else
                    {
                        cout << *itr;
                    }

                    ++index;
                }
            }

            if(words.size() > 0 && numbers.size() > 0)
            {
                cout << "|";
            }

            index = 0;
   
            if(numbers.size() > 0)
            {
                for(vector<string>::const_iterator itr=numbers.begin();
                    itr!=numbers.end();
                    ++itr)
                {
                    if(index < numbers.size()-1)
                    {
                        cout << *itr << ",";
                    }
                    else
                    {
                        cout << *itr;
                    }

                    ++index;
                }
            }

            cout << endl;
        }
    }

    inputFile.close();

    return 0;
}
