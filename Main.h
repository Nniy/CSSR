////////////////////////////////////////////////////////////////////////
//Title:	Main.h
//Author:	Kristina Klinkner
//Date:		March 20, 2002
//Description:	Header file for Main.cpp
//
////////////////////////////////////////////////////////////////////////

#ifndef MAIN_H
#define MAIN_H

#include "Common.h"
#include "AllStates.h"
#include "ParseTree.h"
#include "Hash2.h"
#include "Machine.h"

char const *program = "CSSR";  //program name

void PrintError() {
    std::cerr << program << " usage: " << "alphabet_file " << "data_file "
              << "max_string_length " << "-m (optional multi-line)"
              << " -s (optional sig level)"
              << " -ch (optional use of chi-squared test)"
              << std::endl
              << "See README or http://bactra.org/CSSR/ for more help"
              << std::endl;
    exit(1);
}


void PrintCopyrightInfo() {
    std::cout << program << " version 0.0, Copyright (C) 2002 Kristina Klinkner "
              << std::endl
              << program << " comes with ABSOLUTELY NO WARRANTY.  "
              << "This is free software, and you are welcome "
              << "to redistribute it under certain conditions.  Read accompanying "
              << "file 'COPYING-WARRANTY' for details." << std::endl << std::endl;
}

void CheckArgs(char *argv[], bool &isMulti, bool &isSigLevel,
               double &sigLevel, bool &isChi, int index) {
    if (strcmp(argv[index], "-m") == 0 && isMulti == false)
        isMulti = true;
    else if (strcmp(argv[index], "-s") == 0 && isSigLevel == false) {
        std::cout << "Enter significance level: " << std::endl;
        std::cin >> sigLevel;
        isSigLevel = true;
    } else if (strcmp(argv[index], "-ch") == 0 && isChi == false)
        isChi = true;
    else
        PrintError();

}


void SevenArgs(char *argv[], bool &isMulti, bool &isSigLevel, double &sigLevel,
               bool &isChi) {
    CheckArgs(argv, isMulti, isSigLevel, sigLevel, isChi, 4);
    CheckArgs(argv, isMulti, isSigLevel, sigLevel, isChi, 5);
    CheckArgs(argv, isMulti, isSigLevel, sigLevel, isChi, 6);
}

void SixArgs(char *argv[], bool &isMulti, bool &isSigLevel, double &sigLevel,
             bool &isChi) {
    CheckArgs(argv, isMulti, isSigLevel, sigLevel, isChi, 4);
    CheckArgs(argv, isMulti, isSigLevel, sigLevel, isChi, 5);
}


void FiveArgs(char *argv[], bool &isMulti, bool &isSigLevel, double &sigLevel,
              bool &isChi) {
    CheckArgs(argv, isMulti, isSigLevel, sigLevel, isChi, 4);
}


#endif
