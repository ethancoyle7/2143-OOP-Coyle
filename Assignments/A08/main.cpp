//**********************************************************
///
//Ethan Coyle
//Assignment 8 create class to combine Colors in Color pall
//Dr. Griffin-OOP 2143
//
//Tuesday/Thursday 9:30A.
//
//Due 3/16/21
//
// thee purpose of this assignment was to create a color 
//pallete to hold our various inputted values for RGB
//and store them inside main we utilize the creation of an
// additional color palette to be store which is user
// inputted and store inside of our vectore called Color
//PalletteMixes.. ideally, we are able to store as many color 
//combinations as we want and furthing this, we also call
//the inputted values to display the created mixture
//
//This program also uses the idea of inheritance in C++ by
//taking on some of the former traits of its
//parent class
//////////////////////////////////////////////////////////////
#include <iostream>
#include < vector>

using namespace std;

// implementation of rgb Color class
// that intialize one instance, or three instance
class RgbColor
{
 private:// private by default
    int RedColor;                    // 0-255 RedColor
    int GreenColor;                  // 0-255 GreenColor
    int BlueColor;                  // 0-255 BlueColor
public: 
    RgbColor();             // def. constructr
    RgbColor(int);          // overloaded 1 Color
    RgbColor(int,int,int);  // overload three Colors
    
    //3 setters for Colors
    void SetRedColor(int);         // set RedColor
    void SetGreenColor(int);         // set GreenColor
    void SetBlueColor(int);         // set BlueColor
   
  // three get functions for Color
  
    int GetRedColor();             // get RedColor
    int GetGreenColor();             //get GreenColor
    int GetBlueColor();             //get BlueColor

    void GrayScale();       // averages  of the Colors
    void AddColor(RgbColor ColorPalleteMixes);// adding Colors to
    //Colorpallete

    //we create a vecotr now to hold our custom added Colors
    // we need to initialize this so values dont change(static)
    //call the RGbColor class and call it ColorPaletteMix
    static vector <RgbColor> ColorPalleteMix;

    // print to the outstream ostream overloading
    friend ostream& operator<<(ostream&,const RgbColor&);

    // overloaded addition operator
    RgbColor operator+(const RgbColor& );


};


//setters with dot operator
void RgbColor:: SetRedColor(int red)
{
    r = red;
}
void RgbColor::SetGreenColor(int green)
{
    g = green;
}


void RgbColor::SetBlueColor(int blue)
{
    b = blue;
}

//initialize getters

int RgbColor:: GetRedColor()
{
    return r;
}



int RgbColor::GetGreenColor()
{
    return GreenColor;
}

int RgbColor::GetBlueColor()
{
    return BlueColor;
}
//dot operator for rgb color class to hold our mixed colors
//inside of a vectore called colorpallete mixes
// this is so we can store a plethora of different mixes if we
//wanted to
 void RgbColor::AddColor(RgbColor ColorPalleteMixes)
{
	ColorPalleteMix.push_back(ColorPalleteMixes);
}

RgbColor RgbColor::operator+(const RgbColor& other)
{
    //addtion operator overloader
    int RedColor = (this->RedColor + other.RedColor) / 2;
    int GreenColor = (this->GreenColor + other.GreenColor) / 2;
    int BlueColor = (this->BlueColor + other.BlueColor) / 2;

    return *this;//retrun the dereferenced values
}
//this is the default default constructor
RgbColor::RgbColor()
{
    //initialize all to 0
    RedColor = GreenColor = BlueColor = 0;
}
// intialize each to Color
RgbColor::RgbColor(int Color)
{
    RedColor = GreenColor = BlueColor = Color;
}

// assign variable to make new

RgbColor::RgbColor(int r,int g, int b)
{
    //values are store and assigned to respective
    //colors
    RedColor = r;
    GreenColor = g;
    BlueColor = b;
}

//setters with dot operator for grb color class

void RgbColor:: SetRedColor(int red)
{
    RedColor = red;
}
void RgbColor::SetGreenColor(int green)
{
    GreenColor = green;
}

void RgbColor::SetBlueColor(int blue)
{
    BlueColor=blue;
}


//initialize getters for color palatte

int RgbColor:: GetRedColor()
{
    return RedColor;
}

int RgbColor::GetGreenColor()
{
    return GreenColor;
}

int RgbColor::GetBlueColor()
{
    return BlueColor;
}

//overload ostream using friend function
 ostream& operator<<(ostream& outfile,const RgbColor& other)
{
    outfile<<"["<<other.RedColor<<","<<other.GreenColor<<
           ","<<other.BlueColor<<"]";
    return outfile;
    //printing out the value of the other color
}
int main() 
{
 // creating instand of rgbColor class with a combo
 //for Color pallete mixing

//RgbColor FirstColor(255,200,11);  //create instance of c1
//RgbColor SecondColor(100,14,123);// create instance of c2
//RgbColor ThirdColor = FirstColor + SecondColor;

// first color and second color add together
//addition overload assign to c3
//cout<<ThirdColor<<endl;// print out 3rdColor obj

//next we initialize a color palatte to add to a list of color
//mixes





RgbColor ColorMix1, ColorMix2;
//class name rgbColor object name Color mix1 and 2
// initialize all the Colors as integers
int RedColor, GreenColor, BlueColor;

cout << "ether value for red green and blue " << endl;
//user inputs values
cin >> RedColor >> BlueColor >> GreenColor;
//intialize the functions to set the values of each of the

//user inputted values go to the setter functions to set
//these values in

ColorMix1.SetRedColor(RedColor);
ColorMix1.SetGreenColor(GreenColor);
ColorMix1.SetBlueColor(BlueColor);

//now we must utilize the get functions to obtain the stored value
//GETTING RBG COLORS
ColorMix1.GetRedColor();
ColorMix1.GetGreenColor();
ColorMix1.GetBlueColor();
ColorMix1.AddColor(ColorMix1);//adding these to
//instance and colorpallete

    //output the Color mixture

cout<<"our mixture to Color pallete is : "<<
      ColorMix1 <<endl;


    // creating another mixture to our concoction Color pallete

cout << "Enter the Colors for another Color pallete mixture "
         <<" in the form Red, Green and then Blue"<<"\n\n";
    //user inputted integers
cin >> RedColor >> BlueColor >> GreenColor;

    //call setter functions to set newvalues

ColorMix2.SetRedColor(RedColor);//set redColor
ColorMix2.SetGreenColor(GreenColor);//setgreenColor
ColorMix2.SetBlueColor(BlueColor);//setblueColor

    //call getter functions to obtain the Colors

    //utilize the class rgb Color to obtain the getters
    //getting RBG COLORS
ColorMix2.GetRedColor();//get new red
ColorMix2.GetGreenColor();//get new green
ColorMix2.GetBlueColor();// get new blue
ColorMix2.AddColor(ColorMix2);// add this Color mix to stored
                                  // data values

cout<< "New Color Mixture is : " << ColorMix2 << "\n\n";
    // output the nex wolor mixture

//after this is we want to add more we can as well it dont matter

return 0;
//ending  the program
}
