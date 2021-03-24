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

public:
    Node() {};// default constructor
    //overloaded default method for our node
    Node(string NodeNum, string name, string fillcolor, string edge, string outline, string EdgeCol)
    {
        //basic node has these attributes
        NodeNumber = NodeNum;// read in the node number
        Name = name;
        FillColor = fillcolor;
        EdgeStyle = edge;
        OutlineColor = outline;
        EdgeColor = EdgeCol;
    }

    //setters for out attributes
    void SetNodeNumber(string);//node number read in
    void SetEdgeStyle(string); // style for the edge
    void SetOutlineColor(string); //style for outline
    void SetFillColor(string);// node fill setter
    void SetName(string);// name of the node
    void SetEdgeColor(string); // color for our edges

    //getters for our attributes
    string getNodeNumber();
    string getEdgeStyle();
    string getOutlineColor();
    string getFillColor();
    string getName();// get the name
    string getEdgeColor();//get edge color

    //operator outfile overloading to print how we want
    friend ostream& operator<<(ostream& OutFile, Node& other);

    ~Node()
    {
        cout << " node has been destoyed" << endl;
    };// destructor for our node class
};




//definition for ostream overloading
ostream& operator<<(ostream& OutFile, Node& other)
{

    OutFile << other.id << "[ ";

    for (other.node = other.styles.begin(); other.node != other.styles.end(); ++other.node)
    {
        return OutFile << other.node->first << "=" << other.node->second << ", " << "]";

    }
};


//setters for our class

void Node::SetNodeNumber(string NodeNum)
{
    NodeNumber = NodeNum;//name of the node
}
void Node::SetName(string name)
{
    Name = name;//name of the node
}
void Node::SetEdgeStyle(string edge)
{
    EdgeStyle = edge;//assign edge to edgestyle
}
//set the outline color attribute
void Node::SetOutlineColor(string color)
{
    OutlineColor = color;//assign outline color
}
//set the fill attribute
void Node::SetFillColor(string Fill)
{
    FillColor = Fill;//assign the fill color
}
void Node::SetEdgeColor(string EdgeCol)
{
    EdgeColor = EdgeCol;
}

//getters to obtain the attribute names

string Node::getNodeNumber()
{
    return NodeNumber;
}

string Node::getName()
{
    return Name;
}
string Node::getOutlineColor()
{
    return OutlineColor;// return the string color
}

string Node::getEdgeStyle()
{
    return EdgeStyle;//return the edge style
}
string Node::getFillColor()
{
    return FillColor; // return the fill color attribute
}
string Node::getEdgeColor()
{
    return EdgeColor; // return the fill color attribute
}



//function prototypes to read from InFile
void openFiles(ifstream& InFile, ofstream& OutFile);

//function prototype to read a line list array from infile
int InputData(ifstream& InFile, string[]);


int main()
{
    
    int id;
    string length;
    string color, shape, GraphType = "", list[100];
    //sting color for node color and shape string, list is the
    //whole line of strings that read in the whole line

    Node* NEWNODE;// pointer to a new node
    vector<Node*> nodes;

    // open input file and output file
    ifstream InFile;
    ofstream OutFile;
    openFiles(InFile, OutFile);// prompt for input output

    //read in the first value string to show which kind of graph

    InFile >> GraphType;// read in the graph type and go to next line
    OutFile << "The GraphType is: " << GraphType <<
        "\n\n";

    while (!InFile.eof())
    {//until eof() is encountered
        for (int i = 0; i < GraphType;i++)
        {
            length = InputData(InFile, list); // read the list and
            InFile >> id;
            NEWNODE = new Node(to_string(id));

            InFile >> color;
            InFile >> shape;

            NEWNODE->addStyle("color", Color);
            NEWNODE->addStyle("shape", shape);
            NEWNODE->addEdgeColor("EdgeColor", EdgeColor);
                NEWNODE.setOutlineColor();

            nodes.push_back(NEWNODE);

        }
        for (int i = 0;i < nodes.size();i++)
        {
            OutFile << *nodes[i] << endl;
            //output all of the nodes and attributes
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

//###########################################//
// function name
//  ->int InputData(ifstream& InFile, int list[])
//
//parameters
//  -> accets the InFile that is opened in the InFile
//  -> search function, and accepts the integer array
//  -> list that is set to max 100
//
//what it does
//-> the purpose of this function is to read from the InFile
//-> and read the string of integers on each line and store it 
//-> in an array that makes it easier to compute the GCD and LCM
//
//return type
//-> returns the integer size of each individual line to be used in
//-> computational processing in the other functions
//################################################################//

int InputData(ifstream& InFile, string list[])
{
    string line;
    getline(InFile, line); // read a line from file
    if (line == "") // read line is empty, read another line
        getline(InFile, line);
    int SIZE = 0; // initialize SIZE of list to 0

    istringstream is(line);
    // loop over the line reading integers into array
    //list and computing the length of the list
    while (is >> list[SIZE])
        SIZE++;
    return SIZE;
}