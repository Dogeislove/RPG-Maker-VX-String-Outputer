#pragma once
//A ton of exceptions you can use
#include <string>

using namespace std; //funny
struct Bad_File_Type
{
    string file_name;
    Bad_File_Type(string name) : file_name{ name } {}
};

struct Secret
{
    Secret() {};
};

struct I_Am_Evil //Random Exepction thrown because your evil
{
    I_Am_Evil() {};
};
//Lazy
struct Placeholder
{
    Placeholder() {};
};

//I don't like this type so i will throw an execption
template<typename t>
struct Invalid_Read
{
    t Read;
    Invalid_Read(t Last_read) : Read{ Last_read } {}
};

