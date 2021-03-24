#include <iostream>
#include<fstream>
#include <map>

using namespace std;

class EDGE;

struct Node
{
  protected:
      string IdentityNum;
      string NameofNode;
      string NodeColor;
      string outlineColor;
  public:
      Node(string identity, string name, string color, string outline)
     {
        IdentityNum = identity;
        NameofNode = name;
        NodeColor = color;
        outlineColor= outline;
      }
  friend EDGE;
  friend ostream& operator<<(ostream& Outfile,Node* other)
    {
        return Outfile << other->IdentityNum << " [NameofNode=" << other->NameofNode << " NodeColor=" << 
                       other->NodeColor<<" OutlineColor=" << other->outlineColor << "]";
    }
};

//
struct EDGE
{
    map<string,string> attributes;
    //structure to create nodes holding id,name, and color
    //map<string, string> attributes;

    Node* Head;
    Node* Tail;
    string pointerstyle;// pointer style

    EDGE(Node* H, Node* T)
    {
        Head = H;//pointer to head
        Tail = T; // pointer to the tail
    }
    //pointerstyle is the pointer
    void setpointerstyle(string s)
    {
        pointerstyle = s;
    }
    // read in the first string num then the value
    void addAttribute(string key, string value)
    {
        // add attributes for an edge
    }
    
    friend ostream& operator<<(ostream& Outfile, const EDGE& other)
    {
        Outfile << other.Head->IdentityNum << "->" << other.Tail->IdentityNum;
        Outfile << "[ pointerstyle=" << other.pointerstyle << "]";
        return Outfile;
    }
    friend ostream& operator<<(ostream& os,const Edge& other)
    {
        os << other.start->id<<"->"<<other.end->id;
        os << "[ arrowhead="<<other.arrowhead<<"]";
        return os;
    }
};


int main()
{
     ofstream Outfile;
     Outfile.open("output.txt");
    //below is a list of nodes that created to 
    // show a linked list variety used
    //in our Graphviz class to get visual

    //creating instances of each and then overwrite the default constructor
    Node* NODE1 = new Node("01", "Home", "green", "dotted");
    Node* NODE2 = new Node("02", "School", "blue", "solid");
    Node* NODE3 = new Node("03", "Food", "yellow", " solid");
    Node* NODE4 = new Node("04", "Grocery Store", "Pink", "dotted");
    Node* NODE5 = new Node("05", "Gym", "magenta","dotted");
    Node* NODE6 = new Node("06", "Work", "green","dotted");
    Node* NODE7 = new Node("07", "FriendsHouse", "blue","dotted");
    Node* NODE8 = new Node("08", "WorkLocatioNODE2", "yellow","dotted");
    Node* NODE9 = new Node("09", "DogPark", "purple","dotted");
    Node* NODE10 = new Node("10", "Library", "purple","dotted");


    //creating EDGE to tie our linked list together
    EDGE Node1(NODE1, NODE2);
    //2 points to 3 and so on
    EDGE Node2(NODE2, NODE3);
    EDGE Node3(NODE3, NODE4);
    EDGE Node4(NODE4, NODE5);
    EDGE Node5(NODE5, NODE6);
    EDGE Node6(NODE6, NODE7);
    EDGE Node7(NODE7, NODE8);
    EDGE Node8(NODE8, NODE9);
    EDGE Node9(NODE9, NODE10);

    //wrap all this around back to one

    EDGE Node10(NODE10, NODE1);


    Node1.setpointerstyle("diamond");
    Node2.setpointerstyle("square");
    Node3.setpointerstyle("square");
    Node4.setpointerstyle("circle");
    Node5.setpointerstyle("circle");
    Node6.setpointerstyle("rectangle");
    Node7.setpointerstyle("rectangle");
    Node8.setpointerstyle("circle");
    Node9.setpointerstyle("circle");
    Node10.setpointerstyle("square");

    Outfile << " below are the nodes and attributes" << endl << endl;

    //print out the nodes and attributes
    Outfile << NODE1 << endl;
    Outfile << NODE2 << endl;
    Outfile << NODE3 << endl;
    Outfile << NODE4 << endl;
    Outfile << NODE5 << endl;
    Outfile << NODE6 << endl;
    Outfile << NODE7 << endl;
    Outfile << NODE8 << endl;
    Outfile << NODE9 << endl;
    Outfile << NODE10 << endl;


    Outfile << " below are the linked list" << endl << endl;

    //display the nodes and what they point to
    Outfile << Node1 << endl;
    Outfile << Node2 << endl;
    Outfile << Node3 << endl;
    Outfile << Node4 << endl;
    Outfile << Node5 << endl;
    Outfile << Node6 << endl;
    Outfile << Node7 << endl;
    Outfile << Node8 << endl;
    Outfile << Node9 << endl;
    Outfile << Node10 << endl;
return 0;
}