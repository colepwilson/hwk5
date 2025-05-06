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

    const int RANGE = 16;
    string regs[RANGE] = {"01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111"};     // $t0-$t9 and $s0-$s7 5-bit binary values
    // int s_regs[RANGE] = {16, 17, 18, 19, 20, 21, 22, 23};    // $s0-$s9 decimal values

    const int SIZE = 5;
    string opcodes[SIZE] = {"001000", "001001", "001100", "001101", "001010"};                 // addi, addiu, andi, ori, slti opcodes in 6-bit binary

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
    string rs = binary.substr(6, 5);
    string rt = binary.substr(11, 5);
    string imm = binary.substr(16, 16);

    string result = ""; // want opcode rt, rs, imm

    if (opcode == opcodes[0]) {
        result += "addi ";
    } else if (opcode == opcodes[1]) {
        result += "addiu ";
    } else if (opcode == opcodes[1]) {
        result += "andi ";
    } else if (opcode == opcodes[1]) {
        result += "ori ";
    } else {
        result += "slti ";
    }

    if (rt == regs[0]) {
        result += "$t0, ";
    } else if (rt == regs[1]) {
        result += "$t1, ";
    } else if (rt == regs[2]) {
        result += "$t2, ";
    } else if (rt == regs[3]) {
        result += "$t3, ";
    } else if (rt == regs[4]) {
        result += "$t4, ";
    } else if (rt == regs[5]) {
        result += "$t5, ";
    } else if (rt == regs[6]) {
        result += "$t6, ";
    } else if (rt == regs[7]) {
        result += "$t7, ";
    } else if (rt == regs[8]) {
        result += "$s0, ";
    } else if (rt == regs[9]) {
        result += "$s1, ";
    } else if (rt == regs[10]) {
        result += "$s2, ";
    } else if (rt == regs[11]) {
        result += "$s3, ";
    } else if (rt == regs[12]) {
        result += "$s4, ";
    } else if (rt == regs[13]) {
        result += "$s5, ";
    } else if (rt == regs[14]) {
        result += "$s6, ";
    } else {
        result += "$s7, ";
    }

    if (rs == regs[0]) {
        result += "$t0, ";
    } else if (rs == regs[1]) {
        result += "$t1, ";
    } else if (rs == regs[2]) {
        result += "$t2, ";
    } else if (rs == regs[3]) {
        result += "$t3, ";
    } else if (rs == regs[4]) {
        result += "$t4, ";
    } else if (rs == regs[5]) {
        result += "$t5, ";
    } else if (rs == regs[6]) {
        result += "$t6, ";
    } else if (rs == regs[7]) {
        result += "$t7, ";
    } else if (rs == regs[8]) {
        result += "$s0, ";
    } else if (rs == regs[9]) {
        result += "$s1, ";
    } else if (rs == regs[10]) {
        result += "$s2, ";
    } else if (rs == regs[11]) {
        result += "$s3, ";
    } else if (rs == regs[12]) {
        result += "$s4, ";
    } else if (rs == regs[13]) {
        result += "$s5, ";
    } else if (rs == regs[14]) {
        result += "$s6, ";
    } else {
        result += "$s7, ";
    }

    int immediate;

    if (imm[0] == '1') {
        immediate = stoi(imm, nullptr, 2);
        immediate -= (1 << 16);
    } else {
        immediate = stoi(imm, nullptr, 2);
    }

    imm = to_string(immediate);
    result += imm;

    return result;  // remove stub and replace it with correct variable
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
