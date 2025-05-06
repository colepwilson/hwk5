#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          Level 1 difficulty: assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori, slti
//          c) has only registers $t0 thru $t7 or $s0 thru $s7 in the instruction
//
string disassemble( string hex ) {
    /*
        I-type instruction: opcode, rs, rt, immediate --> 6, 5, 5, and 16 bits, respectively
        
        Registers:
            $t0-$t7 --> 8-15
            $s0-$s7 --> 16-23
    */

    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the different parts of the hex instruction!
    //
    // YOUR CODE GOES HERE!!

    const int RANGE = 8;
    int t_regs[RANGE] = {8, 9, 10, 11, 12, 13, 14, 15};     // $t0-$t9 decimal values
    int s_regs[RANGE] = {16, 17, 18, 19, 20, 21, 22, 23};    // $s0-$s9 decimal values

    const int SIZE = 5;
    int opcodes[SIZE] = {8, 9, 12, 13, 10};                 // addi, addiu, andi, ori, slti opcodes in decimal

    const int VALS = 16;
    string binVals[VALS] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    string binary = "";
    for (char c : hex) {
        switch (c) {
            case '0':
                binary += binVals[0];
                break;
            case '1':
                binary += binVals[1];
                break;
            case '2':
                binary += binVals[2];
                break;
            case '3':
                binary += binVals[3];
                break;
            case '4':
                binary += binVals[4];
                break;
            case '5':
                binary += binVals[5];
                break;
            case '6':
                binary += binVals[6];
                break;
            case '7':
                binary += binVals[7];
                break;
            case '8':
                binary += binVals[8];
                break;
            case '9':
                binary += binVals[9];
                break;
            case 'A':
                binary += binVals[10];
                break;
            case 'B':
                binary += binVals[11];
                break;
            case 'C':
                binary += binVals[12];
                break;
            case 'D':
                binary += binVals[13];
                break;
            case 'E':
                binary += binVals[14];
                break;
            default:
                binary += binVals[15];
                break;
        }

    }


    string opcode = binary.substr(0, 6);
    string rs = binary.substr(6, 11);
    string rt = binary.substr(11, 16);
    string imm = binary.substr(16, 31);
 
    return binary;  // remove stub and replace it with correct variable
}

int main() {
// Don't change any code in main() function!!

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
