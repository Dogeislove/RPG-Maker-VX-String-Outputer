//Read Strings from RPG Maker VX Never Gas.
//By: Prussian Doge (Doge Hacking Gaming)
//Code isn't good at all, haven't programmed in c++ in so long.
//I've improved from my last github..

//Issues: EV (from events) random o's (from events yet again).
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
        return Finished_Reading;
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

 



