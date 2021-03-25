#include<sstream>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;


//below is an instance of our node that will create a node to print out to 
//and link to other nodes
class Node
{
private:
    //private attributes
    string EdgeColor;
    string FillColor;
    string OutlineColor;
    string EdgeStyle;
    string Name;
    string NodeNumber;


    string Initials;
    string CountryName;

public:
    //default constructor to hold our values
    Node()
    {
        Initials = CountryName = 'a';
    };// default constructor
    //overloaded default method for our node
    //default string of initials and then countryname
    Node(string CountryInitials, string Name)
    {
        CountryName = Name;
        Initials = CountryInitials;
    }
    //four methods below to get and set the input values
    
    //setters for out attributes
    void SetInitials(string);
    void SetCountryName(string);

    //getters to get new name and initials
    string GetCountryName();
    string GetInitials();

    //copy constructor for another node
    Node(const Node& other)
    {
        this->Initials = other.Initials;
        this->CountryName = other.CountryName;
    }

    //overloaded outstream operator for our class
    friend ostream& operator<<(ostream& OutFile, const Node& other);
    //destructor for our class
    ~Node()
    {
        cout << " node has been destoyed" << endl;
    };// destructor for our node class

}; // conclusion of our class initialization




//definition for ostream overloading

ostream& operator<<(ostream& OutFile, const Node& other)
{
    return OutFile << "[" << " NodeName =" << other.Initials << "," <<
        " Country= " << other.CountryName << "]";
};



//setters for our class dot operator
void Node::SetInitials(string CountryInitials)
{
    Initials = CountryInitials;
}

void Node::SetCountryName(string name)
{
    CountryName = name;
}

//getter functions for our nodes dot operator
string Node::GetCountryName()
{
    return CountryName;
}
string Node::GetInitials()
{
    return Initials;
}

//function prototypes to read from InFile
void openFiles(ifstream& InFile, ofstream& OutFile);

int main()
{
    ifstream InFile;
    ofstream OutFile;
    openFiles(InFile, OutFile);// prompt for input output

    //initialize variables 

    int NumNodes;// second line that reads in node numbers
    int SIZE;
    string line, GraphType = "";
    //sting color for node color and shape string, list is the
    //whole line of strings that read in the whole line

    //Node myNodes; //Object of the class node
    vector<string> myNodes;

    // open input file and output file
    

    //read in the first value string to show which kind of graph

    InFile >> GraphType;// read in the graph type and go to next line
    OutFile << "The GraphType is: " << GraphType <<
        "\n\n";
    InFile >> NumNodes;// read in the next line which is the number of nodes
    SIZE = NumNodes;
    //this is what we will read until

    while (!InFile.eof())
    {//until eof() is encountered
        for (int i = 0; i < NumNodes;i++)

        {
            while (getline(InFile, line))     //create a loop to loop through
            {   //all instances and nodes

                istringstream ss(line);// string streaming from infile

                //variables initializes to read from file
                string Initials, Name;

                //string streaming for each line
                ss >> Initials >> Name;
                myNodes.push_back(line);
            }



        }
    }

InFile.close();
OutFile.close();
return 0;

}

//#####################################################//
//f(x) name                                            // 
//  void openFiles(ifstream& InFile, ofstream& OutFile)//
//                                                     //
//what it does?                                        //
// -> purpose is to user input in and outfile          //
//                                                     //
//paramters                                            //
// -> utilizes the ofstream and outfile                //
//                                                     //
// return type                                         //
// -> no return type because  void                     //
//#####################################################//

void openFiles(ifstream& InFile, ofstream& OutFile)
{
    // Declare variable for the Files. 
    char InFileName[40];
    char outFileName[40];

    // Prompt the user for InFile name
    cout << "Enter the input file name: ";
    cin >> InFileName;

    // open input file
    InFile.open(InFileName);

    //create failsafe way
    if (InFile.fail()) //close out if the file cannot be opened
    {
        cout << "the input file could not be opened" << endl;
        exit(0);
    }

    // Prompt the user for OutFile name
    cout << "Enter the output file name: ";
    cin >> outFileName;

    // Open outfile.
    OutFile.open(outFileName);
}