//Read Strings from RPG Maker VX Never Gas.
//By: Prussian Doge (Doge Hacking Gaming)
//Code isn't good at all, haven't programmed in c++ in so long.
//I've improved from my last github..

//This should try to read RPG Maker Dialoge and output it to file.

#include <iostream>
#include <fstream>
#include <locale>
#include <string>

#define char_size sizeof(char) //Macros.. Macros... M... Mac.. Macros...

 //Global Variables are not usally a good idea but in this caes its alright.
const char end_of_string = ';';
const char start_of_string = 'I';

using namespace std; //I know its a "bad" practice using this, but there are no header files.

template<typename T>
T Interpret_Address(void* byte) //Assume Byte Means Character.
{
    return static_cast<char*>(byte);
}

//Class Member
class String_Storage //Store characters but relies on bool.
{
public:
    String_Storage(char Terminate, char start) : Terminating_Char{ Terminate }, Start{start}  {}

    void Push_back(char& character) //Push character into string. Will stop reading if character == Terminating Character.
    {
        if (character == Terminating_Char)
        {
            Read_String = false;
            Finished_Reading = true;
            character += ' ';
        }
        if (Only_Allowed_Characters(character))
            Read += character;
       
   
    }

    char& operator[](int loc)
    {
        return Read[loc];
    }

    string Pack_String()
    {
        return Read;
    }
    bool Only_Allowed_Characters(char& character) //Is very Slow but hey it works.
    {
        for (auto begin = Dont_Read.begin(); begin != Dont_Read.end(); ++begin)
        {
            if (*begin == character) return true;
        }
        return false;
    }

    void Erase_String()
    {
        Read = "";
    }

    bool Is_Finished() //Is the string done being read?
    {
        return Finished_Reading;//Read Strings from RPG Maker VX Never Gas.
//By: Prussian Doge (Doge Hacking Gaming)
//Code isn't good at all, haven't programmed in c++ in so long.
//I've improved from my last github..

//Issues: EV (from events) random o's (from events yet again).
//This should try to read RPG Maker Dialoge. 

//Testing This lol

#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "Extra_Exceptions.h"

#define char_size sizeof(char) //Macros.. Macros... M... Mac.. Macros...

 //Global Variables are not usally a good idea but in this caes its alright.
const char end_of_string = ';';
const char start_of_string = 'I';

using namespace std; //I know its a "bad" practice using this, but there are no header files.



template<typename T>
T Interpret_Address(void* byte) //Assume Byte Means Character.
{
    return static_cast<char*>(byte);
}

//Class Member
class String_Storage //Store characters but relies on bool.
{
public:
    String_Storage(char Terminate, char start) : Terminating_Char{ Terminate }, Start{start}  {}

    void Push_back(char& character) //Push character into string. Will stop reading if character == Terminating Character.
    {
        if (trash == true)
        {
            if (character == 'o')
                trash = false;
            return;
        }

        if (character == Terminating_Char)
        {
            Read_String = false;
            Finished_Reading = true;
            character += ' ';
        }
        
            
        if (Only_Allowed_Characters(character))
            Read += character;
        if (character == '.' || character == '!' || character == '?') Read += '\n';
   
    }
    char& operator[](int loc)
    {
        return Read[loc];
    }

    string Return_String()
    {
        return Read;
    }
    //Junk is different from Invalid_char!
    bool Only_Allowed_Characters(char& character) //Is very Slow but hey it works.
    {
        for (auto begin = IsChar.begin(); begin != IsChar.end(); ++begin) //read all of the strings
        {
            if (*begin == character) return true;
        }
        return false;
    }

    void Erase_String()
    {
        Read = "";
    }

    bool Is_Finished() //Is the string done being read?
    {
        return Finished_Reading;
    }
    void Allowed_Characters(const string& character) //Only read
    {
        IsChar = character;
    }

    void Set_Read(bool set)
    {
        Finished_Reading = !set;
        Read_String = set;
    }

    void Set_Trash(bool is_trash)
    {
        trash = is_trash;
    }

    bool Reading()
    {
        return Read_String;
    }

    void Set_Finished(bool val)
    {
        Finished_Reading = val;
    }
    bool Is_Terminator(char character)
    {
        return character == Terminating_Char;
    }

    bool Is_Starter(char character)
    {
        return character == Start;
    }
    bool More_Words()
    {
        char* begin = &Read[0];
        while (begin != &Read[Read.size()] && *begin != ' ')
        {
            ++begin;
        }
        return *begin != ' ';
    }
private:
    char Terminating_Char;
    char Start;
    string IsChar = ""; //String to only read
    string Read = ""; //String Read
    bool Read_String = false; //Is the string reading?
    bool Finished_Reading = true; //is the string done reading?
    bool trash;
};


char* Get_Dot(string& name) //FUCKING VISUAL STUDIOS, ARE YOU KIDDING ME? THIS WONT WORK?
{
    char* location = &name[0];
    while (*location != '.' && location != &name[name.size()]) ++location;
    return location;
}

string Get_File_Extension(string& name)
{
    // Get the File Extension.
    string shit = "";
    char* pos = Get_Dot(name);
    for (; pos != &name[name.length()]; ++pos)
    {
        shit += *pos;
    }
    return shit;
}


void do_shit(string name)
{
    String_Storage Read{ end_of_string, start_of_string };
    
    ifstream Map{ name, ios_base::binary }; //Copying isn't a good idea.
   

 

    if (!Map) //placeholder
        throw Placeholder{};

    ofstream to{ name + ".txt" };


    if (Get_File_Extension(name) != ".rvdata2")
        throw Bad_File_Type{ Get_File_Extension(name) };

    Read.Allowed_Characters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ, "); //Allowed Characters
    //Will Simplify
    for (char ye; Map.read(Interpret_Address<char*>(&ye), char_size);)
    {
        char* byte = Interpret_Address<char*>(&ye); //to explain
        if (*byte == 'E') //Get rid of those damn events!
            Read.Set_Trash(true);

        if (Read.Reading()) //If the Read is being Read to.
        {
            Read.Push_back(ye); //Push back until terminator is encountered (In this case its ';')
        }

        if (Read.Is_Finished()) //If we've recently encountered a terminator, write to file and erase string.
        {
            Read.Set_Finished(false);
            if (Read.Return_String().size() < 2 || Read.More_Words()) //Small dumb bytes
                Read.Erase_String(); //Get rid of data to prevent overloading.
            else
                to << Read.Return_String() << endl; //Read The String in Read
                Read.Erase_String(); //Get rid of data to prevent overloading. 
                //Don't worry, its not a pointer. So it will just set the string to default.
        }

        if (Read.Is_Starter(*byte))
            Read.Set_Read(true); //Is *byte == Begin_Of_String (In This Case Its 'I'). If its true, Set the Read To True.
    }
    std::cout << "Finished reading: " << name << endl << "Wrote to File:" << name + ".txt" << endl; //its not gonna be different lol
}


int main()
{
    while (true)
    {
        try 
        {
            cout << "Enter File Name (Currently Supports .rvdata2) (Case Sensitive): ";
            string name;
            cin >> name;
            cout << "\n";
            do_shit(name);
        }
        catch (Bad_File_Type& File_Type)
        {
            std::cerr << "Error: " << File_Type.file_name << " Is not supported. Did you mispell .rvdata2?" << endl;
        }
        catch (Placeholder& placehold)
        {
            cerr << "Too lazy to catch this error so this is very helpful obviously. \n I'm 99% sure this means you didn't enter a valid file_name. lol." << endl;
        }
    }
}


    }
    void Allowed_Characters(const string& character) //Only read
    {
        Dont_Read = character;
    }

    void Set_Read(bool set)
    {
        Finished_Reading = !set;
        Read_String = set;
    }

    bool Reading()
    {
        return Read_String;
    }
    void Set_Finished(bool val)
    {
        Finished_Reading = val;
    }
    bool Is_Terminator(char character)
    {
        return character == Terminating_Char;
    }

    bool Is_Starter(char character)
    {
        return character == Start;
    }
private:
    char Terminating_Char;
    char Start;
    string Dont_Read = "";
    string Read = "";
    bool Read_String; //Is the string reading?
    bool Finished_Reading = true; //is the string done reading?
};

int main()
{
    string name;
    cin >> name;
    ifstream Map{ name, ios_base::binary }; //Copying isn't a good idea.
    ofstream to{ "Stuff.txt" };
    if (!Map)
    {
        std::cerr << "Invalid File, Quitting";
        return 1;
    }

    String_Storage Read{ end_of_string, start_of_string };
    Read.Allowed_Characters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!., "); //Not allowed characters
    for (char ye; Map.read(Interpret_Address<char*>(&ye), char_size);)
    {
        char* byte = Interpret_Address<char*>(&ye); //to explain

        if (Read.Reading()) //If the Read is being Read to.
        {
            Read.Push_back(ye); //Push back until terminator is encountered (In this case its ';')
        }


        if (Read.Is_Finished()) //If we've recently encountered a terminator, write to file and erase string.
        {
            Read.Set_Finished(false);
            to << Read.Pack_String() << endl; //Read The String in Read
            Read.Erase_String(); //Get rid of data to prevent overloading.
        }

        if (Read.Is_Starter(*byte))
            Read.Set_Read(true); //Is *byte == Begin_Of_String (In This Case Its 'I'). If its true, Set the Read To True.
    }

}


  /*
  // Previous attempt
   int main()
    {
        string name;
        cin >> name;
        ifstream Map{ name, ios_base::binary }; //Copying isn't a good idea.
        ofstream to{ "Stuff.txt" };
        bool start = false;
        bool junk = false;
        if (!Map)
        {
            std::cerr << "Invalid File, Quitting";
            return 1;
        }
        String_Storage Read{ end_of_string };
        for (char ye; Map.read(Interpret_Address<char*>(&ye), char_size);)
        {
            char* byte = Interpret_Address<char*>(&ye);

            while (Read.Reading())
            {

            }

            if (*byte == 'I')
            {

            }


        }

    /*for (char ye; Map.read(Interpret_Address<char*>(&ye), char_size);)
    {

        char* byte = Interpret_Address<char*>(&ye);
        //Lazy Programming because i was too lazy to think.
        if (*byte == ';')
        {
            to << '\n';
            start = false;
        }

        if (*byte == '0') junk = true;

        if (junk) //Get rid of any number..
        {
            if (*byte == 'o')
                junk = false;
        }

        if (start == true && *byte != ';' && !junk)
        {
            if (*byte == '') to << '\n';
            to << *byte;
        }
        if (start == false && *byte == 'I')
            start = true;
    }
    //Finished getting the shit ready.. Lets get rid of the non-english words, yes?
    Map.close();
    to.close(); 
    /*
    
    */

 



