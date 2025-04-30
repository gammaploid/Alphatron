

#include "Alphatron.h"

#include <iostream>
#include <iomanip>
using namespace std;

void Alphatron::memory_dump() {
    char prev = std::cout.fill('0');
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 9; col++) {
            std::cout << std::setw(4) << memory[10 * row + col] << " ";
        }
        std::cout << std::setw(4) << memory[10 * row + 9] << std::endl;
    }
    std::cout.fill(prev);
}


void Alphatron::read_program() {
    for (int i = 0; i < 100; i++) memory[i]=0;

    std::string line;
    int memcounter = 1;
    while (std::getline(std::cin, line) && line.find("RUN") != 0) {
        int command = std::stoi(line);
        memory[memcounter++] = command;
    }
    //memory_dump();
}

void Alphatron::run_program() {
    program_counter = 1;
    accumulator = 0;
    while (true) {

        int instruction = memory[program_counter];
        int opcode = instruction / 100;
        int operand = instruction % 100;

        switch (opcode) {
            case INPUT: {
                int value;
                cin >> value;
                if (operand == 0) {
                    accumulator = value;
                } else {
                    memory[operand] = value;
                }
                break;
            }
            case OUTPUT: {
                if (operand == 0) {
                    cout << accumulator << endl;
                } else {
                    cout << memory[operand] << endl;
                }
                break;
            }
            case INC: {
                accumulator++;
                break;
            }
            case HALT: {
                return;
            }
            case DEC: {
                accumulator--;
                break;
            }
            case ADD: {
                accumulator += memory[operand];
                break;
            }
            case SUB: {
                accumulator -= memory[operand];
                break;
            }
            case LOAD: {
                accumulator = memory[operand];
                break;
            }
            case STORE: {
                  memory[operand] = accumulator;
                break;
            }
            case JUMP: {
                program_counter = operand;
                continue;
            }
            case JUMPPOS: {
                if (accumulator > 0) {
                    program_counter = operand;
               continue;
                }
                break;
            }
            case JUMPZERO: {
                if (accumulator == 0) {
                    program_counter = operand;
                    continue;
                }
                break;
            }
            case SKIP: {
                break;
            }

            default: {
                cerr << "Invalid opcode: " << opcode << endl;
                return;
            }

        }

        program_counter++;
    }
}